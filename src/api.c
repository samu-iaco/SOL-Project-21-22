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
#include <connection.h>


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

int init_socket(int fd, char* sockname){
    mySocket clientsock;

    NULL_CHECK(sockname,EINVAL);

    clientsock.fd = fd;
    clientsock.socket = sockname;

    return 0;
}



int openConnection(const char* sockname, int msec, const struct timespec abstime) {
    int sfd=0,unused;
    SYSCALL(sfd,socket(AF_UNIX, SOCK_STREAM, 0),"Error creating socket");
    
    struct sockaddr_un serv_addr; /* ind AF_UNIX */
    strcpy(serv_addr.sun_path, sockname);
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    printf("dai grande qui ci arrivi\n");

    //tempo tra un tentarivo e l'altro nel caso in cui il server non accetta la connessione
    struct timespec start, end;
    struct timespec t;
    t.tv_sec = (int)msec/1000;
    t.tv_nsec = (msec%1000)*1000000;
    int remaining = get_ms(abstime);
    //printf("remaining :%d\n",remaining);    
    SYSCALL(unused,clock_gettime(CLOCK_MONOTONIC, &start),"getting start time");
    int msstart = get_ms(start);
    if(remaining < 0 || msstart < 0){
        errno = EINVAL;
        return -1;
    }

    while( (connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr) == -1 ) && remaining > 0) ){
        printf("CLIENT: impossibile connettersi");
        
        SYSCALL(unused,clock_gettime(CLOCK_MONOTONIC, &end),"getting current time");

        int msend = get_ms(end);
        if(msend < 0){
            errno = EINVAL;
            return -1;
        }

        remaining -= msend - msstart;


        
        nanosleep(&t,NULL); 
    }

    if(sfd){
        printf("CLIENT: connessione con il server stabilita\n");

        init_socket(sfd,sockname);

        return sfd;
    }
    


    return -1;

}    



int closeConnection(const char* sockname){
    NULL_CHECK(sockname,EINVAL);

    //implementare il modo di trovare il file descriptor giusto da chiudere 


    return 0;
}