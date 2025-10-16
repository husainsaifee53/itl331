#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, head, total_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n + 1]; // +1 for head
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    request[n] = head; // Add head to request list
    n++;

    // Sort requests in ascending order
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (request[i] == head) {
            index = i;
            break;
        }
    }

    printf("\nOrder of service: %d", head);

    // Move right from head to max request
    for (i = index + 1; i < n; i++) {
        total_movement += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    // Jump from max request to min request (circular jump)
    if (index != 0) {
        total_movement += abs(head - request[0]);
        head = request[0];
        printf(" -> %d", head);
    }

    // Continue from min request up to just before initial head position
    for (i = 1; i < index; i++) {
        total_movement += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal head movement: %d\n", total_movement);
    printf("Average head movement: %.2f\n", (float)total_movement / (n - 1));
}

//     Step 1: Start the program.

// Step 2: Input number of disk requests (n).

// Step 3: Input the disk request sequence.

// Step 4: Input initial head position.

// Step 5: Add the initial head position to the request list.

// Step 6: Sort the request list in ascending order.

// Step 7: Find the index of the initial head position in the sorted list.

// Step 8: Move the head from the initial position towards the highest request, servicing all requests in between.

// Step 9: Jump from the highest request directly to the lowest request (circular jump).

// Step 10: Service all remaining requests from the lowest request up to just before the initial head position.

// Step 11: Calculate total head movement as the sum of all movements made.

// Step 12: Calculate average head movement = total head movement / number of requests.

// Step 13: Display the order of service, total head movement, and average head movement.

// Step 14: Stop the program.

// Enter number of disk requests: 5
// Enter the disk request sequence:
// 40
// 10
// 70
// 50  
// 90
// Enter initial head position: 50

// Order of service: 50 -> 50 -> 70 -> 90 -> 10 -> 40

// Total head movement: 150
// Average head movement: 30.00