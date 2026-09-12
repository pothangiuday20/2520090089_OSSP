#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 20
#define MAX_HISTORY 10

int main() {
    char **history = malloc(MAX_HISTORY * sizeof(char *));
    int history_count = 0;

    char *input = malloc(INITIAL_SIZE);
    int buffer_size = INITIAL_SIZE;

    if (history == NULL || input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("====== COMMAND HISTORY DEMO ======\n");
    printf("Escape sequence example: \\033[A = UP arrow\n");
    printf("Escape sequence example: \\033[B = DOWN arrow\n");

    /* Store commands */
    const char *commands[] = {
        "ls",
        "pwd",
        "gcc program.c",
        "git status",
        "git push"
    };

    for (int i = 0; i < 5; i++) {
        history[history_count] = malloc(strlen(commands[i]) + 1);

        if (history[history_count] == NULL) {
            printf("Memory allocation failed\n");
            break;
        }

        strcpy(history[history_count], commands[i]);
        history_count++;
    }

    /* Display command history */
    printf("\nCommand History:\n");

    for (int i = 0; i < history_count; i++) {
        printf("%d  %s\n", i + 1, history[i]);
    }

    /* Free allocated memory */
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    free(history);
    free(input);

    return 0;
}
