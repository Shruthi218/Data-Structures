#include <pthread.h>
#include <iostream>
#include "lock.h"
#include "rwlocktest.h"


int total_nolock = 0;
int total_rwlock = 0;
int total_mylock = 0;

pthread_rwlock_t rwlock;
pthread_rdwrlock_t rdwrlock;

int tmp[5];
int tmp1[5];
int tmp2[5];

void noLock() {

     pthread_t thread1[5];
     pthread_t thread2, thread3;
     int i;
  
     for (int j=0; j<5; j++) {
       tmp[j] = j;
       if ((i=pthread_create(&thread1[j], NULL, writernolock, (void*)&tmp[j])) != 0) {
	 std::cout << "thread creation failed. " << j << "\n"; 
       }
     }

     if ((i=pthread_create(&thread2, NULL, readernolock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }

     if ((i=pthread_create(&thread3, NULL, readernolock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }

     for(int j = 0; j < 5; j++) 
      pthread_join(thread1[i], NULL);
     pthread_join(thread2, NULL);
     pthread_join(thread3, NULL);

}

void rwLock() {

     pthread_t thread1[5];
     pthread_t thread2, thread3;
     int i;

    pthread_rwlock_init(&(rwlock), NULL); 
     
     for (int j=0; j<5; j++) {
       tmp1[j] = j;
       if ((i=pthread_create(&thread1[j], NULL, writerLock, (void*)&tmp1[j])) != 0) {
	 std::cout << "thread creation failed. " << j << "\n"; 
       }
     }

     if ((i=pthread_create(&thread2, NULL, readerLock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }
  
     if ((i=pthread_create(&thread3, NULL, readerLock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }

     for(int k = 0; k < 5; k++) 
      pthread_join(thread1[k], NULL);
     pthread_join(thread2, NULL);
     pthread_join(thread3, NULL);

}


void myLock() {

     pthread_t thread1[5];
     pthread_t thread2, thread3;
     int i;

    pthread_rwlock_init_myfunc(&(rdwrlock), NULL); 
     
     for (int j=0; j<5; j++) {
       tmp2[j] = j;
       if ((i=pthread_create(&thread1[j], NULL, writermyLock, (void*)&tmp2[j])) != 0) {
	 std::cout << "thread creation failed. " << j << "\n"; 
       }
     }

     if ((i=pthread_create(&thread2, NULL, readermyLock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }
  
     if ((i=pthread_create(&thread3, NULL, readermyLock, (void*)NULL)) != 0) {
       std::cout << "thread creation failed. " << i << "\n";
     }

     for(int k = 0; k < 5; k++) 
      pthread_join(thread1[k], NULL);
     pthread_join(thread2, NULL);
     pthread_join(thread3, NULL);

}
int main(int argc, char **argv) {
  noLock();
  std::cout << "In main, final value of global with no locks " << total_nolock <<"\n";
  rwLock();
  std::cout << "In main, final value of global with pthread locks " <<  total_rwlock << "\n";
  myLock();
  std::cout << "In main, final value of global with customized locks " << total_mylock << "\n";
  return 0;
}
