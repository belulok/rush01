#ifndef RUSH01_H
#define RUSH01_H

#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

// Function prototypes
int **create_board(int size);
void free_board(int **board, int size);
void initialize_board(int **board, int size);
void print_board(int **board, int size);
void initialize_clues(int *top, int *bottom, int *left, int *right, int size);
int count_visible_from_left(int *row);
int count_visible_from_right(int *row);
int count_visible_from_top(int **board, int col);
int count_visible_from_bottom(int **board, int col);
int is_valid(int **board, int row, int col, int *top, int *bottom, int *left, int *right);
int solve_skyscraper(int **board, int row, int col, int *top, int *bottom, int *left, int *right);
void ft_putstr(char *str);
int ft_putchar(char c);
void ft_putnbr(int n);
void ft_reverse(char *str, int length);
void ft_itoa(int num, char *str);
char *ft_strdup(const char *s);
char *ft_strchr(const char *str, int c);
char *ft_strtok(char *str, const char *delim);
void parse_and_set_clues(char *input, int *top, int *bottom, int *left, int *right);
void print_clues(int top[], int bottom[], int left[], int right[]);
#endif