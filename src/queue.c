#include <queue.h>

requestList* init_queue(){
    requestList *q = malloc(sizeof(requestList *));
    if(q == NULL){
        perror("malloc init_queue");
        exit(EXIT_FAILURE);
    }

    return q;
}

void pushRequest(requestList** queue, int fd){
    if(*queue == NULL){
        printf("lista richiest non inizializzata\n");
        return NULL;
    }

    requestList* newnode = malloc(sizeof(requestList));
    if(newnode == NULL){
        perror("malloc new node request list");
        exit(EXIT_FAILURE);
    }

    newnode->fd = fd;
    newnode->next = queue;

    *queue = newnode;

}