#include <stdio.h>

// Function to display personal information with each item on a new line
void displayPersonalInfo(const char* name, const char* birthdate, 
                        const char* workPhone, const char* cellPhone) {
    printf("%s\n%s\nwork %s\ncell %s\n", 
           name, birthdate, workPhone, cellPhone);
}

int main() {
    // Unit Test #1
    printf("Unit Test #1 Output:\n");
    displayPersonalInfo("Lucinda Potter", "6/24/1992", 
                       "000-000-0101", "000-000-0189");
    printf("\n");  // Extra line between tests
    
    // Unit Test #2
    printf("Unit Test #2 Output:\n");
    displayPersonalInfo("John Smith", "8/15/1978", 
                       "000-111-0101", "000-111-0189");
    printf("\n");
    
    // Unit Test #3
    printf("Unit Test #3 Output:\n");
    displayPersonalInfo("Chris Johnson", "12/01/1987", 
                       "000-222-0101", "000-222-0189");
    printf("\n");
    
    // Unit Test #4
    printf("Unit Test #4 Output:\n");
    displayPersonalInfo("Robert Hall", "2/27/1949", 
                       "000-444-0101", "000-444-0189");
    
    return 0;
}