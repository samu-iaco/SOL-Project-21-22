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
    list->dimStorage = 0;
    list->next = NULL;

    return list;
}

void addfileTail(storage **currStorage, file currFile)
{
    // if(*currStorage == NULL){
    //     printf("Impossibile aggiungere file: storage non inizializzato\n");
    //     exit(EXIT_FAILURE);
    // }

    storage *currHead = *currStorage;


    storage *newnode = malloc(sizeof(storage));
    if(newnode == NULL){
        perror("malloc newnode storage");
        exit(EXIT_FAILURE);
    }
    newnode->f = currFile;


    if (currHead == NULL)
    {
        printf("lista vuota all'inizio\n");
        *currStorage = newnode;
    }
    else
    {
        while (currHead->next != NULL)
        {
            currHead = currHead->next;
        }
        currHead->next = newnode;    //LISTA FILE (SERVE CAMPO NEXT??)
    }


}




size_t dim_storage(storage *currStorage)
{
    if (currStorage == NULL)
    {
        perror("inizializzazione storage");
        fprintf(stderr, "errore inizializzazione storage: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t dim = 0;
    file curr;
    storage *tmp = currStorage;

    while (tmp != NULL)
    {   
        curr = tmp->f;
        printf("curr dim: %ld :\n\tnome file: %s\n",curr.size,curr.name);
        dim += curr.size;
        tmp = tmp->next;
        
    }

    return dim;
}