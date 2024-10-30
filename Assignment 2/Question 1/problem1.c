#include <stdio.h>
int main(){
    int i, small, second_small, arr[5];
    for(i=0;i<5;i++){
        printf("enter a number: ");
        scanf("%d",&arr[i]);
    }
    small = 100000;
    second_small = 999999;
    for(i=0;i<5;i++){
        if (small > arr[i] )
        {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] < second_small && arr[i] != small) 
        {
            second_small = arr[i];
        }
    }
    
printf("\nsecond smallest element in array is: %d",second_small);
}