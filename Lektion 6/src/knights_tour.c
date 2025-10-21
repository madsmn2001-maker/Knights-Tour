#include <stdio.h>
#include <string.h>
#include "knights_tour.h"

// Knight move offsets (clockwise)
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
    int new_x = (int)x + MOVES_X[move_id];
    int new_y = (int)y + MOVES_Y[move_id];

    return new_x >= 0 && new_x < SIZE &&
           new_y >= 0 && new_y < SIZE &&
           visited[new_y][new_x] == 0;
}

unsigned int tour_greedy(size_t start_x, size_t start_y) {
    board_t visited = {0};
    size_t x = start_x;
    size_t y = start_y;
    unsigned int move_count = 1;

    visited[y][x] = move_count;

    while (1) {
        bool moved = false;
        for (size_t i = 0; i < MOVE_COUNT; ++i) {
            int new_x = (int)x + MOVES_X[i];
            int new_y = (int)y + MOVES_Y[i];
            if (move_is_possible(i, x, y, visited)) {
                x = new_x;
                y = new_y;
                visited[y][x] = ++move_count;
                moved = true;
                break;
            }
        }
        if (!moved)
            break;
    }

    return move_count;
}

void greedy_tour_from_each_square(void) {
    board_t result = {0};

    for (size_t y = 0; y < SIZE; ++y) {
        for (size_t x = 0; x < SIZE; ++x) {
            result[y][x] = tour_greedy(x, y);
        }
    }

    print_board(result);
}

void print_board(board_t board) {
    for (size_t y = 0; y < SIZE; ++y) {
        for (size_t x = 0; x < SIZE; ++x) {
            printf("%2u ", board[y][x]);
        }
        printf("\n");
    }
}
