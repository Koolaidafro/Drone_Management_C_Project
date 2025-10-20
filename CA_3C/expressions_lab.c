/**
 * Name: expressions_lab.c
 * Purpose: Demonstrates various arithmetic expressions and operators in C
 * Author: Keith Smith
 * Date: 2024-09-10
 */

#include <stdio.h>

int main(void) {
    /* Basic arithmetic operations section */
    printf("\nEnter 2 integers: ");
    int a, b, c;
    scanf("%d %d", &a, &b);
    float f = a/b;  /* Note: Integer division result stored in float */
    
    /* Display results of basic arithmetic operations */
    printf("Sum: %d\nDifference: %d\nProduct: %d\nInteger Quotient: %d\nRemainder: %d\n", 
           a + b, a - b, a * b, a/b, a % b);
    printf("Float Quotient: %.3f\n\n", f);

    /* Operator precedence demonstration */
    a = 0, b = 0, c = 0;
    printf("Enter 3 more integers: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("a+b * c: %d\n(a+b) * c: %d\n", a+b*c, (a+b)*c);
    printf("a-b-c: %d\n(a-b) - c: %d\n\n", a-b-c, (a-b)-c);

    /* Prefix and postfix increment operator demonstration */
    int i=1, j=2;
    int k = ++i + j++;  /* Prefix increment of i, postfix increment of j */
    printf("++i + j++ (Prefix Results)\ni:%d\nj:%d\nk:%d\n\n", i, j, k);

    i=1, j=2;
    k = i++ + j++;     /* Postfix increment for both i and j */
    printf("i++ + j++ (Postfix Results)\ni:%d\nj:%d\nk:%d\n\n", i, j, k);

    /* Compound assignment operators demonstration */
    int x = 10;
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;  /* UPC digits */
    printf("Compound Assignments:\nx=10\n");
    x += 5;
    printf("x +=5 → %d\n", x);
    x -= 3;
    printf("x -=3 → %d\n", x);
    x *= 2;
    printf("x *=2 → %d\n", x);
    x /= 4;
    printf("x /=4 → %d\n", x);

    /* UPC check digit calculation
     * Formula: 9 - ((3 * sum of odd positions + sum of even positions - 1) mod 10)
     */
    printf("Enter 11 digit UPC: ");
    scanf("%d%d%d%d%d%d%d%d%d%d%d", 
          &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);
    printf("Check digit: %d\n",
           (9 -(((3 * (d1 + d3 + d5 + d7 + d9 + d11)) + 
                 (d2 + d4 + d6 + d8 + d10)) - 1) % 10));
    
    return 0;
}