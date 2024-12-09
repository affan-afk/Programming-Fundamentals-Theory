#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{   
    int *ratings;
    int totalscore;
}employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods){
    printf("\n");
    for (int i = 0; i < numEmployees; i++)
    {
        for (int j = 0; j < numPeriods; j++)
        {
            printf("For employee %d enter rating (1-10) for evaluation period %d: ",i+1,j+1);
            scanf("%d",&ratings[i][j]);
            while ((ratings[i][j] < 1 && ratings[i][j] > 10))
            {
                printf("error! rating should be from 1-10 inclusive: ");
                scanf("%d",&ratings[i][j]);
            }
            
            printf("\n");
        }
        printf("\n");
    }
} 
void displayPerformance(int** ratings, int numEmployees, int numPeriods){
    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nFor employee %d:\nrating for evaluation period(s):\n",i+1);
        for (int j = 0; j < numPeriods; j++)
        {
            printf("%d: %d\n",j+1,ratings[i][j]);
        }
    }
}
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
    int highest_rating = ratings[0][0], tmp = 0,highest_rated = 0; //average directly sum of ratings se nikal jayega cuz for each employee the number of periods is same!
    for (int i = 0; i < numEmployees; i++)
    {
        for (int j = 0; j < numPeriods; j++)
        {
            tmp += ratings[i][j];
        }
        tmp = tmp/numPeriods;
        if (highest_rating < tmp) {
            highest_rating = tmp;
            highest_rated = i;
        }
        tmp = 0;
    }
    return highest_rated + 1;
}
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
      int highest_rating = ratings[0][0], tmp = 0, highest_rated = 0;
    for (int i = 0; i < numPeriods ; i++)
    {
        for (int j = 0; j < numEmployees; j++)
        {
            tmp += ratings[j][i];
        }
        if (highest_rating < tmp) {
            highest_rating = tmp;
            highest_rated = i;
        }
        tmp = 0;
    }
    return highest_rated + 1;
}  

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
    int lowest_rating =ratings[0][0],tmp = 0, lowest_rated = 0;
    for (int i = 0; i < numEmployees; i++)
    {
        for (int j = 0; j < numPeriods; j++)
        {
            tmp += ratings[i][j];
        }
        tmp = tmp/numPeriods;
        if (lowest_rating > tmp) {
            lowest_rating = tmp;
            lowest_rated = i;
        }
        tmp = 0;
    }
    return lowest_rated + 1;
}
int main(){
    int e,n;
    printf("enter num of employees: ");
    scanf("%d",&e);
    printf("\nenter num of evaluation period(s) for each employee: ");
    scanf("%d",&n);
    int** ratings = malloc(sizeof(int*)*e);
    for (int i = 0; i < e; i++){
        ratings[i] = malloc(sizeof(int)*n);
    }
    
    inputEmployees(ratings, e, n);
    displayPerformance(ratings, e, n);

    printf("\nEmployee %d was Employee of the Year\n",findEmployeeOfTheYear(ratings, e,n));

    printf("\nPeriod %d was the Highest Rated\n",findHighestRatedPeriod(ratings, e, n));

    printf("\nEmployee %d had the Worst Average Rating\n",findWorstPerformingEmployee(ratings, e, n));

    for (int i = 0; i < e; i++){
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
