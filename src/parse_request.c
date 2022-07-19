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
#include <files.h>

char const *mysock;
int alreadyconnected = 0;

int parsing(int argc, char *argv[], requestList *queue)
{
    int cmd = 0;
    char *saveptr;

    while ((cmd = getopt(argc, argv, "h:f:w:W:d:D:r:R:t:l:u:c:p")) != -1)
    {
        switch (cmd)
        {
        case 'f':
        {
            if (alreadyconnected)
            {
                printf("il client è gia connesso\n");
                return -1;
            }
            else
            {
                mysock = alloc_strings(strlen(optarg));
                mysock = optarg;
                alreadyconnected = 1;
            }
            break;
        }

        case 'w':
        {
            char* dir; // directory contenente i file da inviare al server
            char* abspath;
            char  path[PATH_MAX];
            // getting directory name
            dir = strtok_r(optarg, ",", &saveptr);
            if (dir == NULL)
            {
                fprintf(stderr, "Error in parsing option -w: couldn't read directory name.\n");
                return -1;
            }
            printf("dir: %s\n",dir);
            abspath = app_path(path,dir);

            printf("abs path of dir: %s: %s\n", dir, abspath);

            break;
        }
        }
    }

    return 0;
}