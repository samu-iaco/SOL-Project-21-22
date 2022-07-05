#include <stdio.h>
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

#define SOCKNAME "./mysock"

int main(int argc, char *argv[])
{
    struct sockaddr_un serv_addr; /* ind AF_UNIX */
    strcpy(serv_addr.sun_path, SOCKNAME);
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;

    int sfd;
    SYSCALL(sfd,socket(AF_UNIX,SOCK_STREAM,0),"Error opening client socket");

    printf("in attesa del server...\n");
    return 0;
}
