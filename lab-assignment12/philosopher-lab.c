//name: Xinchen Xu
//email: xu.xinc@northeastern.edu

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t chopstick[5]; // lock variable

// Thread to be executed
void *philosopher(void *x)
{
    // Treat variable x as a pointer to an int and then extract the value into n
    int* a = (int*)x;
    int n = *a;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", n);
        sleep(1);

        // Pick up chopsticks
        if (n % 2 == 0) {
            pthread_mutex_lock(&chopstick[n]);
            pthread_mutex_lock(&chopstick[(n + 1) % 5]);
        } else {
            pthread_mutex_lock(&chopstick[(n + 1) % 5]);
            pthread_mutex_lock(&chopstick[n]);
        }

        // Eating
        printf("Philosopher %d is eating.\n", n);
        sleep(2);

        // Put down chopsticks
        pthread_mutex_unlock(&chopstick[n]);
        pthread_mutex_unlock(&chopstick[(n + 1) % 5]);

        // Finished eating
        printf("Philosopher %d finished eating.\n", n);
    }
    return NULL;
}

/*------------ Main Program ---------*/
int main()
{
    int i, val[5];
    pthread_t threads[5];

    // Initializing the mutex (for chopsticks)
    for (i = 0; i < 5; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    // Create and run the threads
    for (i = 0; i < 5; i++) {
        val[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &val[i]);
    }

    // Wait until all the threads are done
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroying the mutex
    for (i = 0; i < 5; i++) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}

