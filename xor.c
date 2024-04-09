#include <stdio.h>
#include <string.h>

// Function to convert a character to its binary representation
void charToBinary(char c) {
    for (int i = 7; i >= 0; --i) {
        printf("%d", (c >> i) & 1); // Extracting each bit of the character
    }
}
int main() {
    const char *str = "Hello world";
    printf("Original string: %s\n", str);
    printf("Result after XOR with 0: ");
    for (int i = 0; i < strlen(str); ++i) {
        // Convert the character to its binary representation
        charToBinary(str[i]);
        printf(" XOR 0= ");
        char result = str[i] ^ 0;
        printf("%c ", result);
        printf("\n");
    }
    return 0;
}

