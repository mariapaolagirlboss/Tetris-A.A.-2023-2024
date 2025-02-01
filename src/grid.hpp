#pragma once //usato solamente una volta
#include <ncurses.h>
#ifndef GRID_H
#define GRID_H


class Griglia {

    private: 
     int Lunghezza; // colonne
     int Larghezza; // righe
     char grid [20][10]; 
     WINDOW* win;

    public:
     Griglia();
     ~Griglia() throw ();

     void Inizializza ();
     void Stampa ();
     void Fissa_In_Cella(int x, int y, char tetramino [4][4], int larghezza, int altezza);

     //funzioni riguardanti le collisioni
     bool Collisione_Non_Avvenuta (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     bool Posiziona_T (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     // void Rimozione_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza); metodo superfluo
     void Check_Righe ();
     void Svuota_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza);



};

#endif
