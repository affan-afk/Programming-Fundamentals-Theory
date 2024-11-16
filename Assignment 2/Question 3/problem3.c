#include <stdio.h>
int main(){
    int n,i,j,removed;
    printf("enter number of words you want to enter: ");
    scanf("%d",&n);
    char words[n][30];
    char tmp[30];
    for (i = 0; i < n; i++)
    {
        printf("enter word number %d: ",i+1);\
        scanf(&words[i]);
    }
    
    for (j = 0; j < n; j++)
    {
        removed = 0;
        for (j = 1; j < 30; j++)
        {
            if (words[i][j] = '\0' )
            {
                break;
            }
            else if(words[i][j] != words[i][j+1]){
                strcat(tmp,words[i][j]);
            }
            else
            {
                removed++;
            }
        }
        strcpy(words[i],tmp);
        printf("the  compressed word number %d is %s and the removed characters are %d\n",i+1,words[i],removed);   
    }
    
   
}