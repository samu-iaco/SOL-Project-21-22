#define _POSIX_C_SOURCE 200809L

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

int openConnection(const char* sockname, int msec, const struct timespec abstime) {
    struct sockaddr_un serv_addr; /* ind AF_UNIX */
    strcpy(serv_addr.sun_path, SOCKNAME);
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;

    printf("dai grande qui ci arrivi\n");


    return 0;

}    