#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>

#include <utils.h>
#include "api.h"


int sfd = -1; 

long timespecdifference(struct timespec start, struct timespec end, struct timespec goal){
    int diffsec = end.tv_sec - start.tv_sec;
    long diffnsec = end.tv_nsec - start.tv_nsec;


    if( (diffsec > goal.tv_sec) ){
        return 1;
    }    
    else if( diffsec==goal.tv_sec ){
            if(diffnsec >= goal.tv_nsec)
                return 1;
    }

    return 0;
}

int get_ms(struct timespec ts){
    int ms=0;

    ms = ((ts.tv_sec * 1000)) + ((ts.tv_nsec) / 1000000);
    //printf("%lld.%.9ld", (long long)ts.tv_sec, ts.tv_nsec);


    return ms;
}





int openConnection(const char* sockname, int msec, const struct timespec abstime) {
    if(sfd != -1){
        errno = EISCONN;
        return -1;
    }
    
    int unused;
    SYSCALL(sfd,socket(AF_UNIX, SOCK_STREAM, 0),"Error creating socket",errno);
    printf("sfd dopo socket: %d\n",sfd);
    
    struct sockaddr_un serv_addr;
    printf("sockname api:%s\n",sockname);
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strncpy(serv_addr.sun_path, mysock, strlen(mysock)+1);

    //tempo tra un tentarivo e l'altro nel caso in cui il server non accetta la connessione
    struct timespec start, end;
    struct timespec t;
    t.tv_sec = (int)msec/1000;
    t.tv_nsec = (msec%1000)*1000000;
    int remaining = get_ms(abstime);
    //printf("remaining :%d\n",remaining);    
    SYSCALL(unused,clock_gettime(CLOCK_MONOTONIC, &start),"getting start time",errno);
    int msstart = get_ms(start);
    if(remaining < 0 || msstart < 0){
        errno = EINVAL;
        return -1;
    }

    int tmp;

    while( (tmp = connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))) == -1  && remaining > 0 ){
        printf("CLIENT: impossibile connettersi attraverso il socket %s\n il socket mysock è %s\n",sockname, mysock);
        
        SYSCALL(unused,clock_gettime(CLOCK_MONOTONIC, &end),"getting current time",errno);

        int msend = get_ms(end);
        if(msend < 0){
            errno = EINVAL;
            return -1;
        }

        remaining -= msend - msstart;


        
        SYSCALL(unused,nanosleep(&t,NULL),"nanosleep",errno); 
    }

    // if( (remaining <= 0) ){
    //     printf("CLIENT: Connessione fallita\n");
    //     return -1;
    // }

    
    // printf("CLIENT: connessione con il server stabilita\n");

    // // init_socket(sfd,sockname);
    // mysock = sockname;
    // return 0;
    
    printf("tmp : %d\n",tmp);
    return tmp;
}    



int closeConnection(const char* sockname){
    NULL_CHECK(sockname,EINVAL);
    int err;

    if( strcmp(mysock,sockname)!=0 ){ //client non connesso;
        errno = ENOTCONN;
        return -1;   
    }

    // if( (close(sfd)) == -1 ){
    //     perror("chiusura socket");
    //     return -1;
    // }
    
    SYSCALL(err,close(sfd),"closeConnection",errno);

    sfd = -1; //reset del socket una volta disconnesso



    return 0;
}




int openFile(const char* pathname, int flags){
    NULL_CHECK(pathname,EINVAL);

    if(sfd == -1){
        errno = ENOTCONN;
        return -1;
    }

    

    return 0;
}
