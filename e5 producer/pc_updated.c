#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void produce() {
    int item;

    if (sem_trywait(&empty) != 0) {
        printf("Buffer is full. Cannot produce.\n");
        return;
    }

    sem_wait(&mutex);

    printf("Enter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    printf("Produced: %d at index %d\n", item, in);
    in = (in + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&full);
}

void consume() {
    int item;

    if (sem_trywait(&full) != 0) {
        printf("Buffer is empty. Cannot consume.\n");
        return;
    }

    sem_wait(&mutex);

    item = buffer[out];
    printf("Consumed: %d from index %d\n", item, out);
    out = (out + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    int choice;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);      // Mutex = 1
    sem_init(&empty, 0, SIZE);   // Empty slots = SIZE
    sem_init(&full, 0, 0);       // Full slots = 0

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                produce();
                break;

            case 2:
                consume();
                break;

            case 3:
                printf("Exiting...\n");
                sem_destroy(&mutex);
                sem_destroy(&empty);
                sem_destroy(&full);
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


// output


// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 2
// Buffer is empty. Cannot consume.

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 1
// Enter item to produce: 20
// Produced 20 at index 0

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 1
// Enter item to produce: 23
// Produced 23 at index 1

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 2
// Consumed 20 from index 0

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 2
// Consumed 23 from index 1

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// 3. Exit
// Enter your choice: 2
// Consumed 23 from index 1

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// 2. Consume
// 3. Exit
// 3. Exit
// Enter your choice: 2
// Buffer is empty. Cannot consume.

// Menu:
// 1. Produce
// 2. Consume
// 3. Exit
// Enter your choice: 3
// Exiting...


// Algo:

// Step 1: Start
// Step 2: Define an array buffer[SIZE] to simulate the shared buffer.
// Step 3: Declare semaphore variables:
//     sem_t mutex for mutual exclusion.
//     sem_t empty to count empty buffer slots.
//     sem_t full to count filled buffer slots.
// Step 4: Initialize global variables in = 0 and out = 0 (circular buffer indices).
// Step 5: Initialize semaphores:
//     mutex to 1 (unlocked).
//     empty to SIZE (buffer capacity).
//     full to 0 (initially empty buffer).
// Step 6: Use a menu in the main loop to perform the following actions:
//     Produce
//     Consume
//     Exit
// Step 7: Check if empty slots are available using sem_trywait(&empty)
//     If not available, print "Buffer full", skip producing.
// Step 8: Lock the critical section using sem_wait(&mutex)
// Step 9: Ask the user to input the item to produce.
// Step 10: Insert item at buffer[in], update in = (in + 1) % SIZE
// Step 11: Unlock critical section using sem_post(&mutex)
// Step 12: Signal sem_post(&full) to indicate one item is available
// Step 13: Check if items are available using sem_trywait(&full)
//         If not available, print "Buffer empty", skip consuming.
// Step 14: Lock the critical section using sem_wait(&mutex)
// Step 15: Remove item from buffer[out], update out = (out + 1) % SIZE
// Step 16: Unlock critical section using sem_post(&mutex)
// Step 17: Signal sem_post(&empty) to indicate one slot is now empty
// Step 18: On exit, destroy all semaphores using sem_destroy()
// Step 19: Terminate the program
// Step 20: Stop