#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void main() {
    int buffer[SIZE];
    int in = 0, out = 0, count = 0;
    int choice, item;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count == SIZE) {
                    printf("Buffer full, cannot produce\n");
                } else {
                    printf("Enter item to produce: ");
                    scanf("%d", &item);
                    buffer[in] = item;
                    in = (in + 1) % SIZE;
                    count++;
                    printf("Produced %d\n", item);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Buffer empty, cannot consume\n");
                } else {
                    item = buffer[out];
                    out = (out + 1) % SIZE;
                    count--;
                    printf("Consumed %d\n", item);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
        
    }
}


1. Produce
2. Consume
3. Exit
Enter your choice: 1
Enter item to produce: 2
Produced 2

1. Produce
2. Consume
3. Exit
Enter your choice: 2
Consumed 2

1. Produce
2. Consume
3. Exit
Enter your choice: 3



Sure! Here’s a **simple algorithm** for the **Producer-Consumer problem** corresponding to the single `main()` function code (no threads, basic simulation):

---

### Simple Algorithm for Producer-Consumer (Single Main Function)

1. **Initialize**:

   * Create a buffer array of fixed size (e.g., 5).
   * Set `in = 0` (index to insert items).
   * Set `out = 0` (index to remove items).
   * Set `count = 0` (number of items currently in buffer).

2. **Repeat forever**:

   * Display a menu:

     * 1. Produce
     * 2. Consume
     * 3. Exit
   * Read user choice.

3. **If choice is Produce**:

   * If `count == SIZE` (buffer full):

     * Display "Buffer full, cannot produce".
   * Else:

     * Ask user to enter an item.
     * Insert the item into `buffer[in]`.
     * Update `in = (in + 1) mod SIZE`.
     * Increment `count`.
     * Display "Produced <item>".

4. **If choice is Consume**:

   * If `count == 0` (buffer empty):

     * Display "Buffer empty, cannot consume".
   * Else:

     * Remove item from `buffer[out]`.
     * Update `out = (out + 1) mod SIZE`.
     * Decrement `count`.
     * Display "Consumed <item>".

5. **If choice is Exit**:

   * Terminate the program.

6. **If choice is invalid**:

   * Display "Invalid choice".

7. Go back to step 2.

---

Let me know if you want me to make a flowchart or explain the threaded/semaphore version algorithm too!

