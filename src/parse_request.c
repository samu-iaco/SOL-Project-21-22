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
#include <dirent.h>

#include <api.h>
#include <utils.h>
#include <files.h>

char const *mysock;
int alreadyconnected = 0;

long isNumber(const char *s)
{
    char *e = NULL;
    long val = strtol(s, &e, 0);
    if (e != NULL && *e == (char)0)
        return val;
    return -1;
}

int recursive_dir_search(char *directory)
{
    DIR *dir;
    // struct per ricerca directory
    struct dirent *entry;
    struct stat filestat;
    char path[PATH_MAX];
    char *pathfile;

    int checkclosedir;

    if ((dir = opendir(directory)) == NULL)
    {
        perror("opendir");
        return -1;
    }

    printf("Directory: %s\n", directory);

    while ((entry = readdir(dir)))
    {
        char fullname[FILENAME_MAX];
        sprintf(fullname, "%s/%s", directory, entry->d_name);

        if ((stat(fullname, &filestat)) == -1)
        {
            perror("stat");
            return -1;
        }

        if (S_ISDIR(filestat.st_mode))
        {
            // printf("%4s: %s\n", "Dir", fullname);

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                // printf("Directory: %s\n" , entry->d_name);
                // printf("\n*Entering a subDirectory*\n");
                recursive_dir_search(fullname);
                // printf("\n*Leaving a subDirectory*\n");
            }
        }
        else
        {
            printf("\t%s\t", entry->d_name); // nome file
            pathfile = app_path(path, fullname);
            if (pathfile == NULL)
            {
                printf("errore su percorso assoluto del file %s\n", fullname);
                return -1;
            }
            printf("percorso assoluto file: %s\n", pathfile);

            if ((openFile(pathfile, 2)) == -1)
            {
                perror("parsing openFile");
                return -1;
            }
        }
    }

    checkclosedir = closedir(dir);
    if (checkclosedir == -1)
    {
        perror("close dir");
        return -1;
    }

    return 0;
}

int parsing(int argc, char *argv[], requestList *queue)
{
    int cmd = 0;
    char *saveptr1;

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
                /* timespec per timeout connessione client */
                struct timespec t;
                t.tv_sec = 5;
                t.tv_nsec = 0;
                int err;
                OP_CHECK(err, openConnection(mysock, 1000, t), "open connection", errno);
                printf("err openconnection: %d\n", err);

                printf("CLIENT: connessione stabilita con successo\n");
            }
            break;
        }

        case 'w':
        {
            char *dir; // directory contenente i file da inviare al server
            char *abspath;
            char path[PATH_MAX];
            char *numfile;

            dir = strtok_r(optarg, ",", &saveptr1);
            if (dir == NULL)
            {
                printf("errore nel comando -w: impossibile ottenere nome della cartella\n");
                return -1;
            }
            printf("dir: %s\n", dir);
            numfile = strtok_r(NULL, ",", &saveptr1);
            if (numfile == NULL)
            {
                printf("non è stato passato un numero di file, invio tutti i file dentro la cartella: %s\n", dir);
            }
            else
            {
                if (isNumber(numfile) == -1)
                {
                    printf("il numero di file da passare al server deve essere un numero\n");
                    return -1;
                }
            }

            abspath = app_path(path, dir);
            if (abspath == NULL)
            {
                // perror("errore ottenimento path assoluto cartella");
                return -1;
            }

            printf("abs path of dir %s: %s\n", dir, abspath);

            printf("numero di file da inviare al server: %s\n", numfile);

            int ressearchdir = recursive_dir_search(abspath);

            if (ressearchdir == -1)
            {
                return -1;
            }

            break;
        }
        }
    }

    return 0;
}