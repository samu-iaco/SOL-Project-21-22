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
#include <queue.h>

#define SOCKNAME "./mysock"

int main(int argc, char *argv[])
{

    if(argc == 1){
        printf("Specificare almeno un argomento. Usa il comando -h per ottenere aiuto\n");
        exit(EXIT_FAILURE);
    }

    node *queue = init_queue(); //coda richieste


    int cmd = 0;

    while ((cmd = getopt(argc, argv, "h:f:w:W:d:D:r:R:t:l:u:c:p")) != -1)
    {
        switch (cmd)
        {
            case 'f':
            
                mysock = alloc_strings(strlen(optarg));
                strcpy(mysock,optarg);
                //free(mysock);
            break;
        }
    }


 

    return 0;
}
