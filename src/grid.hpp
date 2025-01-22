#pragma once //usato solamente una volta
#ifndef GRID_H
#define GRID_H

class Griglia {

    private: 
     int Lunghezza; // colonne
     int Larghezza; // righe
     int GrandezzaCella; 

    public:
     Griglia();
     int grid [20][10]; 
     void Inizializza ();
     void Stampa ();
     bool Verifica_Posizione(int x, int y);
     void Fissa_Cella(int x, int y, char valore);

     //funzioni riguardanti le collisioni
     bool Collisione_Non_Avvenuta (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     bool Posiziona (int x, int y, char tetramino [4][4], int larghezza, int altezza, char figura);
     // void Rimozione_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     void Controllo_Er ();
     void Svuota_Celle (int x, int y, char tetramino [4][4], int larghezza, int altezza);
     void Elimina_Riga (int r);



};

#endif
