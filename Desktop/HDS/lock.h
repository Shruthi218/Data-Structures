#ifndef LOCK_H
#define LOCK_H

#include <pthread.h>

struct rdwr {
  int readers;
  int writer;
  pthread_mutex_t mutex;
  pthread_cond_t cvar;
};

typedef rdwr pthread_rdwrlock_t;

/* Init - set writer and readers to 0 and initialize both mutex and condition variable */

int pthread_rwlock_init_myfunc(pthread_rdwrlock_t *rdwrlock, pthread_rwlockattr_t *attr) {
    rdwrlock->readers = 0;
    rdwrlock->writer = 0;
    pthread_mutex_init(&(rdwrlock->mutex), NULL);
    pthread_cond_init(&(rdwrlock->cvar), NULL);
    return 0;     	   
}

/* check if a writer is currently holding a lock and wait if so. Else grab lock and increment reader count. */ 

int pthread_rwlock_rdlock_myfunc(pthread_rdwrlock_t *rdwrlock) {
    
    pthread_mutex_lock(&(rdwrlock->mutex));
    while(rdwrlock->writer) //check here later
        pthread_cond_wait(&(rdwrlock->cvar), &(rdwrlock->mutex));
    rdwrlock->readers++;
    pthread_mutex_unlock(&(rdwrlock->mutex));
    return 0;
}       

/*check for both readers and writer, if not grab the lock and increment writer count */

int pthread_rwlock_wrlock_myfunc(pthread_rdwrlock_t *rdwrlock) {

    pthread_mutex_lock(&(rdwrlock->mutex));
    while((rdwrlock->readers) || (rdwrlock->writer)) 
        pthread_cond_wait(&(rdwrlock->cvar), &(rdwrlock->mutex));
    
     rdwrlock->writer++;
    pthread_mutex_unlock(&(rdwrlock->mutex));
   return 0;
}

/* make sure someone is holding a lock. otherwise return. 
     if writer is holding a lock, decrement writer count and broadcast 
     if readers are holding the locks, decerement reader count. If reader count reaches 0, signal */  

int pthread_rwlock_unlock_myfunc(pthread_rdwrlock_t *rdwrlock) {
    pthread_mutex_lock(&(rdwrlock->mutex));
    if(rdwrlock->writer == 0 && rdwrlock->readers == 0) {
       pthread_mutex_unlock(&(rdwrlock->mutex));
       return -1;
  } else if(rdwrlock->writer) {
       rdwrlock->writer = 0;
       pthread_cond_broadcast(&(rdwrlock->cvar));
       pthread_mutex_unlock(&(rdwrlock->mutex));
       return 0;
    } else if(rdwrlock->readers) {
         rdwrlock->readers--;
         if(rdwrlock->readers == 0) {
         pthread_cond_signal(&(rdwrlock->cvar));
         pthread_mutex_unlock(&(rdwrlock->mutex));
         return 0;
       }
    }
   
}

#endif  
  
  
    
