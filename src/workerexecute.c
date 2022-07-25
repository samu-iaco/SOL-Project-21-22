#include <workerexecute.h>
#include <unistd.h>


int init_pipe(int **pipe){


    return 0; 
}

int init_worker(pthread_t *worker, int** pipes, int nworker){
    if(worker == NULL || pipe == NULL){
        errno = EINVAL;
        return -1;
    }

    int err;

    for(int i=0; i<nworker; i++){
        pipes[i] = malloc(sizeof(int*) * 2);
        NULL_CHECK_MALLOC(pipes[i]);

        SYSCALL(err,pipe(pipes[i]),"pipe",errno);

        

    }
    

    for(int i=0; i<nworker; i++){
        thworker *workerinfo = malloc(sizeof(thworker));
        NULL_CHECK_MALLOC(workerinfo);

        workerinfo->thid = i;
        


    }

    return 0;
}