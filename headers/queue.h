/**
 * @file queue.h
 * @brief headers per gestire coda di richieste
 */

// typedef struct _request_queue
// {
//     char* request;
// }request_queue;

#include <stdio.h>
#include <stdlib.h>

typedef struct requestList_t
{
    char *request;
    struct requestList* next;
}requestList;



requestList* init_queue();

