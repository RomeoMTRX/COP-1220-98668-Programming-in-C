#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    // Early exit for numbers <= 1
    if (num <= 1) {
        return 0;
    }
    
    int sum = 1;  // Start with 1 as it's always a divisor
    
    // Check divisors up to num/2 (as no number larger than n/2 can be a divisor except n itself )
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            sum += i;
            
            // Early exit if sum exceeds number
            if (sum > num) {
                return 0;
            }
        }
    }
    
    return (sum == num);
}

void checkNumber(int num) {
    printf("Number tested: %d\n", num);
    if (isPerfect(num)) {
        printf("Perfect Number\n");
    } else {
        printf("Not A Perfect Number\n");
    }
    printf("----------------------------------------\n");
}

int main() {
    // Test Case 1
    printf("\nTest Case 1:\n");
    checkNumber(496);

    // Test Case 2
    printf("\nTest Case 2:\n");
    checkNumber(68);

    // Test Case 3
    printf("\nTest Case 3:\n");
    checkNumber(5112);

    // Test Case 4
    printf("\nTest Case 4:\n");
    checkNumber(8128);
    
    printf("\nPerfect numbers between 1 and 10000:\n");
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}