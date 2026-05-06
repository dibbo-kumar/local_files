#include <stdio.h>

int main()
{
    int x, y, i = 3, m = 0;

    printf("p1 pick a number\n");
    scanf("%d", &x);
    printf("p2 guess the number\n");
    scanf("%d", &y);

    if (x != y)
    {
        printf("sorry wrong guess  %d chances left\n", i - 1);
        i--;
    }
    else
    {
        printf("number 2 wins\n");
        m = 1;
    }

    if (m != 1 && i > 0)
    {
        printf("p2 guess the number again\n");
        scanf("%d", &y);

        if (x != y)
        {
            printf("sorry wrong guess  %d chances left\n", i - 1);
            i--;
        }
        else
        {
            printf("congrats, you've guessed correctly\n");
            m = 1;
        }
    }

    if (m != 1 && i > 0)
    {
        printf("p2 guess the number again\n");
        scanf("%d", &y);

        if (x != y)
            printf("player 1 wins\n");
        else
        {
            printf("congrats, you've guessed correctly\n");
            m = 1;
        }
    }

    return 0;
}