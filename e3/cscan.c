#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total_movement = 0, disk_size;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n + 1]; // +1 for head
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (max cylinder number): ");
    scanf("%d", &disk_size);

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

    // Move right from head to max
    for (i = index + 1; i < n; i++) {
        total_movement += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    // Jump from max to 0 (circular)
    if (head != disk_size - 1) {
        total_movement += abs(head - (disk_size - 1));
        head = disk_size - 1;
        printf(" -> %d", head);
    }
    total_movement += disk_size - 1;  // From max to 0 (wrap-around)
    head = 0;
    printf(" -> %d", head);

    // Continue from 0 to just before initial head position
    for (i = 0; i < index; i++) {
        total_movement += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal head movement: %d\n", total_movement);
    printf("Average head movement: %.2f\n", (float)total_movement / (n - 1));

    return 0;
}

// Step 1: Start the program.

// Step 2: Input number of disk requests (n).

// Step 3: Input the disk request sequence.

// Step 4: Input initial head position.

// Step 5: Input total disk size (max cylinder number).

// Step 6: Add the initial head position to the request list.

// Step 7: Sort the request list in ascending order.

// Step 8: Find the index of the initial head position in the sorted list.

// Step 9: Move the head from the initial position towards the maximum cylinder number, servicing all requests to the right of the head in order.

// Step 10: Move the head to the maximum cylinder (disk_size - 1) if not already there.

// Step 11: Wrap the head from the maximum cylinder to cylinder 0 (add this movement).

// Step 12: Service the remaining requests from cylinder 0 up to just before the initial head position.

// Step 13: Calculate the total head movement as the sum of all movements made.

// Step 14: Calculate average head movement = total head movement / number of requests.

// Step 15: Display the order of service, total head movement, and average head movement.

// Step 16: Stop the program.


// Enter number of disk requests: 6
// Enter the disk request sequence:
// 95
// 180
// 34
// 119
// 11
// 123
// Enter initial head position: 100
// Enter total disk size (max cylinder number): 200

// Order of service: 100 -> 119 -> 123 -> 180 -> 199 -> 0 -> 11 -> 34 -> 95

// Total head movement: 393
// Average head movement: 65.50


