#include <string.h>
#include <stdio.h>

struct cricketer
{
    char name[50];
    char country[50];
    char type[10];
    int wicketTaken[30];
    int runsScored[30];

};
 int main()
{
    int matchesPlayed;
    float overallscore;

    for (int i = 0; i < 100; i++)
    {
        printf("for player %d enter name country and type( bowler or batter ) : ", i + 1);
         scanf("%s", cricketer[i].name);
         
        // if (cricketer[i].type == bowler )
        // scanf("%d", cricketer[i].wicketTaken);
        // else
        // scanf("%d", cricketer[i].runsScored);
    }

    return 0;
}