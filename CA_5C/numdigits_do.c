/*
 * Program Name: numdigits_do.c
 * Purpose: This program counts the number of digits in a non-negative integer using:
 *          - A do-while loop for digit counting
 *          - Integer division by 10 to remove rightmost digit
 *          - Counter variable to track total digits
 *          - Demonstration of do-while loop behavior (executes at least once)
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void){
    int n = 0, digits = 0;  // n stores the input number, digits counts the digits

    // Prompt user for input
    printf("Enter non-negative integer: ");
    scanf("%d", &n);

    // Use do-while loop to count digits
    // The do-while ensures the loop runs at least once, 
    // which correctly handles the case when n = 0 (has 1 digit)
    do{
        n = n / 10;     // Remove rightmost digit by integer division
        digits++;       // Increment digit counter
        
    }while (n > 0);     // Continue while there are still digits left
    
    // Display the result
    printf("The number has: %d digit(s)", digits);
    return 0;
}