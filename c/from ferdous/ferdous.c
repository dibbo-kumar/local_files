#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char playerName[50];
    int playerNumber;
    char playerPosition[10];
    int goalsScored;
    int goalsConceded;
    int minutes_played;
};

struct Team
{
    char teamName[50];
    struct Player players[20];
    int numPlayers;
};

void loadTeamsFromFile(struct Team teams[], int *numTeams)
{
    FILE *file = fopen("teams.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(file, "%s", teams[*numTeams].teamName) != EOF)
    {
        fscanf(file, "%d", &teams[*numTeams].numPlayers);
        for (int i = 0; i < teams[*numTeams].numPlayers; i++)
        {
            struct Player p;
            fscanf(file, "%s %d %s %d %d %d", p.playerName, &p.playerNumber, p.playerPosition,
                   &p.goalsScored, &p.goalsConceded, &p.minutes_played);
            teams[*numTeams].players[i] = p;
        }
        (*numTeams)++;
    }
    fclose(file);
}

void saveTeamsToFile(struct Team teams[], int numTeams)
{
    FILE *file = fopen("teams.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
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
}

void addPlayerToTeam(struct Team *team, struct Player player)
{
    if (team->numPlayers < 20)
    {
        team->players[team->numPlayers] = player;
        team->numPlayers++;
        printf("Player has been added succesfully.\n");
    }
    else
    {
        printf("Team is full. Cannot add more players.\n");
    }
}

void displayTeam(struct Team team)
{
    printf("\nTeam Name: %s\n", team.teamName);
    printf("Number of Players: %d\n", team.numPlayers);
    printf("Players:\n");
    for (int i = 0; i < team.numPlayers; i++)
    {
        printf("\nPlayer Name: %s\n Number: %d\n Position: %s\n Goals Scored: %d\n Goals Conceded: %d\n Minutes Played: %d\n",
               team.players[i].playerName, team.players[i].playerNumber, team.players[i].playerPosition,
               team.players[i].goalsScored, team.players[i].goalsConceded, team.players[i].minutes_played);
    }
}

void displayStatistics(struct Team teams[], int numTeams)
{
    int maxScored = 0;
    int maxConceded = 0;
    int maxMinutes = 0;
    char pWithMaxMinutes[50];
    char teamWithMaxConceded[50];

    for (int i = 0; i < numTeams; i++)
    {
        for (int j = 0; j < teams[i].numPlayers; j++)
        {
            if (teams[i].players[j].goalsScored > maxScored)
            {
                maxScored = teams[i].players[j].goalsScored;
            }
            if (teams[i].players[j].minutes_played > maxMinutes)
            {
                maxMinutes = teams[i].players[j].minutes_played;
                strcpy(pWithMaxMinutes, teams[i].players[j].playerName);
            }
        }

        int totalConceded = 0;
        for (int j = 0; j < teams[i].numPlayers; j++)
        {
            totalConceded += teams[i].players[j].goalsConceded;
        }
        if (totalConceded > maxConceded)
        {
            maxConceded = totalConceded;
            strcpy(teamWithMaxConceded, teams[i].teamName);
        }
    }

    printf("\nMost goals scored: %d\n", maxScored);
    printf("Most goals conceded by a team: %d \nTeam: %s\n", maxConceded, teamWithMaxConceded);
    printf("Most minutes played by a player: %d \nPlayer: %s\n", maxMinutes, pWithMaxMinutes);

    FILE *file = fopen("statistics.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(file, "Most goals scored: %d\n", maxScored);
    fprintf(file, "Most goals conceded by a team: %d \nTeam: %s\n", maxConceded, teamWithMaxConceded);
    fprintf(file, "Most minutes played by a player: %d \nPlayer: %s\n", maxMinutes, pWithMaxMinutes);
    fclose(file);
}

int main()
{
    struct Team footballTeams[100];
    int numTeams = 0;
    loadTeamsFromFile(footballTeams, &numTeams);

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
            int nT;
            struct Player newPlayer;
            printf("Enter which team:");
            scanf("%d", &nT);
            printf("Enter player name: ");
            scanf("%s", newPlayer.playerName);
            printf("Enter player number: ");
            scanf("%d", &newPlayer.playerNumber);
            printf("Enter player position: ");
            scanf("%s", newPlayer.playerPosition);
            printf("Enter goals scored: ");
            scanf("%d", &newPlayer.goalsScored);
            printf("Enter goals conceded: ");
            scanf("%d", &newPlayer.goalsConceded);
            printf("Enter minutes played: ");
            scanf("%d", &newPlayer.minutes_played);
            addPlayerToTeam(&footballTeams[nT - 1], newPlayer);
            break;
        }
        case 2:
        {
            int n;
            printf("Enter which team:");
            scanf("%d", &n);
            displayTeam(footballTeams[n - 1]);
            break;
        }
        case 3:
            displayStatistics(&footballTeams, numTeams);
            break;
        case 4:
            saveTeamsToFile(&footballTeams, numTeams);
            break;
        case 5:
            printf("Thanks for using our System!!!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            exit(1);
        }
    }
    return 0;
}