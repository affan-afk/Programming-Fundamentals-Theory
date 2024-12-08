#include <stdio.h>
#include <stdlib.h>
void displaygrid(char grid[5][5]) {

    printf("\nCurrent Grid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[5][5] = { 
        {' ', ' ', 'I', 'X', ' '}, 
        {' ', 'X', ' ', ' ', ' '}, 
        {'I', ' ', 'X', 'X', ' '}, 
        {' ', ' ', ' ', 'I', 'X'}, 
        {'P', 'X', ' ', ' ', ' '} 
    };

    int playerX = 4, playerY = 0;  
    int itemsCollected = 0;  
    char move;
    while (1) {
        displaygrid(grid);
        printf("\nItems Collected: %d\n", itemsCollected);
        printf("Use WASD to move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);  
        switch (move) {
            case 'W':  
                if (playerX > 0 && grid[playerX - 1][playerY] != 'X') {
                    if (grid[playerX - 1][playerY] == 'I') {
                        itemsCollected++;
                    }
                    grid[playerX][playerY] = ' ';  
                    playerX--;
                    grid[playerX][playerY] = 'P';  
                } else {
                    printf("Invalid move! Cannot go up.\n");
                }
                break;

            case 'S':  
                if (playerX < 5 - 1 && grid[playerX + 1][playerY] != 'X') {
                    if (grid[playerX + 1][playerY] == 'I') {
                        itemsCollected++;
                    }
                    grid[playerX][playerY] = ' '; 
                    playerX++;
                    grid[playerX][playerY] = 'P';  
                } else {
                    printf("Invalid move! Cannot go down.\n");
                }
                break;

            case 'A':  
                if (playerY > 0 && grid[playerX][playerY - 1] != 'X') {
                    if (grid[playerX][playerY - 1] == 'I') {
                        itemsCollected++;
                    }
                    grid[playerX][playerY] = ' ';  
                    playerY--;
                    grid[playerX][playerY] = 'P';  
                } else {
                    printf("Invalid move! Cannot go left.\n");
                }
                break;

            case 'D':  
                if (playerY < 5 - 1 && grid[playerX][playerY + 1] != 'X') {
                    if (grid[playerX][playerY + 1] == 'I') {
                        itemsCollected++;
                    }
                    grid[playerX][playerY] = ' '; 
                    playerY++;
                    grid[playerX][playerY] = 'P';  
                } else {
                    printf("Invalid move! Cannot go right.\n");
                }
                break;

            case 'Q':   
                return 0;

            default:
                printf("Invalid input! Please use W, A, S, D, or Q.\n");
                break;
        }
    }

    return 0;
}
