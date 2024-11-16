#include <stdio.h>
#include <string.h>

int ascii(char *transaction) {
    int i, ascii = 0;
    for (i = 0; i < strlen(transaction); i++) {
        ascii += (int)transaction[i];
    }
    return ascii;
}

int main() {
    int n, i, j;
    printf("enter number of transactions you want to enter: ");
    scanf("%d", &n);
    char transactions[n][30];
    int skip[n]; 

    for (i = 0; i < n; i++) {
        printf("enter transaction number %d: ", i + 1);
        scanf("%s", transactions[i]);
        skip[i] = 0; 
    }
    printf("[");
    for (i = 0; i < n; i++) {
        if (skip[i] == 0) { 
            printf("['%s',", transactions[i]);
            for (j = i + 1; j < n; j++) {
                if (ascii(transactions[i]) == ascii(transactions[j]) && skip[j] == 0) {
                    printf("'%s',", transactions[j]);
                    skip[j] = 1; 
                }
            }
            printf("],");
        }
    }
    printf("]");
    return 0;
}
