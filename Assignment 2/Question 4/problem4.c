#include <stdio.h>
#include <string.h>
int main(){
    int n,i,j,x=0,y=0;
    printf("enter number of transactions you want to enter: ");
    scanf("%d",&n);
    char transaction[n][30];
    int anagrams[n][n][1]; //anagrams[group number][transactions k konse konse index print krwaane][1]
    for (i = 0; i < n; i++)
    {
        printf("enter transaction number %d: ",i);\
        scanf(&transaction[i]);
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (strcmp(transaction[i],transaction[j]) == 0)
            {
                anagrams[i][j][1] = j;
            }
        }
        
        
    }
    printf("[");
    for ( i = 0; i < n; i++)
    {
        printf("[");
        for ( j = 0; j < n; j++)
        {
            if (anagrams[i][j][1] == 0){
                break;
            }
            printf("'%s', ",transaction[anagrams[i][j][1]]);
        }
         printf("/b]");
    }
    printf("/b]");
}