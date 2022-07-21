#include <serverapi.h>

int openfile(int fd){
{
    int err;
    int len_name;

    char* pathname;

    int flags;

    if( (err = readn(fd, &len_name, sizeof(int))) == -1)
    {
        perror("readn lunghezza nome file");
        return -1;
    }

    printf("len file. %d\n", len_name);

    pathname = malloc(sizeof(char) * len_name);
    if(pathname == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("ciao\n");
    if( (err = readn(fd, (void*)pathname, len_name)) == -1)
    {
        perror("readn nome file");
        return -1;
    }

    if(err == 0){
        printf("pathname non valido\n");
        return -1;
    }
    printf("nomefile: %s\n",pathname);
    

    // if( (err = readn(fd, &flags, sizeof(int))) == -1)
    // {
    //     perror("readn flags");
    //     return -1;
    // }

    // printf("flags: %d\n", flags);

    return 0;
}
}