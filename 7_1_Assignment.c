#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the struct for a salesperson
typedef struct {
    char name[20];     // Full name of the salesperson
    char initial;      // Initial used for input
    double sales;      // Accumulated sales
} SalesPerson;

// Function to format a number with commas
void formatWithCommas(double value, char *buffer, int bufferSize) {
    char temp[32];
    int i, j, count;
    
    // Convert value to an integer string format
    snprintf(temp, sizeof(temp), "%.0f", value);
    
    // Count the number of digits
    count = strlen(temp);
    
    // Calculate the buffer size needed with commas
    int neededSize = count + (count-1) / 3 + 1;
    if (neededSize > bufferSize) {
        snprintf(buffer, bufferSize, "%.0f", value); // Fall back to no commas if buffer too small
        return;
    }
    
    // Format with commas
    j = 0;
    for (i = 0; i < count; i++) {
        if (i > 0 && (count - i) % 3 == 0) {
            buffer[j++] = ',';
        }
        buffer[j++] = temp[i];
    }
    buffer[j] = '\0';
}

int main() {
    // Create individual SalesPerson structs
    SalesPerson danielle = {"Danielle", 'D', 0.0};
    SalesPerson edward = {"Edward", 'E', 0.0};
    SalesPerson francis = {"Francis", 'F', 0.0};
    
    char choice;
    double amount;
    double grandTotal;
    char highestSalesPerson;
    char formattedNumber[32];
    
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
        choice = toupper(choice);  // Convert to uppercase for easier comparison
        
        if(choice == danielle.initial) {
            printf("Enter sale amount: $");
            scanf("%lf", &amount);
            danielle.sales += amount;
        }
        else if(choice == edward.initial) {
            printf("Enter sale amount: $");
            scanf("%lf", &amount);
            edward.sales += amount;
        }
        else if(choice == francis.initial) {
            printf("Enter sale amount: $");
            scanf("%lf", &amount);
            francis.sales += amount;
        }
        else {
            printf("Error, invalid salesperson selected, please try again\n");
        }
    }
    
    // Calculate grand total of all sales
    grandTotal = danielle.sales + edward.sales + francis.sales;
    
    // Find the salesperson with highest sales
    if(danielle.sales >= edward.sales && danielle.sales >= francis.sales) {
        highestSalesPerson = danielle.initial;
    }
    else if(edward.sales >= danielle.sales && edward.sales >= francis.sales) {
        highestSalesPerson = edward.initial;
    }
    else {
        highestSalesPerson = francis.initial;
    }
    
    // Display final results
    printf("\nResults:\n");
    
    formatWithCommas(danielle.sales, formattedNumber, sizeof(formattedNumber));
    printf("%c Total: $%s\n", danielle.initial, formattedNumber);
    
    formatWithCommas(edward.sales, formattedNumber, sizeof(formattedNumber));
    printf("%c Total: $%s\n", edward.initial, formattedNumber);
    
    formatWithCommas(francis.sales, formattedNumber, sizeof(formattedNumber));
    printf("%c Total: $%s\n", francis.initial, formattedNumber);
    
    formatWithCommas(grandTotal, formattedNumber, sizeof(formattedNumber));
    printf("Grand Total: $%s\n", formattedNumber);
    printf("Highest Sale: %c\n", highestSalesPerson);
    
    system("pause");
    return 0;
}