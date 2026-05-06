#include <stdio.h>
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
void updateTeam(Team *team, int player_index, int goals_scored, int goals_conceded, int minutes_played);
void displayPlayer(Player player);
void displayTeam(Team team);
void saveTeamsToFile(Team teams[], int num_teams);
void loadTeamsFromFile(Team teams[], int *num_teams);
void updateStats(Team teams[], int num_teams);
void Add_team(Team *team);

int max_goals= 0;
char max_team[50];
const int max = 1000000;
int min_goals= max;
char min_team[50];

int main()
{
    int choice;
    Team teams[10];
    int num_teams = 0;
    max_goals = 0;
    strcpy(max_team, "");
    min_goals = max;
    strcpy(min_team, "");

    loadTeamsFromFile(teams, &num_teams);
    loadStatsFromFile();
    updateStats(teams, num_teams);

    do
    {
        printf("\nFootball Database Management System\n");
        printf("1. Add a new team\n");
        printf("2. Add a player to a team\n");
        printf("3. Display team information\n");
        printf("4. Display player information\n");
        printf("5. Update player statistics\n");
        printf("6. View statistics\n");
        printf("7. Save teams to file\n");
        printf("8. Load teams from file\n");
        printf("9. End\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTeam(teams, &num_teams);
            break;
        case 2:
        {
            char team_name[50];
            Player player;
            int teamIndex;
            printf("Enter team name: ");
            scanf("%s", team_name);

            Team *team = NULL;
            for (int i = 0; i < num_teams; i++)
            {
                if (strcmp(teams[i].team_name, team_name) == 0)
                {
                    team = &teams[i];
                    teamIndex = i;
                    break;
                }
            }

            if (team == NULL)
            {
                printf("Team not found.\n");
                break;
            }

            printf("Enter player name: ");
            scanf("%s", player.player_name);
            printf("Enter player number: ");
            scanf("%d", &player.player_number);
            printf("Enter player position (FWD, MID, DEF): ");
            scanf("%s", player.player_position);
            if((strcmp(player.player_position,"FWD")==0)||(strcmp(player.player_position,"MID")==0))
            {
                printf("Enter goals scored: ");
                scanf("%d", &player.goals_scored);
            }
            else
            {
                printf("Enter goals conceded: ");
                scanf("%d", &player.goals_conceded);
            }
            printf("Enter minutes played: ");
            scanf("%d", &player.number_of_minutes_played);

            addPlayerToTeam(team, player);
            updateStats(teams, num_teams);
            break;
        }
        case 3:
        {
            char team_name[50];
            printf("Enter team name: ");
            scanf("%s", team_name);

            for (int i = 0; i < num_teams; i++)
            {
                if (strcmp(teams[i].team_name, team_name) == 0)
                {
                    displayTeam(teams[i]);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            char player_name[50];
            printf("Enter player name: ");
            scanf("%s", player_name);

            for (int i = 0; i < num_teams; i++)
            {
                for (int j = 0; j < teams[i].num_players; j++)
                {
                    if (strcmp(teams[i].players[j].player_name, player_name) == 0)
                    {
                        displayPlayer(teams[i].players[j]);
                        break;
                    }
                }
            }
            break;
        }
        case 5:
        {
            char team_name[50];
            int player_index;
            int goals_scored, goals_conceded, minutes_played;
            printf("Enter team name: ");
            scanf("%s", team_name);

            Team *team = NULL;
            for (int i = 0; i < num_teams; i++)
            {
                if (strcmp(teams[i].team_name, team_name) == 0)
                {
                    team = &teams[i];
                    break;
                }
            }

            if (team == NULL)
            {
                printf("Team not found.\n");
                break;
            }

            printf("Enter player index: ");
            scanf("%d", &player_index);

            printf("Enter goals scored: ");
            scanf("%d", &goals_scored);
            printf("Enter goals conceded: ");
            scanf("%d", &goals_conceded);
            printf("Enter minutes played: ");
            scanf("%d", &minutes_played);

            updateTeam(team, player_index - 1, goals_scored, goals_conceded, minutes_played);
            updateStats(teams, num_teams);
            break;
        }
        case 6:
            printf("Team with most goals scored: %s (%d goals)\n", max_team, max_goals);
            printf("Team with least goals conceded: %s (%d goals)\n", min_team, min_goals);
            break;
        case 7:
            saveTeamsToFile(teams, num_teams);
            break;
        case 8:
            loadTeamsFromFile(teams, &num_teams);
            updateStats(teams, num_teams);
            break;
        case 9:
            printf("Program Ended...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    while (choice != 9);

    return 0;
}
void addTeam(Team teams[], int *num_teams)
{
    char team_name[50];
    printf("Enter team name: ");
    scanf("%s", team_name);

    for (int i = 0; i < *num_teams; i++)
    {
        if (strcmp(teams[i].team_name, team_name) == 0)
        {
            printf("This team already exists.\n");
            return;
        }
    }

    if (*num_teams < 10)
    {
        strcpy(teams[*num_teams].team_name, team_name);
        (*num_teams)++;
        printf("Team added successfully!\n");
    }
    else
    {
        printf("Cannot add more teams. Maximum limit reached.\n");
    }
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
void displayPlayer(Player player)
{
    printf("Player Name: %s\n", player.player_name);
    printf("Player Number: %d\n", player.player_number);
    printf("Player Position: %s\n", player.player_position);
    if((strcmp(player.player_position,"FWD")==0)||(strcmp(player.player_position,"MID")==0)) printf("Goals Scored: %d\n", player.goals_scored);
    else printf("Goals Conceded: %d\n", player.goals_conceded);
    printf("Minutes Played: %d\n", player.number_of_minutes_played);
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
void saveTeamsToFile(Team teams[], int num_teams)
{
    FILE *file = fopen("football_database.txt", "w");
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
void loadTeamsFromFile(Team teams[], int *num_teams)
{
    FILE *file = fopen("football_database.txt", "r");
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
void updateTeam(Team *team, int player_index, int goals_scored, int goals_conceded, int minutes_played)
{
    if (player_index >= 0 && player_index < (*team).num_players)
    {
        Player *player = &(*team).players[player_index];

        if (strcmp((*player).player_position, "FWD") == 0 || strcmp((*player).player_position, "MID") == 0)
        (*player).goals_scored += goals_scored;

        if (strcmp((*player).player_position, "DEF") == 0) (*player).goals_conceded += goals_conceded;

        (*player).number_of_minutes_played += minutes_played;

        printf("Player stats updated successfully!\n");
    }
    else
    {
        printf("Invalid player index.\n");
    }
}
void updateStats(Team teams[], int num_teams)
{
    max_goals = 0;
    strcpy(max_team, "");
    min_goals = max;
    strcpy(min_team, "");

    for (int i = 0; i < num_teams; i++)
    {
        int team_goals_scored = 0;
        int team_goals_conceded = 0;
        for (int j = 0; j < teams[i].num_players; j++)
        {
            team_goals_scored += teams[i].players[j].goals_scored;
            team_goals_conceded += teams[i].players[j].goals_conceded;
        }
        if (team_goals_scored > max_goals)
        {
            max_goals = team_goals_scored;
            strcpy(max_team, teams[i].team_name);
        }
        if (team_goals_conceded < min_goals)
        {
            min_goals = team_goals_conceded;
            strcpy(min_team, teams[i].team_name);
        }
    }
    saveStatsToFile();
}
void saveStatsToFile()
{
    FILE *file = fopen("stats.txt", "w");
    if (file == NULL)
    {
        printf("Error opening stats.txt file.\n");
        return;
    }

    fprintf(file, "%s %d\n", max_team, max_goals);
    fprintf(file, "%s %d\n", min_team, min_goals);

    fclose(file);
    printf("Statistics saved to stats.txt successfully!\n");
}
void loadStatsFromFile()
{
    FILE *file = fopen("stats.txt", "r");
    if (file == NULL)
    {
        printf("stats.txt file not found.\n");
        return;
    }

    fscanf(file, "%s %d", max_team, &max_goals);
    fscanf(file, "%s %d", min_team, &min_goals);

    fclose(file);
    printf("Statistics loaded from stats.txt successfully!\n");
}

