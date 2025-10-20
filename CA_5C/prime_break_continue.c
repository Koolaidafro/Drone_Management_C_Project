/*
 * Program Name: prime_break_continue.c
 * Purpose: This program finds the first divisor of a given integer using:
 *          - For loop to test potential divisors from 2 to n-1
 *          - Continue statement to skip non-divisors
 *          - Break statement to exit loop when first divisor is found
 *          - Modulus operator (%) to test for divisibility
 *          - Demonstrates control flow with break and continue
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void){  // Fixed: should be (void) not (int)
    int n, d;    // n stores the input number, d is the potential divisor

    // Get input from user
    printf("Enter Integer greater than 1: ");
    scanf("%d", &n);

    // Loop through potential divisors from 2 to n-1
    for(d = 2; d < n; d++){

        // If n is not divisible by d, skip to next iteration
        if(n % d != 0){
            continue;   // Skip the break statement and continue with next d
        }
        
        // If we reach here, n is divisible by d (first divisor found)
        break;          // Exit the loop immediately
    }

    // Display the result - shows the first divisor found
    // Note: If n is prime, d will equal n (no divisors found in range 2 to n-1)
    printf("%d is divisible by %d", n, d);

    return 0;
}