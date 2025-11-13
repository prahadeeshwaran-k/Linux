#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 100000

long counter = 0;

void* increment_counter(void* arg) {
    for (int i = 0; i < ITERATIONS / 2; i++) {
        counter = counter + 1;   // ❌ Critical section — no lock protection
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, increment_counter, NULL);
    pthread_create(&t2, NULL, increment_counter, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Print final counter value
    printf("Final Counter: %ld\n", counter);
    return 0;
}
