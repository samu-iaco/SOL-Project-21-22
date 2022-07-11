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

int parsing(int argc, char *argv[], node *queue)
{
    int cmd = 0;

    while ((cmd = getopt(argc, argv, "h:f:w:W:d:D:r:R:t:l:u:c:p")) != -1)
    {
        switch (cmd)
        {
        case 'f':

            mysock = alloc_strings(strlen(optarg));
            strcpy(mysock, optarg);
            
            break;
        }
    }

    printf("mysock: %s\n" , mysock);

    return 0;
}