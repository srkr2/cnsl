#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char text[100],key[100];
    int i,a;
    printf("enter plain text :");
    scanf("%s",text);
    
    printf("Enter the key:");
    scanf("%s",key);

    for(i=0;i<strlen(text);i++){
        a=i%strlen(key);
        text[i]= (((text[i]-'A') + (key[a]-'A'))%26)+'A';
    }
    printf("\nEncrypted text:%s",text);
    
    for(i=0;i<strlen(text);i++){
        a=i%strlen(key);
        text[i]= ((((text[i]-'A') - (key[a]-'A'))+26)%26)+'A';
    }
    printf("\nDecrypted text: %s",text);
    return 0;
}

