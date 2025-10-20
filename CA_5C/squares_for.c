/*
 * Program Name: squares_for.c
 * Purpose: This program generates a table of numbers and their squares using:
 *          - For loop with initialization, condition, and increment
 *          - Loop variable declared within the for statement
 *          - Tabulated output formatting with tab character
 *          - Mathematical computation (squaring numbers)
 *          - Demonstrates compact for loop syntax
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void){
    int n;  // Variable to store the upper limit for the table
    
    // Get the range limit from user
    printf("Enter Positive Integer: ");
    scanf("%d", &n);

    // Generate table of numbers and their squares using for loop
    // Loop variable i is declared and initialized within the for statement
    for(int i = 1; i <= n; i++){
        // Print number and its square in tabulated format
        // \t creates a tab for alignment, \n creates a new line
        printf("%d\t%d\n", i, i * i);
    }

    return 0;
}