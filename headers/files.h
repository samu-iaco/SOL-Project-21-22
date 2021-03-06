#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

typedef struct _file
{
    char* name;
    off_t size;
    time_t used;
    //tempo nella cache
}file;

file* init_file(char const *pathname, off_t size);


off_t fsize(const char *filename);




#endif