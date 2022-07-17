#ifndef STORAGELIST_H_
#define STORAGELIST_H_

#include <stdio.h>
#include <files.h>

typedef struct _storage
{
    file f;
    size_t dimCache;
    storage *next;

}storage;


storage* init_storage();

size_t dim_storage(storage* currStorage);


#endif