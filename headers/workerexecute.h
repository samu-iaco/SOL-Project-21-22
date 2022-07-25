#include <serverapi.h>
#include <pthread.h>

typedef struct _thworker{
    int thid;
    int* thpipe;
}thworker;

int init_worker(pthread_t *worker, int** pipe, int nworker);