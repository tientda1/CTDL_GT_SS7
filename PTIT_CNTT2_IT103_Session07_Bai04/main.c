#include <stdio.h>
#include <string.h>

void softString(char *str) {
    int n = strlen(str);
    int i,j;
    char temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (str[j] > str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main(void) {
    char inputStr[100];
    printf("Enter string: ");
    fgets(inputStr, sizeof(inputStr), stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';
    softString(inputStr);
    printf("The string is: %s\n", inputStr);
    return 0;
}