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

char *mysock;
int alreadyconnected = 0;

int parsing(int argc, char *argv[], requestList *queue)
{
    int cmd = 0;

    while ((cmd = getopt(argc, argv, "h:f:w:W:d:D:r:R:t:l:u:c:p")) != -1)
    {
        switch (cmd)
        {
        case 'f':
            if(alreadyconnected){
                printf("il client è gia connesso\n");
                exit(EXIT_FAILURE);
            }
            else{
                mysock = alloc_strings(strlen(optarg));
                strcpy(mysock, optarg);
                alreadyconnected = 1;
            }
            
            
            break;
        }
    }

    printf("mysock: %s\n" , mysock);

    return 0;
}