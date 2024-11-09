#include <pthread.h>  // For pthread functions
#include <semaphore.h> // For semaphore functions
#include <unistd.h>   // For sleep function
#include <stdio.h>    // For printf

// Semaphores for synchronization
sem_t r; // Semaphore to protect the read count
sem_t w; // Semaphore to protect the writing operation

int rcount = 0; // Count of active readers

// Reader function
void* reader(void* arg) {
    // Wait to access the reader count semaphore
    sem_wait(&r); // Lock the read count access
    rcount++; // Increment the count of active readers

    // If this is the first reader, lock the writer semaphore
    if (rcount == 1) {
        sem_wait(&w); // Lock writing access for readers
    }
    sem_post(&r); // Release the lock on the read count

    // Perform the reading operation
    printf("\nReading Operation is Performed");

    // Wait to access the reader count semaphore again
    sem_wait(&r); // Lock the read count access
    rcount--; // Decrement the count of active readers

    // If this was the last reader, unlock the writer semaphore
    if (rcount == 0) {
        sem_post(&w); // Allow writers to access
    }
    sem_post(&r); // Release the lock on the read count
    return NULL; // Return from the thread
}

// Writer function
void* writer(void* arg) {
    // Wait for writing access
    sem_wait(&w); // Lock writing access

    // Perform the writing operation
    printf("\nWriting operation is Performed");

    sem_post(&w); // Release the lock on writing access
    return NULL; // Return from the thread
}

// Main function
int main() {
    pthread_t Rtid[5]; // Thread IDs for readers
    pthread_t Wtid[5]; // Thread IDs for writers

    // Initialize semaphores
    sem_init(&r, 0, 1); // Initialize semaphore for read count with value 1
    sem_init(&w, 0, 1); // Initialize semaphore for writing with value 1

    // Create writer and reader threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&Wtid[i], NULL, writer, NULL); // Create writer thread
        pthread_create(&Rtid[i], NULL, reader, NULL); // Create reader thread
    }

    // Wait for all writer and reader threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(Wtid[i], NULL); // Wait for writer thread
        pthread_join(Rtid[i], NULL); // Wait for reader thread
    }

    printf("\n"); // Print a new line at the end
    return 0; // Exit the program
}

