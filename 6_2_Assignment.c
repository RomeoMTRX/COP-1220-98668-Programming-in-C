#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt text using Caesar cipher
void encrypt(char text[], int shift) {
    int i;
    char ch;
    
    // Ensure shift is handled correctly regardless of sign
    // For this implementation, I'm consistently SUBTRACTING the shift
    
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        
        // Encrypt uppercase letters
        if(isupper(ch)) {
            // Adjust position based on shift
            int newPos = ch - 'A';
            
            // Subtract the shift (this handles both positive and negative shifts)
            newPos = newPos - shift;
            
            // Ensure we wrap around correctly
            // Add 26 until positive, then take modulo 26
            while(newPos < 0)
                newPos += 26;
            newPos %= 26;
            
            text[i] = newPos + 'A';
        }
        // Encrypt lowercase letters
        else if(islower(ch)) {
            // Adjust position based on shift
            int newPos = ch - 'a';
            
            // Subtract the shift (this handles both positive and negative shifts)
            newPos = newPos - shift;
            
            // Ensure we wrap around correctly
            // Add 26 until positive, then take modulo 26
            while(newPos < 0)
                newPos += 26;
            newPos %= 26;
            
            text[i] = newPos + 'a';
        }
        // Leave non-alphabetic characters unchanged
    }
}

int main() {
    char text[1000];
    int shift;
    
    printf("Enter text: ");
    // Use fgets instead of scanf to handle spaces
    fgets(text, sizeof(text), stdin);
    // Remove trailing newline
    text[strcspn(text, "\n")] = '\0';
    
    printf("Enter shift value: ");
    scanf("%d", &shift);
    
    // Store the original text
    char original[1000];
    strcpy(original, text);
    
    // Encrypt the text
    encrypt(text, shift);
    
    // Display the results
    printf("Text: %s\n", original);
    printf("Shift: %d\n", shift);
    printf("Cipher: %s\n", text);
    
    // Add a pause so output remains visible
    printf("\nPress Enter to exit...");
    getchar();
    getchar(); // Additional getchar to capture the Enter
    
    return 0;
}