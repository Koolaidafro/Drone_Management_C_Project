/*
 * Program Name: types_system.c
 * Purpose: This program demonstrates basic C data types through an interactive menu system including:
 *          - Integer types (int, short, long, unsigned)
 *          - Floating-point types (float, double)
 *          - Character types and ASCII operations
 *          - Boolean logic with stdbool.h
 *          - Type conversion and casting
 *          - Type definitions using typedef
 *          - Format specifiers for input/output
 *          - Menu-driven program flow with switch statements
 * 
 * Author: Keith Smith
 * Date: October 18, 2025
 */

#include <stdio.h>
#include <ctype.h>      // For toupper(), tolower(), and character functions
#include <limits.h>     // For UINT_MAX and other numeric limits
#include <stdbool.h>    // For bool, true, false

int main(void)
{
    // Type alias definition - creates 'Dollars' as an alias for 'double'
    typedef double Dollars;
    
    // Variable declarations organized by type
    unsigned int i = 0;             // Integer value for calculations
    unsigned int unsigned_d = 0;    // Unsigned integer for wraparound demonstration
    double d = 0.0;                 // Double value for calculations
    Dollars dollar_amnt = 0.0;      // Dollar amount using type alias
    long long_d = 0;                // Long integer for size comparison
    short short_d = 0;              // Short integer for size comparison
    char cmd;                       // Command character for menu selection
    char c = '\0';                  // Character for ASCII operations
    bool verbose = false;           // Flag for verbose output mode
    bool running = true;            // Loop control flag

    // Main program loop - continues until user quits
    while (running)
    {
        // Display menu with all available commands
        printf("\n=== C Types System Menu ===\n");
        printf("[i] Set integer          [d] Set double\n");
        printf("[c] Character & ASCII    [u] Convert to uppercase\n");
        printf("[m] Divide int & double  [s] Short & long values\n");
        printf("[w] Unsigned integer     [p] Dollar amount\n");
        printf("[t] Toggle verbose mode  [q] Quit\n");
        printf("Enter command: ");
        
        // Read user command (space before %c skips whitespace)
        scanf(" %c", &cmd);

        // Process user command with switch statement
        switch (cmd)
        {
            // ===== ACTIVITY 1: Integer and Double Input/Output =====
            
            case 'i':  // Set integer value
                printf("\nEnter an integer: ");
                scanf("%d", &i);
                printf("Integer set to: %d\n", i);
                break;

            case 'd':  // Set double value
                printf("\nEnter a double: ");
                scanf("%lf", &d);  // Use %lf for double input
                printf("Double set to: %.3f\n", d);
                break;

            // ===== ACTIVITY 2: Character Types and ASCII Operations =====
            
            case 'c':  // Character and ASCII operations
                printf("\nEnter a character: ");
                scanf(" %c", &c);  // Space before %c skips whitespace
                
                // Display character information
                printf("\n--- Character Information ---\n");
                printf("Character: %c\n", c);
                printf("ASCII Value: %d\n", (int)c);
                printf("Next Character: %c (ASCII %d)\n", 
                       (char)((int)c + 1), (int)c + 1);
                break;
            
            case 'u':  // Convert to uppercase
                printf("\nEnter a letter: ");
                scanf(" %c", &c);
                printf("Uppercase: %c\n", toupper(c));
                break;

            // ===== ACTIVITY 3: Casting, Conversion, and Unsigned Types =====
            
            case 'm':  // Divide integer by double (demonstrates casting)
                // Check if values have been set
                if (i == 0 || d == 0.0)
                {
                    printf("\nError: Please set both integer [i] and double [d] values first.\n");
                }
                else
                {
                    printf("\n--- Division Results ---\n");
                    printf("Integer / Double with cast: %.3f\n", ((double)i) / d);
                    printf("Integer / Double without cast: %.3f\n", (double)(i / (int)d));
                    printf("\nNote: Casting ensures floating-point division.\n");
                }
                break;

            case 's':  // Short and long integer demonstration
                printf("\nEnter a short integer: ");
                scanf("%hd", &short_d);  // %hd for short
                
                printf("Enter a long integer: ");
                scanf("%ld", &long_d);   // %ld for long
                
                printf("\n--- Integer Size Comparison ---\n");
                printf("Short value: %hd\n", short_d);
                printf("Long value: %ld\n", long_d);
                break;

            case 'w':  // Unsigned integer and wraparound behavior
                printf("\nEnter an unsigned integer: ");
                scanf("%u", &unsigned_d);  // %u for unsigned int
                
                printf("\n--- Unsigned Integer Information ---\n");
                printf("Unsigned integer: %u\n", unsigned_d);
                printf("Unsigned + 1: %u\n", unsigned_d + 1);
                printf("UINT_MAX: %u\n", UINT_MAX);
                printf("\nNote: Unsigned integers wrap around at UINT_MAX.\n");
                break;

            // ===== ACTIVITY 4: Boolean Logic and Type Definitions =====
            
            case 't':  // Toggle verbose mode
                verbose = !verbose;  // Toggle boolean flag
                printf("\nVerbose mode: %s\n", verbose ? "ENABLED" : "DISABLED");
                break;

            case 'p':  // Dollar amount using typedef
                printf("\nEnter a dollar amount: $");
                scanf("%lf", &dollar_amnt);  // %lf for double (Dollars is typedef for double)
                printf("Amount stored: $%.2f\n", dollar_amnt);
                break;

            case 'q':  // Quit program
                printf("\nExiting program. Goodbye!\n");
                running = false;  // Exit loop
                break;

            default:  // Invalid command
                printf("\nInvalid command. Please try again.\n");
                break;
        }

        // If verbose mode is enabled, display current stored values
        if (verbose && running)
        {
            printf("\n--- Current Values (Verbose Mode) ---\n");
            printf("Integer: %d\n", i);
            printf("Double: %.3f\n", d);
            printf("Last character: '%c' (ASCII %d)\n", c, (int)c);
            printf("Dollar amount: $%.2f\n", dollar_amnt);
            printf("------------------------------------\n");
        }
    }

    return 0;  // Program completed successfully
}