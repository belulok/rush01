#include "rush01.h"

int solve_skyscraper(int **board, int row, int col, int *top, int *bottom, int *left, int *right) {
    // If we are beyond the last row, we've filled in the entire board and are done
    if (row >= SIZE) {
        return 1; // Success!
    }

    // If we are beyond the last column, move to the next row
    if (col >= SIZE) {
        return solve_skyscraper(board, row + 1, 0, top, bottom, left, right);
    }

    int height = 1; // Start with the smallest possible skyscraper

    // Iterate through possible heights for the skyscraper
    while (height <= SIZE) {
        // Place the skyscraper
        board[row][col] = height;
        
        // Check if this placement is valid
        if (is_valid(board, row, col, top, bottom, left, right)) {
            // Move to the next column
            if (solve_skyscraper(board, row, col + 1, top, bottom, left, right)) {
                return 1; // Found a valid solution
            }
        }

        // Backtrack: remove the skyscraper and try the next height
        board[row][col] = 0;
        height++; // Increment the height for the next iteration
    }

    // No valid placement was found, need to backtrack
    return 0;
}