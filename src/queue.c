#include <queue.h>

node* init_queue(){
    node *q = malloc(sizeof(node *));
    if(q == NULL){
        perror("malloc init_queue");
        exit(EXIT_FAILURE);
    }

    return q;
}