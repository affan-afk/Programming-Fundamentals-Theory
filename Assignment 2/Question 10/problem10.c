#include<stdio.h>

int main(){
    int gap , number = 0;
    int in_gap , star , x , y , z;
    do{
    printf("Enter any number greater than 2: ");
    scanf("%d", &number);
    }while(number < 3);
    gap = (number*2)-2;
    in_gap = 0;
    for(x = 0; x <  number-1; x++){
        for(y = 0; y < gap; y++){
            printf(" ");
        }
        printf("*");
        for(z = 0; z < in_gap; z++){
            printf(" ");
        }
        if(z != 0)
            printf("*");
        printf("\n");
        gap--;
        if(x == 0)
            in_gap++;
        else
            in_gap+=2;
    }
    for(x = 0 ;  x < number; x++){
        printf("*");
    }
    for(x = 0;  x < in_gap; x++){
        printf(" ");
    }
    for(x = 0 ;  x < number; x++){
        printf("*");
    }
    printf("\n");
    in_gap = (in_gap*2)-1;
    gap = 1;

    for(x = 0; x < number-1;  x++){
        for(y = 0; y  < gap; y++){
            printf(" ");
        }
        printf("*");
        for(z = 0 ; z < in_gap; z++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        in_gap-=2;
        gap++;
    }
    gap = number-2;
    in_gap = 1;
    for(x = 0; x < number-2; x++){
        for(y = 0; y < gap; y++){
            printf(" ");
        }
        printf("*");
        for(z = 0; z < gap; z++){
            printf(" ");
        }
        printf("*");
        for(y = 0;  y < in_gap; y++){
            printf(" ");
        }
        printf("*");
        for( y = 0; y < gap; y++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        gap --;
        in_gap+=4;

    }
    in_gap+=2;
    printf("*");
    for(y = 0; y < in_gap; y++){
        printf(" ");
    }
    printf("*");
    return 0;
}
