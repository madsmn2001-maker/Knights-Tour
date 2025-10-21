#include "knights_tour.h"
#include <stdio.h>

int main(void) {
    printf("Greedy Knights Tour for board size %d x %d:\n\n", SIZE, SIZE);
    greedy_tour_from_each_square();
    return 0;
}
