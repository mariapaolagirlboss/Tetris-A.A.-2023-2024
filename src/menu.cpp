#include "menu.hpp"

void Menu::mostraGameOver(int punteggio) {
    // Calcola la posizione centrale per la finestra di Game Over
    int startY = (LINES - 5) / 2;
    int startX = (COLS - 30) / 2;

    // Crea finestra Game Over
    WINDOW* gameOverWin = newwin(5, 30, startY, startX);
    box(gameOverWin, 0, 0);

    // Mostra messaggio Game Over
    wattron(gameOverWin, COLOR_PAIR(8));
    mvwprintw(gameOverWin, 1, 2, "Game Over!");
    mvwprintw(gameOverWin, 2, 2, "Punti: %d", punteggio);
    mvwprintw(gameOverWin, 3, 2, "Premi INVIO per continuare");
    wattroff(gameOverWin, COLOR_PAIR(8));
    wrefresh(gameOverWin);

    // Aspetta l'input dell'utente
    timeout(-1);
    while (getch() != 10); // Aspetta INVIO

    // Pulisci la finestra di Game Over
    delwin(gameOverWin);
}

void Menu::mostraMenuIniziale() {
    clear();
    int startY = LINES / 2 - 3;
    int startX = (COLS - 30) / 2;

    // Mostra il titolo
    mvprintw(startY, startX, "Benvenuto in Tetris!");
    mvprintw(startY + 2, startX, "Premi INVIO per iniziare");
    refresh();

    // Aspetta che l'utente prema INVIO
    timeout(-1);
    while (getch() != 10);
    clear();
    refresh();
}