#include <stdio.h>
#include <string.h>

int main() {
    int repeated[128] = {0},i;
    char slogan[100],character;
    printf("enter slogan: ");
    fgets(slogan,100,stdin);
    slogan[strcspn(slogan, "\n")] = '\0';
    for(i=0; i<strlen(slogan);i++){
        character = slogan[i];
        repeated[(int)character] += 1;
    }
    printf("for \"%s\" {",slogan);
    for(i = 0;i < 128;i++){
        if (repeated[i] > 0){
            printf("'%c':%d,",i,repeated[i]);
    }
    }
    printf("}");
}