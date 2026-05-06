#include <stdio.h>

int main()
{
    // Step 1: Read integers from "Sample.txt" and store them in an array
    FILE *file_input = fopen("Sample.txt", "r");
    if (file_input == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    int numbers[100]; // Assuming a maximum of 100 numbers
    int num_count = 0;
    int num;

    while (fscanf(file_input, "%d", &num) != EOF && num_count < 100)
    {
        numbers[num_count++] = num;
    }
    fclose(file_input);

    // Step 2: Write even numbers to "Output.txt"
    FILE *file_output = fopen("Output.txt", "w");
    if (file_output == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < num_count; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            fprintf(file_output, "%d\n", numbers[i]);
        }
    }
    fclose(file_output);

    printf("Even numbers saved to Output.txt successfully.\n");

    return 0;
}