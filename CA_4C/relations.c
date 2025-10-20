/*
 * Program Name: relations.c
 * Purpose: This program demonstrates relational and logical operators in C including:
 *          - Relational operators (<, >, <=, >=)
 *          - Equality operators (==, !=)
 *          - Logical operators (&&, ||, !)
 *          - Precedence and left-to-right associativity
 *          - Understanding true/false (1/0) values in C expressions
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void) 
{
    int a, b, c;  // Variables to store three numbers

    // Get input from user
    printf("Enter 3 Integers: ");
    scanf("%d%d%d", &a, &b, &c);

    // Print results of various relational and logical operations
    printf("\n");
    printf("a<b: %d\n", a < b);                    // Is a less than b?
    printf("b<=c: %d\n", b <= c);                  // Is b less than or equal to c?
    printf("a==c: %d\n", a == c);                  // Is a equal to c?
    printf("a<b && b<c: %d\n", a < b && b < c);    // Are numbers in ascending order?
    printf("a<b || b>c: %d\n", a < b || b > c);    // Is a less than b OR is b greater than c?
    printf("!(a==b): %d\n", !(a == b));           // Are a and b NOT equal?

    return 0;  // Program completed successfully
}