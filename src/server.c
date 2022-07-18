#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <ctype.h>

#include <utils.h>
#include <parse_config.h>
#include <storagelist.h>
#include <files.h>

#define UNIX_PATH_MAX 108
#define N 1024

void cleanup(char *sockname){
    unlink(sockname);
}

int main(int argc, char *argv[])
{
    if(argc <= 1){
        printf("Passare come primo parametro il percorso del file di configurazione\n");
        exit(EXIT_FAILURE);
    }



    // int sfd, /* socket di connessione */
    //     sfd_c, /* socket di I/O con un client */
    //     fd_num=0, /* max fd attivo */
    //     fd; /* indice per verificare risultati select */
    // char buf[N]; /* buffer messaggio */
    // fd_set set, /* l’insieme  dei file descriptor attivi */
    //     rdset; /* insieme fd attesi in lettura */
    // int nread; /* numero caratteri letti */

    /* CONFIGURAZIONE SERVER DA FILE CONFIG */
    sample_parameters parms;
    printf("Initializing parameters to default values...\n");
    init_parameters(&parms);


    printf("Reading config file...\n");
    parse_config_file(&parms,argv[1]);

    cleanup(parms.sockname);
    printf("Final values:\n");
    printf("\tsockname: %s\n\tn.worker: %ld\n\tcapacita server (#file): %ld\n", 
           parms.sockname, parms.nworker, parms.maxfile);


    /* INIZIALIZZAZIONE DELLO STORAGE */
    storage *file_storage = NULL;
    //file_storage = init_storage();
    printf("storage inizializzato\n");
    char currpath[4097];
    char* abspath = app_path(currpath,"./test.txt");
    //printf("il percorso assoluto del file test è: %s\n",abspath);
    off_t filesize = fsize("test.txt");
    //printf("la dimensione del file test è: %ld\n",filesize);

    file* f1 = init_file(abspath,filesize);
    memset(currpath, 0, sizeof(currpath));

    abspath = app_path(currpath,"./poesia.txt");
    //printf("il percorso assoluto del file poesia è: %s\n",abspath);
    filesize = fsize("poesia.txt");
    //printf("la dimensione del file poesia è: %ld\n",filesize);

    file* f2 = init_file(abspath,filesize);


    addfileTail(&file_storage, *f1);
   
    addfileTail(&file_storage, *f2);

    size_t dim = dim_storage(file_storage);
    printf("la dimensione di tutto il file storage è: %ld\n",dim);


    //test = init_file(abspath,filesize);
    //OTTENERE SIZE FILE E PATH ASSOLUTO
    

    // //Creo il socket
    // SYSCALL(sfd, socket(AF_UNIX, SOCK_STREAM, 0), "Server - Error creating socket",errno);

    // //Setto l'indirizzo
    // struct sockaddr_un serv_addr;
    // memset(&serv_addr, '0', sizeof(serv_addr));
    // serv_addr.sun_family=AF_UNIX;
    // strncpy(serv_addr.sun_path, parms.sockname, strlen(parms.sockname)+1);

    //     //Bindo l'indirizzo
	// int unused;
	// SYSCALL(unused, bind(sfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)), "Server - Error binding index",errno);
	
	// //Setta socket in ascolto
	// SYSCALL(unused, listen(sfd, SOMAXCONN), "Server - Error listening socket",errno);

    // printf("SERVER: in attesa di connessioni...\n");

    // if(sfd > fd_num) fd_num = sfd;

    // FD_ZERO(&set);
    // FD_SET(sfd,&set);

    // while (1)
    // {
    //     rdset = set;
    //     if(select(fd_num+1,&rdset,NULL,NULL,NULL) == -1){
    //         perror("select");
    //         exit(EXIT_FAILURE);
    //     }
    //     else{
    //         for(fd=0; fd<=fd_num; fd++){
    //             if(FD_ISSET(fd,&rdset)){
    //                 if(fd == sfd){
    //                     sfd_c = accept(sfd,NULL,0);
    //                     printf("SERVER: connessione con client stabilita!\n");
    //                     FD_SET(sfd_c,&set);
    //                     if(sfd_c > fd_num) fd_num = sfd_c;
    //                 }else{
    //                     // int len,r;
    //                     // char *up;
    //                     // //leggo lunghezza stringa
    //                     // SYSCALL(nread,read(fd,&len,sizeof(int)),"Error reading lenght string from client",errno);
    //                     // if(nread == 0){
    //                     //     printf("niente piu da leggere\n");
    //                     //     FD_CLR(fd,&set);
    //                     //     fd_num = aggiorna(&set,fd_num);
                            
    //                     //     break;
    //                     // }
    //                     // SYSCALL(r,read(fd,buf,len*sizeof(char)),"Error reading string from client",errno);
    //                     // printf("stringa ricevuta: %s\n",buf);
    //                     // fflush(stdout);
    //                     // up = up_string(buf,len);
    //                     // //len = strlen(up);

    //                     // SYSCALL(r,write(fd,&len,sizeof(int)), "Error writing lenght string on client",errno);
    //                     // SYSCALL(r,write(fd,up,len*sizeof(char)), "Error writing string on client",errno);
    //                     //printf("haohaohao\n");


    //                 }
    //             }
                
    //         }
    //         close(fd);
    // }
    

    // }    


    return 0;
}
