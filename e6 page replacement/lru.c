#include<stdio.h>

void main()
{
    int q[20], p[50], c=0, c1, f, i, j, k=0, n, r, t, b[20], c2[20];

    printf("Enter no of frames: ");
    scanf("%d", &f);

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for(i=0; i<n; i++)
        scanf("%d", &p[i]);

    // First page is always a page fault
    q[k] = p[k];
    printf("\n\t%d", q[k]);
    c++;
    k++;

    for(i=1; i<n; i++)
    {
        c1 = 0;
        for(j=0; j<k; j++)
        {
            if(p[i] == q[j])  // Page found → No page fault
            {
                c1 = 1;
                break;
            }
        }
        if(c1 == 0)  // Page Fault
        {
            c++;
            if(k < f)  // If empty frames available
            {
                q[k] = p[i];
                k++;
            }
            else  // Replace using LRU logic
            {
                for(r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for(j = i - 1; j >= 0; j--)
                    {
                        if(q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }

                // Copy c2[] to b[] for finding max
                for(r = 0; r < f; r++)
                    b[r] = c2[r];

                // Sort to find max in b[]
                for(r = 0; r < f; r++)
                {
                    for(j = r; j < f; j++)
                    {
                        if(b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }

                // Replace the page that was least recently used
                for(r = 0; r < f; r++)
                {
                    if(c2[r] == b[0])
                    {
                        q[r] = p[i];
                        break;
                    }
                }
            }
        }

        printf("\n");
        for(j = 0; j < k; j++)
            printf("\t%d", q[j]);
    }

    printf("\n\nTotal number of page faults = %d\n", c);
}







/*
algorithm:
ALGORITHM:

Step 1: Start the program.

Step 2: Declare the necessary variables for the number of pages, number of frames, reference string array, page frame array, and a page fault counter.

Step 3: Prompt the user to enter the number of pages and the reference string.

Step 4: Prompt the user to enter the number of frames.

Step 5: For each page in the reference string, loop through the frames to check if the page is already in memory (a "page hit").

Step 6: If the page is not found in any frame, it is a "page fault". Increment the page fault counter.

Step 7: If there are empty frames available, place the new page in the next empty frame.

Step 8: If all frames are full, find the page that has been unused for the longest time (the "least recently used" page) by looking backwards through the history of the reference string.

Step 9: Replace the least recently used page with the current page from the reference string and display the current state of the frames.

Step 10: After the entire reference string has been processed, print the total number of page faults.

Step 11: Stop the program.


OUTPUT:

Enter length of reference string: 8
Enter the reference string: 2
3
4
1
7
1
4
7

        2
        2       3
        2       3       4
        1       3       4
        1       7       4
        1       7       4
        1       7       4
        1       7       4

Total number of page faults = 5
*/