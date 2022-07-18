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

//file* create_file(char *pathname, size_t size);

char* app_path(char* path, const char* filename);

off_t fsize(const char *filename);




#endif