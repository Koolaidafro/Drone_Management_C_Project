/*
 * Program Name: number_check.c
 * Purpose: This program demonstrates if and if-else decision statements by:
 *          - Using if, else if, and else statements for multi-way decisions
 *          - Categorizing numbers as positive, negative, or zero
 *          - Determining if numbers are even or odd using modulo operator
 *          - Using compound statements with proper braces for clarity
 *          - Applying conditional logic and proper statement nesting
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void) 
{
    int num = 0;  // Variable to store the input number
    
    // Get input from user
    printf("Enter 1 integer: ");
    scanf("%d", &num);

    // Check if number is positive, negative, or zero
    if (num > 0) 
    {
        printf("The number is positive\n");
    } 
    else if (num == 0) 
    {
        printf("The number is zero\n");
    } 
    else 
    {
        printf("The number is negative\n");
    }

    // Check if number is even or odd using modulo operator
    if (num % 2 == 0) 
    {
        printf("The number is even\n");
    } 
    else 
    {
        printf("The number is odd\n");
    }

    return 0;  // Program completed successfully
}