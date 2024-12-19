#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    char* args[100];

    while (1) {
        printf("myshell> ");
        fgets(input, MAX_INPUT, stdin);

        if (strncmp(input, "exit", 4) == 0) break;

        input[strlen(input) - 1] = '\0'; // Remove newline

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            args[++i] = strtok(NULL, " ");
        }

        if (fork() == 0) {
            execvp(args[0], args);
            perror("Command failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
