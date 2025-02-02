#include <stdio.h>

void classifyHurricane(double windSpeed) {
    int category;
    
    printf("Wind Speed: %.2f mph\n", windSpeed);
    
    // Determine category based on wind speed
    if (windSpeed >= 157) category = 5;
    else if (windSpeed >= 130) category = 4;
    else if (windSpeed >= 111) category = 3;
    else if (windSpeed >= 96) category = 2;
    else if (windSpeed >= 74) category = 1;
    else category = 0;
    
    // Use switch to attribute correct reading based on category
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
    printf("----------------------------------------\n");
}

int main() {
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

    return 0;
}