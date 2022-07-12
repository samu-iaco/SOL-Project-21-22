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

#define UNIX_PATH_MAX 108
#define N 1024

int main(int argc, char *argv[])
{
    int sfd, /* socket di connessione */
        sfd_c, /* socket di I/O con un client */
        fd_num=0, /* max fd attivo */
        fd; /* indice per verificare risultati select */
    char buf[N]; /* buffer messaggio */
    fd_set set, /* l’insieme  dei file descriptor attivi */
        rdset; /* insieme fd attesi in lettura */
    int nread; /* numero caratteri letti */

    //Creo il socket
	SYSCALL(sfd, socket(AF_UNIX, SOCK_STREAM, 0), "Server - Error creating socket",errno);

    //Setto l'indirizzo
	struct sockaddr_un serv_addr;
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sun_family=AF_UNIX;
	strncpy(serv_addr.sun_path, SOCKNAME, strlen(SOCKNAME)+1);


    return 0;
}
