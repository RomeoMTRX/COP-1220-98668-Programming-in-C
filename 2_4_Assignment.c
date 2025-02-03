#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables for keeping track of each salesperson's total sales
    double dTotal = 0, eTotal = 0, fTotal = 0;
    char choice;
    double amount;
    // Display program header
    printf("Holiday Homes Sales Tracker\n");
    printf("---------------------------\n");
    // Main program loop
    while(1) {
        // Get salesperson initial from user
        printf("\nEnter salesperson (D, E, F) or Z to finish: ");
        scanf(" %c", &choice);
    // Check if user wants to exit
        if(choice == 'Z' || choice == 'z') {
            break;
        }
    // Process the sale based on salesperson initial
        switch(choice) {
            case 'D':
            case 'd':
                printf("Enter sale amount: $");
                scanf("%lf", &amount);
                dTotal += amount;
                break;

            case 'E':
            case 'e':
                printf("Enter sale amount: $");
                scanf("%lf", &amount);
                eTotal += amount;
                break;

            case 'F':
            case 'f':
                printf("Enter sale amount: $");
                scanf("%lf", &amount);
                fTotal += amount;
                break;

            default:
                printf("Error, invalid salesperson selected, please try again\n");
        }
    }
    // Calculate grand total of all sales 
    double grandTotal = dTotal + eTotal + fTotal;
    char highest = 'D';
    // Compare totals to find the highest
    if(eTotal > dTotal && eTotal > fTotal) {
        highest = 'E';
    } else if(fTotal > dTotal && fTotal > eTotal) {
        highest = 'F';
    }
    // Display final results
    printf("\nResults:\n");
    printf("D Total: $%.2f\n", dTotal);
    printf("E Total: $%.2f\n", eTotal);
    printf("F Total: $%.2f\n", fTotal);
    printf("Grand Total: $%.2f\n", grandTotal);
    printf("Highest Sale: %c\n", highest);

    system("pause");
    return 0;
}