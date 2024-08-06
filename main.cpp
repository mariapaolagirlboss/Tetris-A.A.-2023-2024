#include <ncurses.h>

int main () {

    initscr();

    // hide the cursor
    curs_set(0);

    int height, width, start_y, start_x;
    height = 20;
    width = 10;
    start_y = 5;
    start_x = 10;

    WINDOW *win = newwin(height, width, start_y, start_x);

    // cornice base
    box(win, 0, 0);

    // refreshes a specific window
    wrefresh(win);
    // refreshes the entire screen
    refresh();

    endwin();

    return 0;
}