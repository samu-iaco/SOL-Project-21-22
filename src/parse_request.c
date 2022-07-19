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
    char *saveptr1, *saveptr2;

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
            char* numfile;

            char* test = optarg;
            printf("optarg w: %s\n", test);

            while(numfile != NULL){
                
                dir = strtok_r(optarg, ",", &saveptr1);
                if(dir == NULL){
                    printf("errore nel comando -w: impossibile ottenere nome della cartella\n");
                    return -1;
                }
                printf("dir: %s\n", dir);
                numfile = strtok_r(NULL,",",&saveptr1);

                printf("numfile: %s\n", numfile);
                if(numfile == NULL)
                    break;

            }


            // abspath = app_path(path,dir);
            // if(abspath == NULL){
            //     //perror("errore ottenimento path assoluto cartella");
            //     return -1;
            // }
            // printf("abs path of dir %s: %s\n", dir, abspath);

            // numfile = strtok_r(optarg, " ", &saveptr2);
            // printf("numero di file da inviare al server: %s\n" , numfile);



            break;
        }
        }
    }

    return 0;
}