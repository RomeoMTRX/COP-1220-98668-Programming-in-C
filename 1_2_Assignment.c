#include <stdio.h>

// Function to display lyrics with proper formatting
void displayLyrics(int testNumber, const char* line1, const char* line2, 
                  const char* line3, const char* line4) {
    printf("Unit Test #%d Output:\n", testNumber);
    printf("%s\n", line1);
    printf("%s\n", line2);
    printf("%s\n", line3);
    printf("%s\n", line4);
    printf("\n");  // Add blank line between tests
}

int main() {
    // Unit Test #1
    displayLyrics(1,
        "Oh, well imagine",
        "As I'm pacing the pews in a church corridor",
        "And I can't help but to hear",
        "No, I can't help but to hear an exchanging of words...");
    
    // Unit Test #2
    displayLyrics(2,
        "Oh-oh-oh-oh-oh,",
        "oh-oh-oh-oh,",
        "oh-oh-oh",
        "Caught in a bad romance...");
    
    // Unit Test #3
    displayLyrics(3,
        "Coming out of my cage",
        "And I've been doing just fine",
        "Gotta gotta be down",
        "Because I want it all");
    
    // Unit Test #4
    displayLyrics(4,
        "Now, this is a story all about how",
        "My life got flipped-turned upside down",
        "And I'd like to take a minute",
        "Just sit right there");
    
    return 0;
}