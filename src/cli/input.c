#include <stdio.h>
#include <string.h>

void getInput(char *str, int length, char *prompt) {
    printf("%s ", prompt);
    fgets(str, length, stdin);

    str[strcspn(str, "\n")] = 0;
}