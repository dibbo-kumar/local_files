#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file;
    char ch[100];
    file = fopen("text.txt", "w");
    if (file == NULL)
    {
        printf("\nfile is not  opened");
        return 0;
    }
    else
    {
        printf("\nfile is  opened\n");
        // printf("\n enter the string");
        // gets(ch);
        // fputs(ch, file);
        // printf("\nfile is  done\n");
        // while (!feof(file))
        // {
        //     ch = fgetc(file);
        //     printf("%c", ch);

        // }
        // printf("\n");
        // while (fgets(ch, sizeof(ch), file) != NULL)
        // {
        //     printf("%s", ch);
        // }
        printf("\nenter the string");
        fgets(ch, sizeof(ch), stdin);
        fputs(ch, file);

        fclose(file);
    }

    return 0;
}