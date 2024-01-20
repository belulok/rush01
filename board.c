#include "rush01.h"


int **create_board(int size) {
    int **board = (int **)malloc(size * sizeof(int *));
    if (board == NULL) {
        ft_putstr("Memory allocation failed for board.\n");
        return NULL;
    }
    
    int i = 0;
    while (i < size) {
        board[i] = (int *)malloc(size * sizeof(int));
        if (board[i] == NULL) {
            ft_putstr("Memory allocation failed for board row ");
            ft_putnbr(i);
            ft_putchar('\n');
            
            // Free any previously allocated rows
            int j = 0;
            while (j < i) {
                free(board[j]);
                j++;
            }
            free(board);
            
            return NULL;
        }
        i++;
    }
    return board;
}



// Function to free the board
void free_board(int **board, int size) {
    int i = 0;
    while (i < size) {
        free(board[i]);
        i++;
    }
    free(board);
}


// Function to initialize the board with zeros
void initialize_board(int **board, int size) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            board[i][j] = 0;
            j++;
        }
        i++;
    }
}

// Function to print the board
void print_board(int **board, int size) {
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            ft_putnbr(board[i][j]);
            ft_putchar(' '); // To print a space after each number
            j++;
        }
        ft_putchar('\n'); // To start a new line after each row
        i++;
    }
}