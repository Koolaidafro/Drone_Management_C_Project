#include <stdio.h>

int main(void){

    int n, d;
    printf("Enter Integer greater than 1: ");
    scanf("%d", &n);

    for (d = 2; d < n && n % d != 0; d++){
     ; /* empty loop body */   
    }
    printf("Empty body complete\n\nHowever you did still ask us to print the divisor or prime\nso I did\n");
    
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