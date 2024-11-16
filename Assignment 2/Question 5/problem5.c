#include <stdio.h>
void horizontal_histogram(int n, int numbers[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: ",numbers[i]);
        for (int j = 0; j < numbers[i]; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
     printf("\n");
}

void vertical_histogram( int n, int numbers[]) {
    int max_value = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        for (int i = max_value; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (numbers[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++)
        {
            printf("%d ",numbers[j]);
        }
    return;
}
    }
void input(int n){
    int i,numbers[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter value %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    horizontal_histogram(n,numbers);
    vertical_histogram(n,numbers);
}
int main()
{
    int n;
    printf("enter number of values you want to input: ");
    scanf("%d",&n);
    input(n);
}
