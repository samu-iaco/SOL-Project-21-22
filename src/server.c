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

#define UNIX_PATH_MAX 108
#define N 1024

int main(int argc, char *argv[])
{
    // int sfd, /* socket di connessione */
    //     sfd_c, /* socket di I/O con un client */
    //     fd_num=0, /* max fd attivo */
    //     fd; /* indice per verificare risultati select */
    // char buf[N]; /* buffer messaggio */
    // fd_set set, /* l’insieme  dei file descriptor attivi */
    //     rdset; /* insieme fd attesi in lettura */
    // int nread; /* numero caratteri letti */

    // //Creo il socket
    // SYSCALL(sfd, socket(AF_UNIX, SOCK_STREAM, 0), "Server - Error creating socket",errno);

    // //Setto l'indirizzo
    // struct sockaddr_un serv_addr;
    // memset(&serv_addr, '0', sizeof(serv_addr));
    // serv_addr.sun_family=AF_UNIX;
    // strncpy(serv_addr.sun_path, SOCKNAME, strlen(SOCKNAME)+1);
    if(argc <= 1){
        printf("Passare come primo parametro il percorso del file di configurazione\n");
        exit(EXIT_FAILURE);
    }

    char* path_to_conf = argv[1];

    sample_parameters parms;
    printf("Initializing parameters to default values...\n");
    init_parameters(&parms);

    printf("Reading config file...\n");
    parse_config_file(&parms,argv[1]);

    printf("Final values:\n");
    printf("  sockname: %s\n",
           parms.sockname);

    return 0;
}
