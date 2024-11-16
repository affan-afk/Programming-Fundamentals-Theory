#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    int removed;
    printf("Enter number of words you want to enter: ");
    scanf("%d", &n);
    char words[n][30];

    for (i = 0; i < n; i++) {
        printf("Enter word number %d: ", i + 1);
        scanf("%s", words[i]);
        int len = strlen(words[i]);
        int index = 0;
        removed = 0;
        for (j = 0; j < strlen(words[i]); j++) {
            if (j == 0 || words[i][j] != words[i][j - 1]) {
                words[i][index] = words[i][j];
                index+=1;
            }
            else{
                removed++;
            }
        }
        words[i][index] = '\0';

        printf("The compressed word number %d is %s and the number of characters removed are %d\n", i + 1, words[i],removed);
    }

    return 0;
}
