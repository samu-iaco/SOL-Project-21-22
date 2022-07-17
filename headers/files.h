#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>
#include <time.h>

typedef struct _file
{
    char* name;
    size_t size;
    time_t used;
    //tempo nella cache
}file;

file* init_file();

file* create_file(char *pathname, size_t size);




#endif