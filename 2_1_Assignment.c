#include <stdio.h>
#include <string.h>

#define MAX_CHARS 140

void checkMessage(const char* message) {
    int length = strlen(message);
    
    printf("Message: %s\n", message);
    printf("Length: %d\n", length);
    
    if (length <= MAX_CHARS) {
        printf("Result: Posted\n");
    } else {
        printf("Result: Rejected\n");
    }
    printf("----------------------------------------\n");
}

int main() {
    // Test Case 1
    printf("\nTest Case 1:\n");
    checkMessage("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

    // Test Case 2
    printf("\nTest Case 2:\n");
    checkMessage("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Id semper risus in hendrerit. Viverra mauris in aliquam sem. Arcu felis bibendum ut tristique et egestas quis. Pretium fusce id velit ut tortor pretium viverra suspendisse. Arcu cursus vitae congue mauris rhoncus aenean vel elit. In nisl nisi scelerisque eu ultrices. Mattis enim ut tellus elementum sagittis vitae et leo duis. In massa tempor nec feugiat. Feugiat nibh sed pulvinar proin. Elit ullamcorper dignissim cras tincidunt lobortis feugiat vivamus at. Scelerisque eu ultrices vitae auctor eu augue ut. Ac turpis egestas integer eget aliquet nibh praesent tristique. Viverra suspendisse potenti nullam ac tortor. Tortor id aliquet lectus proin. Dictum non consectetur a erat nam at lectus urna duis. Dui vivamus arcu felis bibendum ut tristique et egestas.");

    // Test Case 3
    printf("\nTest Case 3:\n");
    checkMessage("Massa vitae tortor condimentum lacinia quis vel eros donec ac.");

    // Test Case 4
    printf("\nTest Case 4:\n");
    checkMessage("Platea dictumst quisque sagittis purus sit amet volutpat consequat mauris.");

    return 0;
}