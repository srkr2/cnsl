#include <stdio.h>
#include <string.h>

#define N 2
#define ALPHABET_SIZE 26

// Function to calculate determinant of a 2x2 matrix
int calculateDeterminant(int mat[N][N]) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

// Function to calculate multiplicative inverse of a number modulo m
int multiplicativeInverse(int num, int m) {
    num = (num % m + m) % m; // Ensure num is within range of m
    for (int x = 1; x < m; x++)
        if ((num * x) % m == 1)
            return x;
    return -1; // No multiplicative inverse exists
}

int main() {
    char message[100];
    int key[N][N] = {{7, 8}, {11, 11}};//HILL;
    int inverse[N][N];
    int det = calculateDeterminant(key);
    int detInv = multiplicativeInverse(det, ALPHABET_SIZE);
    
    // Check if the determinant is invertible
    if (detInv == -1) {
        printf("Key matrix is not invertible. Decryption not possible.\n");
        return 1;
    }
    
    // Calculate the inverse of the key matrix
    inverse[0][0] = key[1][1];
    inverse[0][1] = -key[0][1];
    inverse[1][0] = -key[1][0];
    inverse[1][1] = key[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            inverse[i][j] *= detInv;
            inverse[i][j] %= ALPHABET_SIZE;
            if (inverse[i][j] < 0)
                inverse[i][j] += ALPHABET_SIZE;
        }

    printf("Enter plaintext (uppercase letters only): ");
    scanf("%s", message);

    int len = strlen(message);
    int blocks = len / 2; // Number of blocks needed
    char padded_message[len + 1]; // +1 for null terminator
    strcpy(padded_message, message);

    // Append 'X' if plaintext length is not already a multiple of 2
    if (len % 2 != 0) {
        padded_message[len] = 'X';
        padded_message[len + 1] = '\0';
        blocks++; // Increment block count
    }

    printf("Encrypted Cipher Text: ");
    for (int i = 0; i < blocks; i++) {
        int block[N] = {padded_message[i * 2] - 'A', padded_message[i * 2 + 1] - 'A'};
        int result[N] = {0};
        
        // Matrix multiplication
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[j] += key[j][k] * block[k];
            }
            result[j] %= ALPHABET_SIZE;
        }
        // Print encrypted characters
        for (int j = 0; j < N; j++) {
            printf("%c", result[j] + 'A');
        }
    }
    printf("\n");
    printf("Enter ciphertext (uppercase letters only): ");
    scanf("%s", message);

    len = strlen(message);
    blocks = len / 2; // Number of blocks

    printf("Decrypted Plain Text: ");
    for (int i = 0; i < blocks; i++) {
        int block[N] = {message[i * 2] - 'A', message[i * 2 + 1] - 'A'};
        int result[N] = {0};
        // Matrix multiplication with inverse key
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[j] += inverse[j][k] * block[k];
            }
            result[j] %= ALPHABET_SIZE;
            if (result[j] < 0)
                result[j] += ALPHABET_SIZE;
        }
        // Print decrypted characters
        for (int j = 0; j < N; j++) {
            printf("%c", result[j] + 'A');
        }
    }
    printf("\n");
    return 0;
}

