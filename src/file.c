#include <files.h>
#include <stdlib.h>

file *init_file()
{
    file *tmp;

    tmp = (file *)malloc(sizeof(file));
    if (!tmp)
    {
        perror("malloc storage");
        exit(EXIT_FAILURE);
    }
    tmp->name = NULL;
    tmp->size = 0;
    tmp->used = NULL;

    return tmp;
}

file* create_file(char *pathname, size_t size){
    file *tmp;

    if(tmp == NULL){
        perror("file non ancora allocato");
        exit(EXIT_FAILURE);
    }

    tmp->name = pathname;
    tmp->size = size;
    tmp->used = NULL;

    return tmp;

}
