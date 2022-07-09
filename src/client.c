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

    node *queue = init_queue(); //coda richieste
    //int res = parse

    //passo questa coda a una funzione che parsa le richieste
    if( parsing(argc,argv,queue) == -1 ){
        perror("parsing");
        exit(errno);
    }



 

    return 0;
}
