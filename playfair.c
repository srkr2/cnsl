#include <stdio.h>
#include <string.h>

#define SIZE 5


void generateMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int len = strlen(key);
    int row = 0, col = 0;

    for (int i = 0; i < len; i++) {
        if (key[i] != 'J') {
            if (!used[key[i] - 'A']) {
                matrix[row][col++] = key[i];
                used[key[i] - 'A'] = 1;
                if (col == SIZE) {
                    col = 0;
                    row++;
                }
            }
        }
    }

  
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch != 'J' && !used[ch - 'A']) {
            matrix[row][col++] = ch;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Treat 'J' as 'I'

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPair(char matrix[SIZE][SIZE], char a, char b) {
    int row1, col1, row2, col2;

    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);
        
    if (row1 == row2) {
        
        printf("%c%c ", matrix[row1][(col1 + 1) % SIZE], matrix[row2][(col2 + 1) % SIZE]);
    } else if (col1 == col2) {
       
        printf("%c%c ", matrix[(row1 + 1) % SIZE][col1], matrix[(row2 + 1) % SIZE][col2]);
    } else {
        
        printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
    }
}


void decryptPair(char matrix[SIZE][SIZE], char a, char b) {
    int row1, col1, row2, col2;

    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    if (row1 == row2) {
       
        printf("%c%c ", matrix[row1][(col1 - 1 + SIZE) % SIZE], matrix[row2][(col2 - 1 + SIZE) % SIZE]);
    } else if (col1 == col2) {
       
        printf("%c%c ", matrix[(row1 - 1 + SIZE) % SIZE][col1], matrix[(row2 - 1 + SIZE) % SIZE][col2]);
    } else {
       
        printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
    }
}

int main() {
    char key[100];
    char plaintext[100];
     char ciphertext[100];
    char matrix[SIZE][SIZE];

    // Prompt user for key and plaintext
    printf("Enter the key (uppercase letters only): ");
    scanf("%s", key);
printf("Enter the plaintext (uppercase letters only, no spaces): ");
    scanf("%s", plaintext);

  
    generateMatrix(key, matrix);

    // Encrypt plaintext
    printf("Encrypted Text: ");
    for (int i = 0; i < strlen(plaintext); i += 2) {
        if (plaintext[i] == plaintext[i + 1]) {
            encryptPair(matrix, plaintext[i], 'X');
           
            i--;
        } else {
            encryptPair(matrix, plaintext[i], plaintext[i + 1]);
        }
    }
    printf("\n");

printf("Enter the ciphertext (uppercase letters only, no spaces):");
    scanf("%s", ciphertext);

    // Decrypt ciphertext
     printf("Decrypted Text: ");
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        decryptPair(matrix, ciphertext[i], ciphertext[i + 1]);
    }
    printf("\n");
    
    return 0;
}

