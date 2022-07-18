#ifndef STORAGELIST_H_
#define STORAGELIST_H_

#include <stdio.h>
#include <files.h>

typedef struct _storage
{
    file f;
    size_t dimStorage;
    struct _storage *next;

}storage;


storage* init_storage();

void addfileTail(storage **currStorage, file currFile);

size_t dim_storage(storage *currStorage);


#endif