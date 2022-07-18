#include <files.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <limits.h>



file *init_file(char *pathname, off_t size)
{
    file *tmp;

    tmp = (file *)malloc(sizeof(file));
    if (!tmp)
    {
        perror("malloc storage");
        exit(EXIT_FAILURE);
    }
    tmp->name = pathname;
    tmp->size = size;
    tmp->used = (time_t) NULL;

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


char* app_path(char* path, const char* filename){
    char buf[PATH_MAX];
    //char res[PATH_MAX+1];
    
    if (filename[0] == '/') {    // run with absolute path
        strcpy(buf, filename);
    } else {    // run with relative path
        if(NULL == getcwd(buf, PATH_MAX)) {
            perror("getcwd error");
            return NULL;
        }
        strcat(buf, "/");
        strcat(buf, filename);
        printf("buf now: %s\n" , buf);
        
    }
    if (NULL == realpath(buf, path)) {
        perror("realpath error");
        return NULL;
    }
    return path;
}
