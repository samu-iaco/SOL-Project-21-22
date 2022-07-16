#include <storagelist.h>
#include <stdlib.h>

storage* init_storage(){
    storage *list;
    list = malloc(sizeof(storage));
    if(!list){
        perror("malloc storage");
        exit(EXIT_FAILURE);
    }
    list->dimCache = 0;
    list->next = NULL;

    return list;
}