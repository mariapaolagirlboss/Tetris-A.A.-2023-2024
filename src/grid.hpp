#pragma once //usato solamente una volta
#ifndef GRID_H
#define GRID_H

#include <ncurses.h>

class Griglia {

    private: 
     int Lunghezza; // colonne
     int Larghezza; // righe
     int GrandezzaCella; 
     int grid [20][10]; 
     WINDOW* win;

    public:
     Griglia();
     ~Griglia() noexcept;

     void Inizializza ();
     void Stampa ();
     void Fissa_In_Cella(int x, int y, char tetramino [4][4], int larghezza, int altezza);

     //funzioni riguardanti le collisioni
     bool Collisione_Non_Avvenuta (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     bool Posiziona (int x, int y, char tetramino [4][4], int larghezza, int altezza, char figura);
     // void Rimozione_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza); metodo superfluo
     void Check_Righe ();
     void Svuota_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza);



};

#endif
