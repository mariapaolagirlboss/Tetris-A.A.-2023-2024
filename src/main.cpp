#include <ncurses.h>
#include <cstdlib>
#include "grid.hpp"
#include "classifica.hpp"

void menu(classifica& classifica);
void nuovaPartita(classifica& classifica);

int main() {
    initscr();            // Inizializza la modalità schermo per ncurses
    cbreak();             // Disabilita il buffering dell'input per leggere i caratteri immediatamente
    noecho();             // Disabilita l'eco dei caratteri digitati dall'utente
    keypad(stdscr, TRUE); // Abilita l'uso dei tasti speciali (come le frecce)
    curs_set(0);          // Nasconde il cursore

    // Crea un oggetto Classifica che gestisce la classifica nel file "classifica.txt"
    classifica classifica("classifica.txt");
    Griglia grid;
    grid.Inizializza();

    refresh();              // Aggiorna lo schermo

    // Avvia il menu principale
    menu(classifica);

    endwin();             // Termina la modalità schermo di ncurses
    return 0;
}

// Funzione che gestisce il menu principale
void menu(classifica& classifica) {
    int scelta;
    while (true) {
        clear();
        mvprintw(0, 0, "Benvenuto nel gioco!");
        mvprintw(2, 0, "1. Nuova partita");
        mvprintw(3, 0, "2. Visualizza classifica");
        mvprintw(4, 0, "3. Esci");

        scelta = getch();  // Legge la scelta dell'utente

        switch (scelta) {
            case '1':
                nuovaPartita(classifica); // Avvia una nuova partita
                break;
            case '2':
                classifica.drawClassifica(stdscr); // Visualizza la classifica
                break;
            case '3':
                return; // Esce dal programma
            default:
                mvprintw(6, 0, "Scelta non valida. Premi un tasto per continuare.");
                getch();
                break;
        }
    }
}

// Funzione che simula una nuova partita e aggiunge il punteggio alla classifica
void nuovaPartita(classifica& classifica) {
    clear();
    mvprintw(0, 0, "Gioco in corso...");

    // Simulazione di una partita con punteggio casuale
    int punteggio = rand() % 100 + 1;
    mvprintw(2, 0, "Hai ottenuto un punteggio di: %d", punteggio);

    // Aggiunge il punteggio alla classifica e lo salva nel file
    classifica.inserisciPunteggio(punteggio);

    mvprintw(4, 0, "Premi un tasto per tornare al menu...");
    getch(); // Attende un input dell'utente per tornare al menu
}

/*#include <ncurses.h>
#include <cstdlib>
#include "grid.hpp"
#include "classifica.hpp"
#include "menu.hpp"

void menu(Classifica& classifica);
void nuovaPartita(Classifica& classifica);

int main() {
    initscr();            // Inizializza la modalità schermo per ncurses
    cbreak();             // Disabilita il buffering dell'input per leggere i caratteri immediatamente
    noecho();             // Disabilita l'eco dei caratteri digitati dall'utente
    keypad(stdscr, TRUE); // Abilita l'uso dei tasti speciali (come le frecce)
    curs_set(0);          // Nasconde il cursore

    // Crea un oggetto Classifica che gestisce la classifica nel file "classifica.txt"
    Classifica classifica("classifica.txt");
    Griglia grid;
    grid.Inizializza();

    refresh();              // Aggiorna lo schermo

    // Avvia il menu principale
    menu(classifica);

    endwin();             // Termina la modalità schermo di ncurses
    return 0;
}

// Funzione che gestisce il menu principale
void menu(Classifica& classifica) {
    int scelta;
    while (true) {
        clear();
        mvprintw(0, 0, "Benvenuto nel gioco!");
        mvprintw(2, 0, "1. Nuova partita");
        mvprintw(3, 0, "2. Visualizza classifica");
        mvprintw(4, 0, "3. Esci");

        scelta = getch();  // Legge la scelta dell'utente

        switch (scelta) {
            case '1':
                nuovaPartita(classifica); // Avvia una nuova partita
                break;
            case '2':
                classifica.mostraClassifica(); // Visualizza la classifica
                break;
            case '3':
                return; // Esce dal programma
            default:
                mvprintw(6, 0, "Scelta non valida. Premi un tasto per continuare.");
                getch();
                break;
        }
    }
}

// Funzione che simula una nuova partita e aggiunge il punteggio alla classifica
void nuovaPartita(Classifica& classifica) {
    clear();
    mvprintw(0, 0, "Gioco in corso...");

    // Simulazione di una partita con punteggio casuale
    int punteggio = rand() % 100 + 1;
    mvprintw(2, 0, "Hai ottenuto un punteggio di: %d", punteggio);

    // Aggiunge il punteggio alla classifica e lo salva nel file
    classifica.aggiungiPunteggio(punteggio);

    mvprintw(4, 0, "Premi un tasto per tornare al menu...");
    getch(); // Attende un input dell'utente per tornare al menu
}*/

