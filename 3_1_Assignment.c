#include <stdio.h>

// Function to add up all factors of a number
int sumOfFactors(int number) {
    int sum = 0;
    
    // Loop through all numbers up to the input number
    for(int i = 1; i < number; i++) {
        // If i is a factor, add it to sum
        if(number % i == 0) {
            sum = sum + i;
        }
    }
    return sum;
}

// Function to check if number is perfect
int checkPerfect(int num) {
    int factorSum;
    
    // Get sum of factors
    factorSum = sumOfFactors(num);
    
    // If sum equals the number, it's perfect
    if(factorSum == num) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print result
void printResult(int number) {
    if(checkPerfect(number)) {
        printf("%d is a Perfect Number\n", number);
    } else {
        printf("%d is Not A Perfect Number\n", number);
    }
}

int main() {
    // Test the required numbers
    printf("Testing numbers:\n");
    printf("---------------\n");
    printResult(496);
    printResult(68);
    printResult(5112);
    printResult(8128);
    
    // Find all perfect numbers up to 10000
    printf("\nAll perfect numbers from 1 to 10000:\n");
    printf("------------------------------------\n");
    
    for(int i = 1; i <= 10000; i++) {
        if(checkPerfect(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}