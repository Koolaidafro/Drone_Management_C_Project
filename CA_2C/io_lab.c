/*
 * Program Name: io_lab.c
 * Purpose: This program demonstrates formatted input/output in C including:
 *          - Using printf with conversion specifications and field widths
 *          - Working with escape sequences
 *          - Using scanf with format strings and input validation
 *          - Processing structured input (dates, times, fractions)
 *          - Computing and displaying fraction arithmetic
 * 
 * Author: Keith Smith
 * Date: October 4, 2025
 */

#include <stdio.h>

int main(void) {
    printf("Item\tValue\tNotes\n");
    printf("Quotes and a Backslash: \" \\ \n");

    int i = 42;
    float f = 3145.69f;

    printf("Integer: %4d, %-4d\n", i, i);
    printf("Float: %5.3f, %.2e, %g\n", f, f, f);
    printf("\n");

    int date, month;
    printf("Enter the date(mm/dd): ");
    scanf("%d/%d", &date, &month);

    int hour, minute;
    printf("Enter the time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    int num1, num2, denom1, denom2;
    printf("Enter the first fraction (a/b): ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter the second fraction (a/b): ");
    scanf("%d/%d", &num2, &denom2);
    printf("\n");

    int sum_num = num1 * denom2 + num2 * denom1;
    int sum_denom = denom1 * denom2;
    printf("Summary for %02d/%02d at %02d:%02d\n----------------------------\n", date, month, hour, minute);
    printf("Entry\tNum\tDenom\n");
    printf("First:\t%d\t%d\n", num1, denom1);
    printf("Second:\t%d\t%d\n", num2, denom2);
    printf("Sum:\t%d\t%d\n", sum_num, sum_denom);


    return 0;
}