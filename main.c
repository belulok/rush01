#include "rush01.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ft_putstr("Error: Strictly only include 2 arguments only \n");
        return 1;
    }

    int top[SIZE], bottom[SIZE], left[SIZE], right[SIZE];
    char *clues = ft_strdup(argv[1]);
    parse_and_set_clues(clues, top, bottom, left, right);
    free(clues);

    int **board = create_board(SIZE);
    initialize_board(board, SIZE);

    if (solve_skyscraper(board, 0, 0, top, bottom, left, right)) {
        print_board(board, SIZE);
    } else {
        ft_putstr("Error: Unsolvable \n");
    }

    free_board(board, SIZE);
    return 0;
}