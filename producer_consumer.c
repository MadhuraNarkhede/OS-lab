#include <pthread.h>  // For pthread functions
#include <semaphore.h> // For semaphore functions
#include <unistd.h>   // For sleep function
#include <stdio.h>    // For printf
#include <stdlib.h>   // For rand and malloc
#include <time.h>     // For time function for random seed

// Semaphores for synchronization
sem_t e; // Semaphore to count empty slots in the buffer
sem_t f; // Semaphore to count filled slots in the buffer
sem_t s; // Semaphore for mutual exclusion (mutex)

// Circular buffer and its indices
int buff[5]; // Buffer size of 5
int in = 0;  // Index for the next position to insert data
int out = 0; // Index for the next position to remove data

// Producer function
void* producer(void* arg) {
    while (1) { // Run indefinitely
        sem_wait(&e); // Wait for an empty slot (decrement empty semaphore)
        sem_wait(&s); // Wait to enter critical section (lock)

        // Generate random data and insert it into the buffer
        int data = rand(); // Create random data
        buff[in] = data; // Place data in buffer
        printf("\nProduct %d entered by %lu successfully\n", data, pthread_self());

        in = (in + 1) % 5; // Move to next position in a circular manner

        sem_post(&s); // Exit critical section (unlock)
        sem_post(&f); // Signal that there is a new filled slot (increment filled semaphore)

        sleep(1); // Simulate time taken to produce
    }
    return NULL; // Return from thread
}

// Consumer function
void* consumer(void* arg) {
    while (1) { // Run indefinitely
        sem_wait(&f); // Wait for a filled slot (decrement filled semaphore)
        sem_wait(&s); // Wait to enter critical section (lock)

        // Retrieve data from the buffer
        int data = buff[out]; // Get data from buffer
        printf("\nProduct %d consumed by %lu successfully\n", data, pthread_self());

        out = (out + 1) % 5; // Move to next position in a circular manner

        sem_post(&s); // Exit critical section (unlock)
        sem_post(&e); // Signal that there is a new empty slot (increment empty semaphore)

        sleep(2); // Simulate time taken to consume
    }
    return NULL; // Return from thread
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    pthread_t tid[5]; // Thread IDs for producers
    pthread_t ctid; // Thread ID for consumer

    // Initialize semaphores
    sem_init(&e, 0, 5); // Initialize empty semaphore to buffer size (5)
    sem_init(&f, 0, 0); // Initialize filled semaphore to 0 (buffer is initially empty)
    sem_init(&s, 0, 1); // Initialize mutex semaphore to 1 (allow one thread at a time)

    // Create producer threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, producer, NULL);
    }
    
    // Create a consumer thread
    pthread_create(&ctid, NULL, consumer, NULL);

    // Wait for all producer threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    }

