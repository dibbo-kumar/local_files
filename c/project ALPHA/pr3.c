#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file;
    char ch[40];
    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("\n fil is not  opened");
        return 0;
    }
    else
    {

        printf("\nfile is  done");
        fscanf(file, "%s", &ch);
        printf("%s\n", ch);

        fclose(file);
    }

    return 0;
}