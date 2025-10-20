/*
 * Program Name: month_name.c
 * Purpose: This program demonstrates switch statements and case handling by:
 *          - Using switch, case, default, and break statements
 *          - Performing multiple discrete selections based on user input
 *          - Replacing long cascaded if-else structures with cleaner switch logic
 *          - Handling invalid input with default case
 *          - Understanding fall-through behavior and proper break usage
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void)
{
    int month;  // Variable to store the month number

    // Get month number from user
    printf("Enter an integer (1-12): ");
    scanf("%d", &month);

    // Use switch statement to display corresponding month name
    switch (month)
    {
        case 1: 
            printf("January");
            break;

        case 2: 
            printf("February");
            break;

        case 3: 
            printf("March");
            break;

        case 4: 
            printf("April");
            break;

        case 5: 
            printf("May");
            break;

        case 6: 
            printf("June");
            break;

        case 7: 
            printf("July");
            break;

        case 8: 
            printf("August");
            break;

        case 9: 
            printf("September");
            break;

        case 10: 
            printf("October");
            break;

        case 11: 
            printf("November");
            break;

        case 12: 
            printf("December");
            break;
    
        default: 
            printf("Invalid Month");
            break;
    }

    return 0;  // Program completed successfully
}
