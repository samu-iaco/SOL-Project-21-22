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

typedef struct _node
{
    char *request;
    struct _node* next;
}node;



node* init_queue();

