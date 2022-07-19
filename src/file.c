#include <files.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <limits.h>

#include <utils.h>



file *init_file(const char *pathname, off_t size)
{
    file *tmp;
    printf("pathname passato a init file:%s\n ",pathname);
    tmp = (file *)malloc(sizeof(file));
    if (!tmp)
    {
        perror("malloc storage");
        exit(EXIT_FAILURE);
    }

    char *storedName = (char*) malloc(strlen(pathname) + 1);
    strncpy(storedName, pathname, strlen(pathname) + 1);
    tmp->name = storedName;
    tmp->size = size;
    tmp->used = (time_t) NULL;

    return tmp;
}


off_t fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    fprintf(stderr, "Cannot determine size of %s: %s\n",
            filename, strerror(errno));

    return -1;
}



