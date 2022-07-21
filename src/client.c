#define _POSIX_C_SOURCE 200809L

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

#include <api.h>
#include <utils.h>



int main(int argc, char *argv[])
{

    if(argc == 1){
        printf("Specificare almeno un argomento. Usa il comando -h per ottenere aiuto\n");
        exit(EXIT_FAILURE);
    }

    requestList *queue = init_queue(); //coda richieste
    int err;

    //passo questa coda a una funzione che parsa le richieste
    if( parsing(argc,argv,queue) == -1 ){
        printf("errore parsing comandi\n");
        exit(EXIT_FAILURE);
    }

    /* timespec per timeout connessione client */
    // struct timespec t;
    // t.tv_sec = 5;
    // t.tv_nsec = 0;
    printf("mysock client: %s\n",mysock);
    // if( (openConnection(mysock,1000,t)) == -1 ){
    //     perror("CLIENT: impossibile stabilire connessione con il server");
    //     exit(EXIT_FAILURE);
    // }


    // OP_CHECK(err,openConnection(mysock,1000,t),"open connection",errno);
    // printf("err openconnection: %d\n", err);

    // printf("CLIENT: connessione stabilita con successo\n");

    OP_CHECK(err,closeConnection(mysock),"close connection",errno);

    printf("err closeconnection: %d\n", err);

    printf("CLIENT: connessione terminata con successo\n");

    return 0;
}
