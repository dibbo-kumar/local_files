#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Player {
    char playerName[50];
    int playerNumber;
    char playerPosition[10];
    int goalsScored;
    int goalsConceded;
    int minutes_played;
};



/// implement function loadTeamsFromFile

/// implement function saveTeamsToFile

/// implement function addPlayerToTeam

/// implement function displayTeam

/// implement function displayPlayer

/// implement function displayStatistics



int main() {
    struct Team footballTeams[MAX_TEAMS];
    int numTeams = 0;
    /// Load teams from file
    loadTeamsFromFile(footballTeams, &numTeams);

    int choice;
    while(1){
        printf("----------------------------------------------------------------------\n");
        printf("----------Welcome to Football Management System (FMS)-----------------\n");
        printf("----------------------------------------------------------------------\n\n");
        printf("Menu:\n1.Add a player\n2.Display Team information\n3.Update team information\n4.Show Statistics\n5.Save Team\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            /// Add players to a team by taking player information as user input
            /// call the function addPlayerToTeam(team,player)
            break;
        case 2:
            /// Display team information
            break;
        case 3:
            /// Update Team information
            break;
        case 4:
            /// show statistics like Most goals scored, Most goals conceded by a team and most minutes played by a player
            break;
        case 5:
            /// Save teams to file
            saveTeamsToFile(footballTeams, numTeams);
            break;
        case 6:
            printf("Thanks for using our System!!!")
            exit(0);
            break;
        }
    }
    return 0;
}
