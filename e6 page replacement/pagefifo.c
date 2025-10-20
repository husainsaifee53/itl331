#include <stdio.h>

int main() {
    int n,m,rs[50],p[10];
    int i, j,flag,k=0,i1=0;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i] = -1;
    }
    printf("Enter the length of the reference string: ");
    scanf("%d", &m);
    printf("Enter the reference string:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &rs[i]);
    }
    for (i = 0; i < m; i++) {
        flag = 0;
        printf("\nReferencing Page: %d\n", rs[i]);
        for (j = 0; j < n; j++) {
            if (p[j] == rs[i]) {
                flag = 1;
                printf(" -> Hit! ");
                break;
            }
        }
        if (flag == 0) {
            printf(" -> Fault!");
            p[i1] = rs[i];            // Replace the oldest page
            i1 = (i1 + 1) % n;      // Update index for the next replacement
            k++;                      // Increment fault count
        }
        // Print the current state of frames 
        printf("Frames: ");
        for (j = 0; j < n; j++) {
            if (p[j] == -1) {
                printf(" - "); // Empty frame
            } else {
                printf(" %d ", p[j]);
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", k);
    return 0;
}

// ALGORITHM:

// Step 1: Start the program.

// Step 2: Declare the necessary variables for frame count, reference string length, the reference string array, the page frame array, a page fault counter, and a replacement index.

// Step 3: Prompt the user to enter the number of frames and initialize all frames to be empty (e.g., set to -1).

// Step 4: Prompt the user to enter the length of the reference string, and then enter the reference string itself.

// Step 5: For each page in the reference string, loop through the frames to check if the page is already in memory (a "page hit").

// Step 6: If the page is not found in any frame, it is a "page fault". The page that has been in memory the longest (the oldest page) is chosen for replacement.

// Step 7: Place the new page into the frame containing the oldest page and increment the page fault counter. The oldest page is tracked by an index that moves sequentially through the frames.

// Step 8: After processing each page (whether a hit or a fault), display the current state of all frames to the user.

// Step 9: After the entire reference string has been processed, print the total number of page faults.

// Step 10: Stop the program.

/* Output
Enter the number of frames: 3
Enter the length of the reference string: 7
Enter the reference string:
2
4
5
6
2
5
7

Referencing Page: 2
 -> Fault!Frames:  2  -  -

Referencing Page: 4
 -> Fault!Frames:  2  4  -

Referencing Page: 5
 -> Fault!Frames:  2  4  5

Referencing Page: 6
 -> Fault!Frames:  6  4  5

Referencing Page: 2
 -> Fault!Frames:  6  2  5

Referencing Page: 5
 -> Hit! Frames:  6  2  5

Referencing Page: 7
 -> Fault!Frames:  6  2  7

--- End ---

Total Page Faults: 6
PS C:\Users\HP\Desktop\clg files\s5\networking-os-lab\pending nos\e6 page replacement> ./a .out
Enter the number of frames: 3
Enter the length of the reference string: 7
Enter the reference string:
2
4
5
3
5
3
4

Referencing Page: 2
 -> Fault!Frames:  2  -  -

Referencing Page: 4
 -> Fault!Frames:  2  4  -

Referencing Page: 5
 -> Fault!Frames:  2  4  5

Referencing Page: 3
 -> Fault!Frames:  3  4  5

Referencing Page: 5
 -> Hit! Frames:  3  4  5

Referencing Page: 3
 -> Hit! Frames:  3  4  5

Referencing Page: 4
 -> Hit! Frames:  3  4  5

--- End ---

Total Page Faults: 4
*/