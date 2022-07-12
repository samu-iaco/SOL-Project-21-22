#include <queue.h>

requestList* init_queue(){
    requestList *q = malloc(sizeof(requestList *));
    if(q == NULL){
        perror("malloc init_queue");
        exit(EXIT_FAILURE);
    }

    return q;
}