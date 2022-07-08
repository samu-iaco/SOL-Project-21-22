/**
 * @file utils.h
 * @brief header contenente macro per utilità
 * 
 */

#ifndef utils
#define utils

#include <stdlib.h>
#include <stdio.h>

#define SYSCALL(r, c, e) \
    if ((r = c) == -1)   \
    {                    \
        perror(e);       \
        exit(errno);     \
    }

#define CHECK_RETURN()


/**
 * @brief alloca una stringa data la sua dimensione
 * 
 * @param dim dimensione stringa
 * @return stringa allocata nello heap
 */
char* alloc_strings(size_t dim);


#endif