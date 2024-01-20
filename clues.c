#include "rush01.h"

void parse_and_set_clues(char *input, int *top, int *bottom, int *left, int *right) {
    char *token = ft_strtok(input, " ");
    int i = 0;

    while (i < SIZE && token != NULL) {
        top[i] = atoi(token);
        token = ft_strtok(NULL, " ");
        i++;
    }
    i = 0;
    while (i < SIZE && token != NULL) {
        bottom[i] = atoi(token);
        token = ft_strtok(NULL, " ");
        i++;
    }
    i = 0;
    while (i < SIZE && token != NULL) {
        left[i] = atoi(token);
        token = ft_strtok(NULL, " ");
        i++;
    }
    i = 0;
    while (i < SIZE && token != NULL) {
        right[i] = atoi(token);
        token = ft_strtok(NULL, " ");
        i++;
    }
}