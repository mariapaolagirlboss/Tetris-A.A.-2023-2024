#ifndef GRID_H
#define GRID_H

#include <ncurses.h>

#define WIDTH 10
#define HEIGHT 20

class Grid {
private:
    char grid[HEIGHT][WIDTH];

public:
    Grid();
    void initialize_grid();
    void draw_grid();
    bool is_valid_position(int x, int y);
    void set_cell(int x, int y, char value);
};

#endif // GRID_H
