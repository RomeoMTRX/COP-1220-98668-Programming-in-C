#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check if character is a vowel
int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char input[2000];
    char output[4000] = "";
    char word[100] = "";
    int i, j = 0;
    int outputIndex = 0;
    int firstVowel;
    
    printf("Enter text to translate to Pig Latin:\n");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline
    input[strcspn(input, "\n")] = 0;
    
    // Process each character
    for (i = 0; i <= strlen(input); i++) {
        // If end of word or end of input
        if (i == strlen(input) || input[i] == ' ' || (ispunct(input[i]) && input[i] != '\'')) {
            // Process word if not empty
            if (j > 0) {
                word[j] = '\0'; // Terminate word
                
                // Find first vowel
                firstVowel = 0;
                while (firstVowel < j && !isVowel(word[firstVowel])) {
                    firstVowel++;
                }
                
                // If word starts with vowel
                if (firstVowel == 0) {
                    // Add word + "yay" to output
                    strcpy(output + outputIndex, word);
                    outputIndex += j;
                    strcpy(output + outputIndex, "yay");
                    outputIndex += 3;
                } 
                // If word has no vowels
                else if (firstVowel == j) {
                    // Add word + "ay" to output
                    strcpy(output + outputIndex, word);
                    outputIndex += j;
                    strcpy(output + outputIndex, "ay");
                    outputIndex += 2;
                }
                // Word starts with consonants
                else {
                    // Add part after first vowel
                    strcpy(output + outputIndex, word + firstVowel);
                    outputIndex += (j - firstVowel);
                    
                    // Add consonants at the beginning
                    strncpy(output + outputIndex, word, firstVowel);
                    outputIndex += firstVowel;
                    
                    // Add "ay"
                    strcpy(output + outputIndex, "ay");
                    outputIndex += 2;
                }
                
                j = 0; // Reset word buffer
            }
            
            // Add space or punctuation to output
            if (i < strlen(input)) {
                output[outputIndex++] = input[i];
            }
        } 
        // Add character to current word
        else {
            word[j++] = input[i];
        }
    }
    
    // Ensure null termination
    output[outputIndex] = '\0';
    
    printf("Pig Latin translation:\n%s\n", output);
    
    // Add a pause to see the output
    printf("\nPress Enter to exit...");
    getchar();
    
    return 0;
}