#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 8
#define MOVE_COUNT 8

// Type definition for the board
typedef unsigned int board_t[SIZE][SIZE];

extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

// Function declarations
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);
unsigned int tour_greedy(size_t start_x, size_t start_y);
void greedy_tour_from_each_square(void);
void print_board(board_t board);

#endif
