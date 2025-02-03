#include <stdio.h>
#include <stdlib.h>

int main() {
    double dTotal = 0, eTotal = 0, fTotal = 0;
    char choice;
    double amount;

    printf("Holiday Homes Sales Tracker\n");
    printf("---------------------------\n");

    while(1) {
        printf("\nEnter salesperson (D, E, F) or Z to finish: ");
        scanf(" %c", &choice);

        if(choice == 'Z' || choice == 'z') {
            break;
        }

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

    double grandTotal = dTotal + eTotal + fTotal;
    char highest = 'D';

    if(eTotal > dTotal && eTotal > fTotal) {
        highest = 'E';
    } else if(fTotal > dTotal && fTotal > eTotal) {
        highest = 'F';
    }

    printf("\nResults:\n");
    printf("D Total: $%.2f\n", dTotal);
    printf("E Total: $%.2f\n", eTotal);
    printf("F Total: $%.2f\n", fTotal);
    printf("Grand Total: $%.2f\n", grandTotal);
    printf("Highest Sale: %c\n", highest);

    system("pause");
    return 0;
}