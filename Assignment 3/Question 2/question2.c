#include <stdio.h>
#include <string.h>
struct Player
{
  int ballScores[12];
  char playername[30];
  int totalScore;
};
int validateScore(int score){
    if (score >=0 && score <= 6) return 1;
    else return 0;
}
void playGame(struct Player *player){
    printf("for player %s:\n",player->playername);
    player->totalScore = 0;
    for (int i = 0; i < 12; i++)
    {
        printf("Enter score for ball %d: ",i+1);
        scanf("%d",&(player->ballScores[i]));
        if (!validateScore(player->ballScores[i]))
        {
            player->ballScores[i] = 0;
        }
        player->totalScore += player->ballScores[i];
    }
    while (getchar() != '\n');
}
void findWinner(struct Player *player1,struct Player *player2){
    if (player1->totalScore > player2->totalScore)
    {
        printf("Player %s is the winner with total score %d.",player1->playername,player1->totalScore);
    }
    else if (player1->totalScore < player2->totalScore)
    {
        printf("Player %s is the winner with total score %d",player2->playername,player2->totalScore);
    }
    else
    {
        printf("Game was tied between %s and %s with total score %d each.",player1->playername,player2->playername,player1->totalScore);
    }
}
void displayMatchScoreboard(struct Player *player1,struct Player *player2){
    for (int i = 0; i < 12; i++)
    {
        printf("\nBall %d Scores:\nPlayer %s: %d\t Player %s: %d",i+1,player1->playername,player1->ballScores[i],player2->playername,player2->ballScores[i]);
    }
    printf("\nPlayer %s:\ntotal score: %d\taverage score: %d",player1->playername,player1->totalScore,player1->totalScore/12);
    printf("\nPlayer %s:\ntotal score: %d\taverage score: %d",player2->playername,player2->totalScore,player2->totalScore/12);
}
int main(){
    struct Player player1,player2;
    printf("enter player 1 name: ");
    fgets(player1.playername,sizeof(player1.playername),stdin);
    player1.playername[strcspn(player1.playername,"\n")] = '\0';
    printf("\nenter player 2 name: ");
    fgets(player2.playername,sizeof(player2.playername),stdin);
    player2.playername[strcspn(player2.playername,"\n")] = '\0';
    playGame(&player1);
    playGame(&player2);
    findWinner(&player1,&player2);
    displayMatchScoreboard(&player1,&player2);
}