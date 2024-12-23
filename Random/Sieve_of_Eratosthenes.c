#include <stdio.h>
void sieve_of_eratosthenes(int n){
    int prime[n];
    int i = 0;
    while (i < n)
    {
        prime[i] = i;
        i += 1;
    }
    i=2;
    while(i < n){
        if (prime[i] != 0){
            int x = 2;
            while(x*i < n){
                prime[x*i] = 0;
                x += 1;
            }
        }
        i += 1;
    }
    i = 2;
    while (i < n)
    {
        if (prime[i]!=0){
         printf("%d\n",prime[i]);   
        }
        i += 1;
    }
}    
    int main(){
	int x;
	printf("Enter a number upto which you want to print prime numbers : ");
	scanf("%d",&x);
        sieve_of_eratosthenes(x);
    }
