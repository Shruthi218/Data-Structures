// global variables
extern int total_nolock;
extern int total_rwlock;
extern int total_mylock;

extern pthread_rwlock_t rwlock;
extern pthread_rdwrlock_t rdwrlock;

/* ----- test for no lock ------ */
void *writernolock(void *arg) {
  for(int i = 0; i < 100000; i++) {
      total_nolock++;
  } 
  return NULL;
}

void *readernolock(void *arg) {
  for(int i = 0; i < 10; i++) {
  }
  return NULL;
}  
/* ---- end test ----- */


/* ------ test for pthread rw locks ------- */
void *writerLock(void *arg) {
  for(int i = 0; i < 100000; i++) {
  pthread_rwlock_wrlock(&rwlock);
      total_rwlock++;
  pthread_rwlock_unlock(&rwlock);
  } 
  return NULL;
}

void *readerLock(void *arg) {
  pthread_rwlock_rdlock(&rwlock);
  for(int i = 0; i < 10; i++) {
  }
  pthread_rwlock_unlock(&rwlock);
  return NULL;
}
/* -------- end test ------- */

/* -------- test for pthread customized rw locks ----- */
void *writermyLock(void *arg) {
  for(int i = 0; i < 100000; i++) {
  pthread_rwlock_wrlock_myfunc(&rdwrlock);
      total_mylock++;
  pthread_rwlock_unlock_myfunc(&rdwrlock);
  } 
  return NULL;
}

void *readermyLock(void *arg) {
  pthread_rwlock_rdlock_myfunc(&rdwrlock);
  for(int i = 0; i < 10; i++) {
  }
  pthread_rwlock_unlock_myfunc(&rdwrlock);
  return NULL;
}  
/* -------- end test ------ */

