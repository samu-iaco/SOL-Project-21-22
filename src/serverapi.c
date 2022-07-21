#include <serverapi.h>

int openfile(int fd){
{
    int err;
    int len_name;

    char *pathname;

    int flags;

    if( (err = readn(fd, &len_name, sizeof(int))) == -1)
    {
        perror("readn lunghezza nome file");
        return -1;
    }

    printf("len file. %d\n", len_name);

    pathname = malloc(sizeof(char) * (len_name + 1));

    if( (err = readn(fd, &pathname, len_name+1)) == -1)
    {
        perror("readn nome file");
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