#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player
{
    char player_name[50];
    int player_number;
    char player_position[10];
    int goals_scored;
    int goals_conceded;
    int number_of_minutes_played;
} Player;

typedef struct team
{
    char team_name[50];
    Player players[20];
    int num_players;
} Team;

void addPlayerToTeam(Team *team, Player player);
void displayPlayer(Player player);
void displayTeam(Team team);
void saveTeamsToFile(Team teams[], int num_teams);
void loadTeamsFromFile(Team teams[], int *num_teams);
void displayStatistics(Team teams[], int num_teams);

// int max_goals = 0;
// char max_team[50];
// int const max = 1000;
// int min_goals = max;
// char min_team[50];
// int main()
// {
//     int choice;
//     Team teams[10];
//     int num_teams = 0;
//     max_goals = 0;
//     strcpy(max_team, "");
//     min_goals = max;
//     strcpy(min_team, "");

//     loadTeamsFromFile(teams, &num_teams);

//     do
//     {
//         printf("\nFootball Database Management System\n");
//         printf("1. Add a player to a team\n");
//         printf("2. Display team information\n");
//         printf("3. View statistics\n");
//         printf("4. Save teams to file\n");
//         printf("5. End\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {

//         case 1:
//         {
//             char team_name[50];
//             Player player;
//             int teamIndex;
//             printf("Enter team name: ");
//             scanf("%s", team_name);

//             Team *team = NULL;
//             for (int i = 0; i < num_teams; i++)
//             {
//                 if (strcmp(teams[i].team_name, team_name) == 0)
//                 {
//                     team = &teams[i];
//                     teamIndex = i;
//                     break;
//                 }
//             }

//             if (team == NULL)
//             {
//                 printf("Team not found.\n");
//                 break;
//             }

//             printf("Enter player name: ");
//             scanf("%s", player.player_name);
//             printf("Enter player number: ");
//             scanf("%d", &player.player_number);
//             printf("Enter player position (FWD, MID, DEF): ");
//             scanf("%s", player.player_position);
//             if((strcmp(player.player_position,"FWD")==0)||(strcmp(player.player_position,"MID")==0))
//             {
//                 printf("Enter goals scored: ");
//                 scanf("%d", &player.goals_scored);
//             }
//             else
//             {
//                 printf("Enter goals conceded: ");
//                 scanf("%d", &player.goals_conceded);
//             }
//             printf("Enter minutes played: ");
//             scanf("%d", &player.number_of_minutes_played);

//             addPlayerToTeam(team, player);
//            // updateStats(teams, num_teams);
//             break;
//         }
//         case 2:
//         {
//             char team_name[50];
//             printf("Enter team name: ");
//             scanf("%s", team_name);

//             for (int i = 0; i < num_teams; i++)
//             {
//                 if (strcmp(teams[i].team_name, team_name) == 0)
//                 {
//                     displayTeam(teams[i]);
//                     break;
//                 }
//             }
//             break;
//         }

//         case 3:
//             printf("Team with most goals scored: %s (%d goals)\n", max_team, max_goals);
//             printf("Team with least goals conceded: %s (%d goals)\n", min_team, min_goals);
//             break;
//         case 4:
//             saveTeamsToFile(teams, num_teams);
//             break;

//         case 5:
//             printf("Program Ended...\n");
//             break;
//         default:
//             printf("Invalid choice. Try again.\n");
//         }
//     }
//     while (choice != 5);

//     return 0;
// }

int main()
{
    Team footballTeams[100];
    int num_teams = 0;
    loadTeamsFromFile(footballTeams, &num_teams);

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
            Player newPlayer;
            printf("Enter which team:");
            scanf("%d", &nT);
            printf("Enter player name: ");
            scanf("%s", newPlayer.player_name);
            printf("Enter player number: ");
            scanf("%d", &newPlayer.player_number);
            printf("Enter player position: ");
            scanf("%s", newPlayer.player_position);
            printf("Enter goals scored: ");
            scanf("%d", &newPlayer.goals_scored);
            printf("Enter goals conceded: ");
            scanf("%d", &newPlayer.goals_conceded);
            printf("Enter minutes played: ");
            scanf("%d", &newPlayer.number_of_minutes_played);
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
            displayStatistics(&footballTeams, num_teams);
            break;
        case 4:
            saveTeamsToFile(&footballTeams, num_teams);
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

void loadTeamsFromFile(Team teams[], int *num_teams)

{
    FILE *file = fopen("fdms.txt", "r");
    if (file == NULL)
    {
        printf("File not found.\n");
        return;
    }

    fscanf(file, "%d", num_teams);
    for (int i = 0; i < *num_teams; i++)
    {
        fscanf(file, "%s", teams[i].team_name);
        fscanf(file, "%d", &teams[i].num_players);
        for (int j = 0; j < teams[i].num_players; j++)
        {
            fscanf(file, "%s %d %s %d %d %d",
                   teams[i].players[j].player_name,
                   &teams[i].players[j].player_number,
                   teams[i].players[j].player_position,
                   &teams[i].players[j].goals_scored,
                   &teams[i].players[j].goals_conceded,
                   &teams[i].players[j].number_of_minutes_played);
        }
    }

    fclose(file);
    printf("Teams loaded from file successfully!\n");
}
void saveTeamsToFile(Team teams[], int num_teams)

{
    FILE *file = fopen("fdms.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d\n", num_teams);
    for (int i = 0; i < num_teams; i++)
    {
        fprintf(file, "%s\n", teams[i].team_name);
        fprintf(file, "%d\n", teams[i].num_players);
        for (int j = 0; j < teams[i].num_players; j++)
        {
            fprintf(file, "%s %d %s %d %d %d\n",
                    teams[i].players[j].player_name,
                    teams[i].players[j].player_number,
                    teams[i].players[j].player_position,
                    teams[i].players[j].goals_scored,
                    teams[i].players[j].goals_conceded,
                    teams[i].players[j].number_of_minutes_played);
        }
    }

    fclose(file);
    printf("Teams saved to file successfully!\n");
}
void addPlayerToTeam(Team *team, Player player)
{
    if ((*team).num_players < 20)
    {
        (*team).players[(*team).num_players++] = player;
        printf("Player added successfully!\n");
    }
    else
    {
        printf("Team is full. Cannot add more players.\n");
    }
}
void displayTeam(Team team)

{
    printf("Team Name: %s\n", team.team_name);
    printf("Players:\n");
    for (int i = 0; i < team.num_players; i++)
    {
        printf("Player %d:\n", i + 1);
        displayPlayer(team.players[i]);
        printf("\n");
    }
}
void displayPlayer(Player player)

{
    printf("Player Name: %s\n", player.player_name);
    printf("Player Number: %d\n", player.player_number);
    printf("Player Position: %s\n", player.player_position);
    printf("Goals Scored: %d\n", player.goals_scored);
    printf("Goals Conceded: %d\n", player.goals_conceded);
    printf("Minutes Played: %d\n", player.number_of_minutes_played);
}
void displayStatistics(Team teams[], int num_teams)

{
    int maxScored = 0;
    int maxConceded = 0;
    int maxMinutes = 0;
    char pWithMaxMinutes[50];
    char teamWithMaxConceded[50];

    for (int i = 0; i < num_teams; i++)
    {
        for (int j = 0; j < teams[i].num_players; j++)
        {
            if (teams[i].players[j].goals_scored > maxScored)
            {
                maxScored = teams[i].players[j].goals_scored;
            }
            if (teams[i].players[j].number_of_minutes_played > maxMinutes)
            {
                maxMinutes = teams[i].players[j].number_of_minutes_played;
                strcpy(pWithMaxMinutes, teams[i].players[j].player_name);
            }
        }

        int totalConceded = 0;
        for (int j = 0; j < teams[i].num_players; j++)
        {
            totalConceded += teams[i].players[j].goals_conceded;
        }
        if (totalConceded > maxConceded)
        {
            maxConceded = totalConceded;
            strcpy(teamWithMaxConceded, teams[i].team_name);
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
