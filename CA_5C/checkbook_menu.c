/*
 * Program Name: checkbook_menu.c
 * Purpose: This program implements a simple checkbook management system with:
 *          - Menu-driven interface for account operations
 *          - Credit (deposit) and debit (withdrawal) transactions
 *          - Balance inquiry and account clearing functions
 *          - Infinite loop with switch statement for menu handling
 *          - Use of goto statement for program termination
 * 
 * Author: Keith Smith
 * Date: October 9, 2025
 */

#include <stdio.h>

int main(void){
    // Initialize account balance to zero
    float balance = 0.0f;

    // Display program title and menu options
    printf("*** ACME Checkbook Program ***\n0 = Clear, 1 = Deposit, 2 = Withdraw, 3 = Check Balance, 4 = Exit\n");

    // Infinite loop to continuously process menu commands
    for(;;){
        int cmd;                // Variable to store user's menu choice
        float amount = 0.0f;    // Variable to store transaction amount
        
        // Get menu command from user
        scanf("%d", &cmd);

        // Process menu selection using switch statement
        switch (cmd)
        {
        case 0: // Clear balance - reset account to zero
            balance = 0.0f;
            break;
        
        case 1: // Credit - add money to account (deposit)
            printf("Enter Amount: ");
            scanf("%f", &amount);
            balance = balance + amount;
            break;
            
        case 2: // Debit - subtract money from account (withdrawal)
            printf("Enter Amount: ");
            scanf("%f", &amount);
            balance -= amount;
            break;
            
        case 3: // Balance inquiry - display current balance
            // Note: There's a bug here - should print balance, not cmd
            printf("Current balance: $%.2f\n", balance);
            break;
            
        case 4: // Exit program
            printf("Thank you for banking with ACME!\nHave a good day!\n");
            goto END;
            break;
        
        default: // Handle invalid menu choices
            break;
        }
    }
    
END: // Label for program termination
    return 0;
}