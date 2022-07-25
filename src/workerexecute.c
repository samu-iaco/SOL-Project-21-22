#include <workerexecute.h>




int init_worker(pthread_t *worker, int** pipe, int nworker){
    if(worker == NULL || pipe == NULL){
        errno = EINVAL;
        return -1;
    }

    thworker *workerinfo = malloc(sizeof(thworker) * nworker);

    for(int i=0; i<nworker; i++){
        
    }

    return 0;
}