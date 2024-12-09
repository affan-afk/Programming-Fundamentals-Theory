#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int validateEmail(char* email){
    int count = 0;
    if (strlen(email) == 0 || email[0] == '\n') return 0;
    if (strcspn(email,".") < strcspn(email,"@")) return 0;
    if (!strchr(email,'@') || !strchr(email,'.')) return 0;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            count++;
            if (count > 1)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    char buffer[320]; // got this length off of google :P
    printf("Enter email address: ");
    fgets(buffer,sizeof(buffer),stdin);
    if (strlen(buffer) > 1) buffer[strcspn(buffer,"\n")] = '\0';
    char *email = malloc(sizeof(char)*strlen(buffer)+1);
    strcpy(email,buffer);
    if (validateEmail(email))
    {
        printf("Valid Email");
    }
    else{
        printf("Invalid Email");
    }
    free(email);
}