#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    char word[100];
    int count = 0;

    printf("First string: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // removing newline character

    printf("Second string: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // removing newline character

    // Convert both strings to lowercase
    for (int i = 0; sentence[i]; i++)
        sentence[i] = tolower(sentence[i]);
    for (int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);

    // Find occurrences of word in sentence
    char *ptr = sentence;
    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr++; // Move pointer to next character in sentence
    }

    printf("%d\n", count);

    return 0;
}