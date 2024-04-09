#include <stdio.h>
#include <string.h>

void charWithAnd(char c) {
    int mat[8];
    int j=0;
    int decimal = 0, i, power = 1;
    for (int i = 7; i >= 0; --i) {
        mat[j]=((c >> i) & 1)&127;
        j++;
    }
    for (i = 7; i >= 0; i--) {
        decimal += mat[i] * power;
        power *= 2;
    }
    char d=decimal;
    printf("%c",d);
}
void charWithXor(char c) {
    int mat[8];
    int j=0;
    int decimal = 0, i, power = 1;
    for (int i = 7; i >= 0; --i) {
        mat[j]=((c >> i) & 1)^127;
        j++;
    }
    for (i = 7; i >= 0; i--) {
        decimal += mat[i] * power;
        power *= 2;
    }
    char d=decimal;
    printf("%c",d);
}

int main() {
    char *str = "HELLO WORLD";
    printf("Original string: %s\n", str);
    printf("Result after AND with 127: ");

    for (int i = 0; i < strlen(str); ++i) {
        charWithAnd(str[i]);
    }
    printf("\nResult after XOR with 127: ");
    for (int i = 0; i < strlen(str); ++i) {
        charWithXor(str[i]);
    }
    return 0;
}