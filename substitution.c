#include <stdio.h>
#include <string.h>

int main() {
    char message[]="Hello world";
    char encryptionKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // Example key, you can modify this
    char decryptionKey[26];

    for (int i = 0; message[i] != '\0'; i++) {
        char current = message[i];
        if ('A' <= current && current <= 'Z') 
        {
            message[i] = encryptionKey[current - 'A'];
        } 
        else if ('a' <= current && current <= 'z') 
        {
            message[i] = encryptionKey[current - 'a'] + 'a' - 'A';
        }
    }
    printf("Encrypted message: %s\n", message);

    // Decryption
    for (int i = 0; i < 26; i++) {
        decryptionKey[encryptionKey[i] - 'A'] = 'A' + i;
    }

    for (int i = 0; message[i] != '\0'; i++) {
        char current = message[i];
        if ('A' <= current && current <= 'Z') {
            message[i] = decryptionKey[current - 'A'];
        } else if ('a' <= current && current <= 'z') {
            message[i] = decryptionKey[current - 'a'] + 'a' - 'A';
        }
    }
    printf("Decrypted message: %s\n", message);

    return 0;
}

