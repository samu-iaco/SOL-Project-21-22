#include <storagelist.h>
#include <stdlib.h>
#include <utils.h>

storage *init_storage()
{
    storage *list;
    list = malloc(sizeof(storage));
    if (list == NULL)
    {
        perror("malloc storage");
        exit(EXIT_FAILURE);
    }
    list->dimCache = 0;
    list->next = NULL;

    return list;
}

size_t dim_storage(storage *currStorage)
{
    if (currStorage == NULL)
    {
        perror("inizializzazione storage");
        fprintf(stderr, "errore inizializzazione storage: %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t dim = 0;

    storage *tmp = currStorage;
    

    while(tmp != NULL){
        dim += tmp->f.size;
        tmp = tmp->next;
    }

    return dim;
}