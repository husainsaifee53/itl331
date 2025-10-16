#include <stdio.h>
#include <stdlib.h>

int main() {
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

  // Inline bubble sort (ascending)
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

  // Move right first: service requests greater than head
  for (i = index + 1; i < n; i++) {
    total_movement += abs(head - request[i]);
    head = request[i];
    printf(" -> %d", head);
  }

  // Reverse direction: move left and service requests less than head
  for (i = index - 1; i >= 0; i--) {
    total_movement += abs(head - request[i]);
    head = request[i];
    printf(" -> %d", head);
  }

  printf("\n\nTotal head movement: %d\n", total_movement);
  printf("Average head movement: %.2f\n", (float)total_movement / (n - 1)); // exclude head

  return 0;
}


// Enter number of disk requests: 6
// Enter the disk request sequence:
// 95
// 180
// 34
// 119
// 11
// 123
// Enter initial head position: 100

// Order of service: 100 -> 119 -> 123 -> 180 -> 95 -> 34 -> 11

// Total head movement: 249
// Average head movement: 41.50

/*
ALGORITHM:

Step 1: Start the program.

Step 2: Input the number of disk requests (n).

Step 3: Input the disk request sequence (array of track numbers).

Step 4: Input the initial head position.

Step 5: Add the initial head position to the request array.

Step 6: Sort the request array in ascending order.

Step 7: Find the index of the initial head position in the sorted array.

Step 8: Move the head towards the right (higher cylinder numbers):
    a) Service all requests to the right of the initial head in ascending order.
    b) Calculate and add the absolute distance moved for each request.

Step 9: Reverse the head direction to move towards the left (lower cylinder numbers):
    a) Service all requests to the left of the initial head in descending order.
    b) Calculate and add the absolute distance moved for each request.

Step 10: Calculate total head movement as the sum of all movements.

Step 11: Calculate average head movement = total head movement / number of requests (excluding initial head).

Step 12: Display the order of service, total head movement, and average head movement.

Step 13: Stop the program.
*/
