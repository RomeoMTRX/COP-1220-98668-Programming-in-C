#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create parallel arrays for salespeople and their sales
    char salespeople[3] = {'D', 'E', 'F'};
    double sales[3] = {0.0, 0.0, 0.0}; // Initialize all sales to 0
    
    char choice;
    double amount;
    int i;
    double grandTotal;
    int highestIndex;
    
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
                sales[0] += amount;
                break;
                
            case 'E':
            case 'e':
                printf("Enter sale amount: $");
                scanf("%lf", &amount);
                sales[1] += amount;
                break;
                
            case 'F':
            case 'f':
                printf("Enter sale amount: $");
                scanf("%lf", &amount);
                sales[2] += amount;
                break;
                
            default:
                printf("Error, invalid salesperson selected, please try again\n");
        }
    }
    
    // Calculate grand total of all sales 
    grandTotal = 0;
    for(i = 0; i < 3; i++) {
        grandTotal += sales[i];
    }
    
    // Find the salesperson with highest sales
    highestIndex = 0;
    for(i = 1; i < 3; i++) {
        if(sales[i] > sales[highestIndex]) {
            highestIndex = i;
        }
    }
    
    // Display final results
    printf("\nResults:\n");
    printf("D Total: $%.2f\n", sales[0]);
    printf("E Total: $%.2f\n", sales[1]);
    printf("F Total: $%.2f\n", sales[2]);
    printf("Grand Total: $%.2f\n", grandTotal);
    printf("Highest Sale: %c\n", salespeople[highestIndex]);
    
    system("pause");
    return 0;
}