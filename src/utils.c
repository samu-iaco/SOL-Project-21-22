#include <utils.h>
#include <limits.h>
#include <linux/limits.h>
#include <stdlib.h>

#define _POSIX_C_SOURCE 200112L

char* alloc_strings(size_t dim){
    char *res = malloc(sizeof(char *) * dim);

    if(res == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return res;
}


ssize_t  /* Read "n" bytes from a descriptor */
readn(int fd, void *ptr, size_t n) {  
   size_t   nleft;
   ssize_t  nread;
 
   nleft = n;
   while (nleft > 0) {
     if((nread = read(fd, ptr, nleft)) < 0) {
        if (nleft == n) return -1; /* error, return -1 */
        else break; /* error, return amount read so far */
     } else if (nread == 0) break; /* EOF */
     nleft -= nread;
     ptr   += nread;
   }
   return(n - nleft); /* return >= 0 */
}


ssize_t  /* Write "n" bytes to a descriptor */
writen(int fd, void *ptr, size_t n) {  
   size_t   nleft;
   ssize_t  nwritten;
 
   nleft = n;
   while (nleft > 0) {
     if((nwritten = write(fd, ptr, nleft)) < 0) {
        if (nleft == n) return -1; /* error, return -1 */
        else break; /* error, return amount written so far */
     } else if (nwritten == 0) break; 
     nleft -= nwritten;
     ptr   += nwritten;
   }
   return(n - nleft); /* return >= 0 */
}

char* app_path(char* path, const char* filename){
    char buf[PATH_MAX];
    
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

