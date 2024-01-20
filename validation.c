#include "rush01.h"

// Checks if the board is valid up to the current row and column
int is_valid(int **board, int row, int col, int *top, int *bottom, int *left, int *right) {
    int i = 0;

    // Check if the current row has a unique set of skyscrapers
    while (i < col) {
        if (board[row][i] == board[row][col] && board[row][col] != 0) {
            return 0; // Duplicate skyscraper in row
        }
        i++;
    }

    i = 0; // Reset i for the next check

    // Check if the current column has a unique set of skyscrapers
    while (i < row) {
        if (board[i][col] == board[row][col] && board[row][col] != 0) {
            return 0; // Duplicate skyscraper in column
        }
        i++;
    }

    // If we are at the end of a row, check against the left and right clues
    if (col == SIZE - 1) {
        if (count_visible_from_left(board[row]) != left[row] || count_visible_from_right(board[row]) != right[row]) {
            return 0; // Clue not matched for the row
        }
    }

    // If we are at the end of a column, check against the top and bottom clues
    if (row == SIZE - 1) {
        int col_values[SIZE];
        i = 0;
        while (i < SIZE) {
            col_values[i] = board[i][col];
            i++;
        }

        if (count_visible_from_top(board, col) != top[col] || count_visible_from_bottom(board, col) != bottom[col]) {
            return 0; // Clue not matched for the column
        }
    }

    return 1; // If all checks pass, the placement is valid
}






// Function to count visible skyscrapers from the right side of a row
int count_visible_from_left(int *row) {
    int visible_count = 0;
    int max_height = 0;
    int i = 0;

    while (i < SIZE) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
        i++;
    }

    return visible_count;
}


// Function to count visible skyscrapers from the top of a column
int count_visible_from_top(int **board, int col) {
    int visible_count = 0;
    int max_height = 0;
    int i = 0;

    while (i < SIZE) {
        if (board[i][col] > max_height) {
            max_height = board[i][col];
            visible_count++;
        }
        i++;
    }

    return visible_count;
}


// Function to count visible skyscrapers from the bottom of a column
int count_visible_from_bottom(int **board, int col) {
    int visible_count = 0;
    int max_height = 0;
    int i = SIZE - 1;

    while (i >= 0) {
        if (board[i][col] > max_height) {
            max_height = board[i][col];
            visible_count++;
        }
        i--;
    }

    return visible_count;
}

int count_visible_from_right(int *row) {
    int visible_count = 0;
    int max_height = 0;
    int i = SIZE - 1;

    while (i >= 0) {
        if (row[i] > max_height) {
            max_height = row[i];
            visible_count++;
        }
        i--;
    }

    return visible_count;
}