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

// Function to load salespeople from file
int loadSalespeople(SalesPerson salespeople[], int maxSize) {
    FILE *file = fopen("salespeople.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open salespeople.txt file\n");
        return 0;
    }
    
    int count = 0;
    while (count < maxSize && !feof(file)) {
        if (fscanf(file, "%19s %c", salespeople[count].name, &salespeople[count].initial) == 2) {
            salespeople[count].sales = 0.0; // Initialize sales to 0
            count++;
        }
    }
    
    fclose(file);
    return count;
}

// Function to clear all sales data (useful for testing)
void clearSalesData() {
    // Just remove the file entirely for a fresh start
    remove("sales.txt");
}

int main() {
    const int MAX_SALESPEOPLE = 10;
    SalesPerson salespeople[MAX_SALESPEOPLE];
    
    // Clear the sales data at the beginning of the program
    // Uncomment this for testing
    // clearSalesData();
    
    // Load salespeople from file
    int numSalespeople = loadSalespeople(salespeople, MAX_SALESPEOPLE);
    
    if (numSalespeople == 0) {
        printf("No salespeople found in the file. Exiting program.\n");
        system("pause");
        return 1;
    }
    
    // Initialize all sales to 0
    for (int i = 0; i < numSalespeople; i++) {
        salespeople[i].sales = 0.0;
    }
    
    char choice;
    double amount;
    char formattedNumber[32];
    
    // Display program header
    printf("Holiday Homes Sales Tracker\n");
    printf("---------------------------\n");
    
    // Display available salespeople
    printf("Available salespeople:\n");
    for (int i = 0; i < numSalespeople; i++) {
        printf("%c - %s\n", salespeople[i].initial, salespeople[i].name);
    }
    
    // Main program loop
    while(1) {
        // Get salesperson initial from user
        printf("\nEnter salesperson (");
        for (int i = 0; i < numSalespeople; i++) {
            printf("%c", salespeople[i].initial);
            if (i < numSalespeople - 1) printf(", ");
        }
        printf(") or Z to finish: ");
        
        scanf(" %c", &choice);
        
        // Check if user wants to exit
        if(choice == 'Z' || choice == 'z') {
            break;
        }
        
        // Process the sale based on salesperson initial
        choice = toupper(choice);  // Convert to uppercase for easier comparison
        
        int foundSalesperson = -1;
        for (int i = 0; i < numSalespeople; i++) {
            if (toupper(salespeople[i].initial) == choice) {
                foundSalesperson = i;
                break;
            }
        }
        
        if (foundSalesperson != -1) {
            printf("Enter sale amount: $");
            scanf("%lf", &amount);
            salespeople[foundSalesperson].sales += amount;
        } else {
            printf("Error, invalid salesperson selected, please try again\n");
        }
    }
    
    // Calculate grand total and find highest sales
    double grandTotal = 0.0;
    int highestSalesIndex = 0;
    
    for (int i = 0; i < numSalespeople; i++) {
        grandTotal += salespeople[i].sales;
        if (salespeople[i].sales > salespeople[highestSalesIndex].sales) {
            highestSalesIndex = i;
        }
    }
    
    // Display final results
    printf("\nResults:\n");
    
    for (int i = 0; i < numSalespeople; i++) {
        formatWithCommas(salespeople[i].sales, formattedNumber, sizeof(formattedNumber));
        printf("%c Total: $%s\n", salespeople[i].initial, formattedNumber);
    }
    
    formatWithCommas(grandTotal, formattedNumber, sizeof(formattedNumber));
    printf("Grand Total: $%s\n", formattedNumber);
    printf("Highest Sale: %c\n", salespeople[highestSalesIndex].initial);
    
    system("pause");
    return 0;
}