/**
 * @file utils.h
 * @brief header contenente macro per utilità
 * 
 */

#ifndef utils
#define utils

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <queue.h>

#define SYSCALL(r, c, e,err) \
    if ((r = c) == -1)   \
    {                    \
        perror(e);       \
        err = errno;     \
        return -1;       \
    }

#define OP_CHECK(r, c, op, e)                                               \
    if ((r = c) == -1)                                                      \
    {                                                                       \
        fprintf(stderr, "errore operazione %s: %s\n", op, strerror(e));     \
        exit(EXIT_FAILURE);                                                 \
    }

#define NULL_CHECK(str, e) \
    if (str == NULL)   \
    {                    \
        errno = e;       \
        return -1;       \
    }



/**
 * @brief alloca una stringa data la sua dimensione
 * 
 * @param dim dimensione stringa
 * @return stringa allocata nello heap
 */
char* alloc_strings(size_t dim);


/**
 * @brief  parsing dei comandi da inviare al server
 * @param  argc: numero di argomenti
 * @param  *argv[]: argomenti passati
 * @param  *queue: coda di richieste
 * @return -1 in caso di fallimento. errno viene settata 
 */
int parsing(int argc, char *argv[], requestList *queue);

char* app_path(char* path, const char* filename);


#endif