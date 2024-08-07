#include <ncurses.h>
#include "grid.h"

Grid::Grid() {
    initialize_grid();
}

void Grid::initialize_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Grid::draw_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mvaddch(i, j, grid[i][j]);
        }
    }
}

bool Grid::is_valid_position(int x, int y) {
    return (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && grid[x][y] == ' ');
}

void Grid::set_cell(int x, int y, char value) {
    grid[x][y] = value;
}
