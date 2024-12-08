#include <stdio.h>
#include <string.h>
struct Employee {
    int code;
    char name[100];
    char d_join[11]; 
};

void input(struct Employee *emp) {
    printf("Enter employee code: ");
    scanf("%d", &((*emp).code));
    getchar(); 

    printf("Enter employee name: ");
    fgets((*emp).name, 100, stdin);
    (*emp).name[strcspn((*emp).name, "\n")] = '\0'; 

    printf("Enter date of joining (DD-MM-YYYY): ");
    fgets((*emp).d_join, 11, stdin);
    (*emp).d_join[strcspn((*emp).d_join, "\n")] = '\0'; 
}
void checktenure(struct Employee employees[], int size) {
    int c_year = 2024;
    int c_month = 11;  
    int c_day = 27;
    int count = 0; 
    for (int i = 0; i < size; i++) {
        int joinYear, joinMonth, joinDay;
        sscanf(employees[i].d_join, "%d-%d-%d",&joinDay,&joinMonth, &joinYear);
        int tenure = c_year - joinYear;
        if (c_month < joinMonth || (c_month == joinMonth && c_day < joinDay)) {
            tenure--;
        }
        if (tenure > 3) {
            printf("\nEmployee Code: %d\n", employees[i].code);
            printf("Employee Name: %s\n", employees[i].name);
            printf("Date of Joining: %s\n", employees[i].d_join);
            printf("Tenure: %d years\n", tenure);
            count++;
        }
    }

    printf("\nNumber of employees with more than 3 years of tenure: %d\n", count);
}

int main() {
    struct Employee employees[4]; 
    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for employee %d\n", i + 1);
        input(&employees[i]);
    }
    checktenure(employees, 4);

    return 0;
}
