#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>

class Menu {
public:
    // Mostra il messaggio di Game Over
    static void mostraGameOver(int punteggio);

    // Mostra il menù iniziale
    static void mostraMenuIniziale();
};

#endif