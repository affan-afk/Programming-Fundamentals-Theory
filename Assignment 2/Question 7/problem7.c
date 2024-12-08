#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void fillgrid(char grid[6][5]) {
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = 'A' + rand() % 26;
        }
    }
    strcpy(grid[5],"0579");
    grid[5][4] = 'A' + rand() % 26;
}
void printgrid(char grid[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int search(char grid[6][5], const char *searchstr) {
    int len = strlen(searchstr);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (grid[i][j + k] != searchstr[k]) {
                    found = 0;
                    break;
                }
            }
            if (found == 1 ){
              return 1;  
            } 
        }
    }

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i <= 6 - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (grid[i + k][j] != searchstr[k]) {
                    found = 0;
                    break;
                }
            }
            if (found == 1){
             return 1;
             }
        }
    }

    return 0;
}

int main() {
    char grid[6][5];
    int score = 0;
    char searchstr[100];
    fillgrid(grid);
    while (1) {

        printgrid(grid);
        printf("Search Str= ");
        fgets(searchstr, sizeof(searchstr), stdin);
        searchstr[strcspn(searchstr, "\n")] = 0;
        if (strcmp(searchstr, "END") == 0) {
            break;
        }
        if (search(grid, searchstr) == 1) {
            score += 1;
            printf("\n%s is present, Score: %d\n\n", searchstr, score);
        } else {
            score -= 1;
            printf("\n%s is not present, Score: %d\n\n", searchstr, score);
        }
    }
    fillgrid(grid);
    return 0;
}
