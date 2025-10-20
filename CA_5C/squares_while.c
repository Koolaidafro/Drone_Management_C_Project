/*
 * Program Name: squares_while.c
 * Purpose: This program generates a table of numbers and their squares using:
 *          - While loop with explicit counter variable management
 *          - Pre-loop initialization of counter variable
 *          - Manual increment of loop variable within loop body
 *          - Tabulated output formatting with tab character
 *          - Comparison between while loop and for loop approaches
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void){
    int n, i = 1;   // n stores upper limit, i is the loop counter initialized to 1

    // Get the range limit from user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Generate table using while loop
    // Unlike for loop, we must manually manage the counter variable
    while (i <= n)
    {
        // Print current number and its square with tab separation
        printf("%d\t%d\n", i, i * i);
        
        // Manually increment counter (essential to avoid infinite loop)
        i++;
    }
    
    return 0;
}