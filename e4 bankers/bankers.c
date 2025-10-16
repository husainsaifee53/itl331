#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 5

int main() {
    int numProcesses, numResources;
    int totalResources[MAX_RESOURCES], available[MAX_RESOURCES];
    int allocated[MAX_PROCESSES][MAX_RESOURCES];
    int maximum[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finished[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int i, j, count = 0;

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    printf("Enter the total instances of each resource:\n");
    for (i = 0; i < numResources; i++) {
        printf("Resource %c: ", 'A' + i);
        scanf("%d", &totalResources[i]);
        available[i] = totalResources[i];
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < numResources; j++) {
            scanf("%d", &allocated[i][j]);
            available[j] -= allocated[i][j];
        }
    }

    printf("\nEnter the Maximum Requirement Matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i);
        for (j = 0; j < numResources; j++) {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }

    int allFinished;
    while (count < numProcesses) {
        allFinished = 0;
        for (i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                int canAllocate = 1;
                for (j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    for (j = 0; j < numResources; j++) {
                        available[j] += allocated[i][j];
                    }
                    safeSequence[count++] = i;
                    finished[i] = 1;
                    allFinished = 1;
                }
            }
        }
        if (!allFinished) {
            printf("\nThe system is in an UNSAFE state. Deadlock may occur.\n");
            return 0;
        }
    }

    printf("\nThe system is in a SAFE state.\nSafe sequence is:\n\t< ");
    for (i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf(">\n");

    return 0;
}


//
//Step 1: Let Work and Finish be vectors of length „m‟ and „n‟ respectively.
//Initialize: Work = Available
//Finish[i] = false; for i=1, 2, 3, 4….n
//Step 2: Find an i such that both
//a) Finish[i] = false
//b) Needi <= Work
//if no such i exists goto step (4)
//Step 3: Work = Work + Allocation[i]
/*Finish[i] = true
goto step (2)
// Step 4:
// If finished[i] == true for all i = 0 to numProcesses-1
// then the system is in a safe state.
// Otherwise, system is unsafe.*/


/*OUTPUT

Enter the number of resources: 3
Enter the total instances of each resource:
Resource A: 10
Resource B: 5
Resource C: 7

Enter the number of processes: 5

Enter the Allocation Matrix:
Process 0:
0
1
0
Process 1:
2
0
0
Process 2:
3
0
2
Process 3:
2
1
1
Process 4:
0
0
2

Enter the Maximum Requirement Matrix:
Process 0:
7
5
3
Process 1:
3
2
2
Process 2:
9
0
2
Process 3:
2
2
2
Process 4:
4
3
3

The system is in a SAFE state.
Safe sequence is:
	< P1 P3 P4 P0 P2 >
*/
