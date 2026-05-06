#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct player
{
    char playerName[50];
    int playerNumber;
    char playerPosition[10];
    int goalsScored;
    int goalsConceded;
    int minutes_played;
} Player;
typedef struct team
{
    char teamName[50];
    Player players[20];
    int numPlayers;
} Team;
void loadTeamsFromFile(Team teams[], int *numTeams)
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("file not opened.\n");
        return;
    }
    while (fscanf(file, "%s", teams[*numTeams].teamName) != EOF)
    {
        fscanf(file, "%d", &teams[*numTeams].numPlayers);
        for (int i = 0; i < teams[*numTeams].numPlayers; i++)
        {
            Player plr;
            fscanf(file, "%s %d %s %d %d %d", plr.playerName, &plr.playerNumber, plr.playerPosition,
                   &plr.goalsScored, &plr.goalsConceded, &plr.minutes_played);
            teams[*numTeams].players[i] = plr;
        }
        (*numTeams)++;
    }
    fclose(file);
}
void saveTeamsToFile(Team teams[], int numTeams)
{
    FILE *file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("File not opened.\n");
        return;
    }
    for (int i = 0; i < numTeams; i++)
    {
        fprintf(file, "%s\n", teams[i].teamName);
        fprintf(file, "%d\n", teams[i].numPlayers);
        for (int j = 0; j < teams[i].numPlayers; j++)
        {
            fprintf(file, "%s %d %s %d %d %d\n", teams[i].players[j].playerName, teams[i].players[j].playerNumber,
                    teams[i].players[j].playerPosition, teams[i].players[j].goalsScored,
                    teams[i].players[j].goalsConceded, teams[i].players[j].minutes_played);
        }
    }
    fclose(file);
    printf("File saved.\n");
}
void addPlayerToTeam(Team *team, Player player)
{
    if (team ->numPlayers < 20)
    {
        team -> players[team->numPlayers] = player;
        team->numPlayers++;
        printf("Player added.\n");
    }
    else
    {
        printf("Team is full.\n");
    }
}
void displayTeam(Team team)
{
    printf("\n\nTeam Name: %s\n", team.teamName);
    printf("Number of Players: %d\n", team.numPlayers);
    printf("Players:\n");
    for (int i = 0; i < team.numPlayers; i++)
    {
        printf("\nPlayer Name: %s\n Number: %d\n Position: %s\n Total Goals Scored: %d\n Total Goals Conceded: %d\n Total Minutes Played: %d\n",
               team.players[i].playerName, team.players[i].playerNumber, team.players[i].playerPosition,
               team.players[i].goalsScored, team.players[i].goalsConceded, team.players[i].minutes_played);
    }
}
void displayStatistics(Team teams[], int numTeams)
{
    int maxscore = 0;
    int maxconced = 0;
    int maxMinutes = 0;
    char pMaxMinutes[90];
    char tMaxConceded[50];
    int tconced = 0;

    for (int i = 0; i < numTeams; i++)
    {
        for (int j = 0; j < teams[i].numPlayers; j++)
        {
            if (teams[i].players[j].goalsScored > maxscore)
            {
                maxscore = teams[i].players[j].goalsScored;
            }
            if (teams[i].players[j].minutes_played > maxMinutes)
            {
                maxMinutes = teams[i].players[j].minutes_played;
                strcpy(pMaxMinutes, teams[i].players[j].playerName);
            }
        }


        for (int j = 0; j < teams[i].numPlayers; j++)
        {
            tconced += teams[i].players[j].goalsConceded;
        }
        if (tconced > maxconced)
        {
            maxconced = tconced;
            strcpy(tMaxConceded, teams[i].teamName);
        }
    }
    printf("\nMost scored: %d\n", maxscore);
    printf("Most goal conceded by a team: %d , and Team name: %s\n", maxconced, tMaxConceded);
    printf("Most minutes played by a player: %d , and Player name: %s\n", maxMinutes, pMaxMinutes);
}
int main()
{
    Team fTeam[100];
    int numTeams = 0;
    loadTeamsFromFile(fTeam, &numTeams);
    int choice;
    while (1)
    {
        printf("----------------------------------------------------------------------\n");
        printf("----------Welcome to Football Management System (FMS)-----------------\n");
        printf("----------------------------------------------------------------------\n\n");
        printf("Menu:\n1.Add a player\n2.Display Team information\n3.Show Statistics\n4.Save Teams\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int newteam;
            Player newp;
            printf("Enter which team,  player name , player number, player position, goal scored, goal conceded, how many time played :\n");
            scanf("%d %s %d %s %d %d %d", &newteam, newp.playerName, &newp.playerNumber, newp.playerPosition, &newp.goalsScored, &newp.goalsConceded, &newp.minutes_played);
            addPlayerToTeam(&fTeam[newteam - 1], newp);
            break;
        }
        case 2:
        {
            int n;
            printf("Enter team serial number :");
            scanf("%d", &n);
            displayTeam(fTeam[n - 1]);
            break;
        }
        case 3:
            displayStatistics(&fTeam, numTeams);
            break;
        case 4:
            saveTeamsToFile(&fTeam, numTeams);
            break;
        case 5:
            printf("Thanks for using our System!\n");
            exit(0);
            break;
        default:
            printf("Error input .\n");
            break;
        }
    }
    return 0;
}
