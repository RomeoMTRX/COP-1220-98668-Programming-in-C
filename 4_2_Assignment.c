#include <stdio.h>
#include <stdlib.h>

int main() {
    // Constants
    const int NUM_TEMPS = 5;
    const int MIN_TEMP = -30;
    const int MAX_TEMP = 130;
    
    // Array to store temperatures
    int temperatures[5];
    int temp;
    float sum = 0;
    int isAscending = 1;    // Flag for checking if temperatures are ascending
    int isDescending = 1;   // Flag for checking if temperatures are descending
    
    // Display program header
    printf("Temperature Comparison\n");
    printf("----------------------\n");
    
    // Get 5 temperature inputs
    for(int i = 0; i < NUM_TEMPS; i++) {
        // Keep asking until a valid temperature is entered
        do {
            printf("Enter temperature #%d: ", i + 1);
            scanf("%d", &temp);
            
            // Check if temperature is in valid range
            if(temp < MIN_TEMP || temp > MAX_TEMP) {
                printf("EXCEPTION Temperature %d is invalid, Please enter a valid temperature between -30 and 130\n", temp);
            }
        } while(temp < MIN_TEMP || temp > MAX_TEMP);
        
        // Store valid temperature in array
        temperatures[i] = temp;
        
        // Add to sum for calculating average later
        sum += temp;
        
        // Check order pattern (starting from the second temperature)
        if(i > 0) {
            // If current temp is not higher than previous, it's not strictly ascending
            if(temperatures[i] <= temperatures[i-1]) {
                isAscending = 0;
            }
            
            // If current temp is not lower than previous, it's not strictly descending
            if(temperatures[i] >= temperatures[i-1]) {
                isDescending = 0;
            }
        }
    }
    
    // Determine temperature pattern
    if(isAscending == 1) {
        printf("\nGetting Warmer\n");
    } else if(isDescending == 1) {
        printf("\nGetting Cooler\n");
    } else {
        printf("\nIt's a mixed bag\n");
    }
    
    // Display temperatures - safer approach
    printf("5-day Temperature [");
    for(int i = 0; i < NUM_TEMPS; i++) {
        printf("%d", temperatures[i]);
        if(i < NUM_TEMPS - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    // Calculate and display average
    float average = sum / NUM_TEMPS;
    printf("Average Temperature is %.1f degrees\n", average);
    
    system("pause");
    return 0;
}