#include <stdio.h>

// Function to determine hurricane category based on wind speed
int determineCategory(double windSpeed) {
    if (windSpeed >= 157) return 5;
    else if (windSpeed >= 130) return 4;
    else if (windSpeed >= 111) return 3;
    else if (windSpeed >= 96) return 2;
    else if (windSpeed >= 74) return 1;
    else return 0;
}

// Function to get category description
void getCategoryDescription(int category) {
    switch (category) {
        case 5:
            printf("Category Five Hurricane\n");
            break;
        case 4:
            printf("Category Four Hurricane\n");
            break;
        case 3:
            printf("Category Three Hurricane\n");
            break;
        case 2:
            printf("Category Two Hurricane\n");
            break;
        case 1:
            printf("Category One Hurricane\n");
            break;
        case 0:
            printf("Not a Hurricane\n");
            break;
        default:
            printf("Error in classification\n");
    }
}

// Function to classify and display hurricane information
void classifyHurricane(double windSpeed) {
    printf("Wind Speed: %.2f mph\n", windSpeed);
    int category = determineCategory(windSpeed);
    getCategoryDescription(category);
    printf("----------------------------------------\n");
}

// Function to run all test cases
void runTestCases() {
    // Test Case 1
    printf("\nTest Case 1:\n");
    classifyHurricane(152);

    // Test Case 2
    printf("\nTest Case 2:\n");
    classifyHurricane(97.913);

    // Test Case 3
    printf("\nTest Case 3:\n");
    classifyHurricane(70.55);

    // Test Case 4
    printf("\nTest Case 4:\n");
    classifyHurricane(175.99);
}

int main() {
    runTestCases();
    return 0;
}