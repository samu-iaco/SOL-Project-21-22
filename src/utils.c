#include <utils.h>


char* alloc_strings(size_t dim){
    char *res = malloc(sizeof(char *) * dim);

    if(res == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return res;
}


