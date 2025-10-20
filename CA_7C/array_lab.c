#include <stdio.h>

#define MAX_N 100
#define ROWS   10
#define COLS   10

void clear_input(void) { int c; while ((c = getchar()) != '\n' && c != EOF) {} }

int main(void) {
    int choice = -1;

    /* Step 1 state (1-D array) */
    int n = 0;
    int a1d[MAX_N] = {0};

    /* Step 3 state (2-D array) */
    int r = 0, c = 0;
    int m2d[ROWS][COLS] = {0};

    do {
        printf("\n=== Array Lab Menu ===\n");
        printf("1) Step 1: 1-D array basics\n");
        printf("2) Step 2: Use sizeof safely\n");
        printf("3) Step 3: 2-D array operations\n");
        printf("0) Quit\n");
        printf("Select: ");
        if (scanf("%d", &choice) != 1) { clear_input(); continue; }

        switch (choice) {
            case 1: {
                /* TODO Step 1:
                   - Ask for n (1..MAX_N)
                   - Read n integers into a 1d[0..n-1]
                   - Print them forward and then in reverse
                   - Prompt for an index/value to edit and apply it if in range
                */
                break;
            }
            case 2: {
                /* TODO Step 2:
                   - Compute capacity = sizeof(a1d)/sizeof(a1d[0]) and print it
                   - Clear the entire storage of a1d to zero using a capacity-based loop
                   - If n>0, refill the first n elements, then compute and print their sum
                   - Also print sizeof(a1d[0]) in bytes
                */
                break;
            }
            case 3: {
                /* TODO Step 3:
                   - Ask for r and c within 1..ROWS and 1..COLS
                   - Read r*c integers into m2d row-by-row
                   - Print the matrix in a grid
                   - If square (r==c), transform into the identity matrix and print it
                     otherwise compute and print each row sum
                */
                break;
            }
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 0);

    return 0;
}