//name: Xinchen Xu
//email: xu.xinc@northeastern.edu

// Compile with:
//
// gcc -lpthread hw12.c -o hw12
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 100

// shared variable
int counter = 0;
pthread_mutex_t lock; // mutex to protect the shared variable

// thread to be executed - unspecified variable arguments
void* thread1 (void* vargp) {
  // add 1 to counter
  pthread_mutex_lock(&lock); // lock the mutex
  counter = counter +1;
  pthread_mutex_unlock(&lock); // unlock the mutex
  return NULL;
}

void* thread2 (void* vargp) {
  // add 5 to counter
  pthread_mutex_lock(&lock); // lock the mutex
  counter = counter +5;
  pthread_mutex_unlock(&lock); // unlock the mutex
  return NULL;
}

void* thread3 (void* vargp) {
  // subtract 2 from counter
  pthread_mutex_lock(&lock); // lock the mutex
  counter = counter -2;
  pthread_mutex_unlock(&lock); // unlock the mutex
  return NULL;
}

void* thread4 (void* vargp) {
  // subtract 10 from counter
  pthread_mutex_lock(&lock); // lock the mutex
  counter = counter -10;
  pthread_mutex_unlock(&lock); // unlock the mutex
  return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS*4];
  int i;

  // initialize the mutex
  pthread_mutex_init(&lock, NULL);

  printf("Counter starts at %d\n", counter);

  // create and run the threads
  for (i = 0; i < NTHREADS; ++i) {
    pthread_create(&(tid[i]), NULL, thread1, NULL);
    pthread_create(&(tid[NTHREADS + i]), NULL, thread2, NULL);
    pthread_create(&(tid[2*NTHREADS + i]), NULL, thread3, NULL);
    pthread_create(&(tid[3*NTHREADS + i]), NULL, thread4, NULL);
  }

  // wait until all threads are done
  for (i = 0; i < NTHREADS*4; ++i) {
    pthread_join(tid[i], NULL);
  }

  printf("Counter ends at %d\n", counter);

  // destroy the mutex
  pthread_mutex_destroy(&lock);

  return 0;
}

