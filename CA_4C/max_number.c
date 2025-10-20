/*
 * Program Name: max_number.c
 * Purpose: This program demonstrates nested if-else and conditional operators by:
 *          - Using nested if-else statements to find the largest of three numbers
 *          - Implementing the same logic using conditional (ternary) operators
 *          - Comparing structured vs. concise conditional expressions
 *          - Understanding the "dangling else" problem and proper bracing
 *          - Testing various number combinations for accuracy
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void) 
{
    int x, y, z;  // Variables to store the three numbers

    // Prompt user for input
    printf("Enter 3 Integers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Part A: Use nested if-else statements to find the maximum
    printf("Part A - Using nested if-else:\n");
    if (x > y) 
    {
        if (x > z) 
        {
            printf("Largest: %d\n", x);  // x is largest
        } 
        else 
        {
            printf("Largest: %d\n", z);  // z is largest
        }
    } 
    else if (y > z) 
    {
        printf("Largest: %d\n", y);      // y is largest
    } 
    else 
    {
        printf("Largest: %d\n", z);      // z is largest when neither x nor y are
    }

    // Part B: Use conditional operator (ternary) for the same logic
    printf("\nPart B - Using conditional operator:\n");
    printf("Largest: %d\n", (x > y ? (x > z ? x : z) : (y > z ? y : z)));

    return 0;  // Program completed successfully
}