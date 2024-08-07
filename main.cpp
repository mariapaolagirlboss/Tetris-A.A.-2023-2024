#include <ncurses.h>
#include "grid.h"

int main() {

    initscr();              // Inizializza ncurses
    noecho();               // Non mostrare l'input dell'utente
    cbreak();               // Disabilita il buffering dell'input

    Grid grid;
    grid.draw_grid();

    refresh();              // Aggiorna lo schermo
    getch();                // Aspetta l'input dell'utente

    endwin();               // Termina ncurses
    return 0;
}
