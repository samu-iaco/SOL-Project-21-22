#include <unistd.h>
#include <pthread.h>

#include <serverapi.h>
#include <workerexecute.h>


pthread_mutex_t mutexQueue = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condQueue = PTHREAD_COND_INITIALIZER;


/**
 * @brief gestione delle richieste del client
 * 
 * @param arg struttura dati del worker
 */
void* startWorker(void* arg){
    int thid = ((thworker *)arg)->thid;
    //int *pipe = ((thworker *)arg)->thpipe;

    printf("ciao sono il worker n. %d\n", thid);

    return 0;
}

int init_worker(pthread_t *worker, int** pipes, int nworker){

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
        workerinfo->thpipe = pipes[i];
        if (pthread_create(&(worker[i]), NULL, &startWorker, (void *)workerinfo) != 0)
        {
            perror("Failed to create the thread");
        }

    }

    return 0;
}

