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

#define SOCKNAME "./mysock"

int main(int argc, char *argv[])
{
    int err;
    char *buf;
    printf("ok\n");
    SYSCALL(err,write(1,&buf,2),"errore write");
    printf("in attesa del server...\n");
    return 0;
}
