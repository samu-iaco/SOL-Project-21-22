#ifndef STORAGELIST_H_
#define STORAGELIST_H_

#include <stdio.h>
#include <files.h>

typedef struct _storage
{
    file f;
    _storage *next;
    size_t dimCache;
}storage;


storage init_storage();


#endif