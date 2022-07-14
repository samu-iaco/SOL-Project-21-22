#include <utils.h>

char* alloc_strings(size_t dim){
    char *res = malloc(sizeof(char *) * dim);

    if(res == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return res;
}


char* app_path(char* path, const char* filename){
    char buf[PATH_MAX];
    char * pos;
    if (filename[0] == '/') {    // run with absolute path
        strcpy(buf, filename);
    } else {    // run with relative path
        if(NULL == getcwd(buf, PATH_MAX)) {
            perror("getcwd error");
            return NULL;
        }
        strcat(buf, "/");
        strcat(buf, filename);
    }
    if (NULL == realpath(buf, path)) {
        perror("realpath error");
        return NULL;
    }
    return path;
}