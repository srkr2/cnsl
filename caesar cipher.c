#include <stdio.h>
#include <string.h>

int main() {
    char str[] ="Hello world";
    char str1[strlen(str)];
    char str2[strlen(str)];
    
    for (int i = 0; str[i] != '\0'; i++) {
        str1[i] = str[i]+3;
    }
    printf("Result after encryption: %s\n", str1);
    for (int i = 0; str1[i] !='\0'; i++) 
    {
        str2[i] = str1[i]-3;
    }
    printf("Result after decryption: %s\n", str2);
    return 0;
}

