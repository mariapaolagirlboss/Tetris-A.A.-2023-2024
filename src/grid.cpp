#include <iostream>
#include <ncurses.h>
#include "grid.hpp"
using namespace std;

// Tutto ciò che riguarda la griglia

Griglia::Griglia(){
    Lunghezza = 20;
    Larghezza = 10;
    GrandezzaCella = 30;
    Inizializza();
}

void Griglia::Inizializza(){
    for (int lungh = 0; lungh<Lunghezza; lungh ++){
        for (int largh= 0; largh<Larghezza; largh++){
            grid[lungh][largh]=' ';//inizialmente avevo posto 0, verifica cosa sia meglio
        }
    }

}

void Griglia::Stampa(){
    for (int lungh=0; lungh<Lunghezza; lungh++){
        for(int largh = 0; largh<Larghezza; largh++){
            mvaddch(lungh, largh, grid[lungh][largh]);

        }
    }
}

bool Griglia::Verifica_Posizione(int x, int y){
    return (x>=0 && x<Larghezza && y>=0 && y<Lunghezza&&grid[x][y]==' '); 

}

void Griglia::Fissa_Cella(int x, int y, char valore){
    grid[x][y]=valore; // fissa tetramino, riguarda se deve servirsi di verifica posizione
}

// Tutto ciò che riguarda le collisioni

bool Griglia::Collisione_Non_Avvenuta(int x, int y, char tetramino[4][4], int larghezza, int lunghezza){
    for (int i_r = 0; i_r<lunghezza; i_r++){ // i_r = indice della riga del tetramino
         for (int i_c = 0; i_c<larghezza; i_c++){ // i_c = indice della colonna del tetramino
            if (tetramino[i_r][i_c] != ' ') {
                int nuovaX = x + i_c;
                int nuovaY = y + i_r; // calcolo nuova posizione in base ai dati forniti


                if (nuovaX<0 || nuovaX > Larghezza || nuovaY<0 || nuovaY>Lunghezza){
                    return false; //collisione con i bordi
                }

                if (grid[nuovaX][nuovaY] != ' '){
                    return false; //collisione con un altro pezzo
                }
            }
         }
    }

    return true; // nessuna collisione
}


// Sottostante: operazione di eliminare una riga completa, guarda se fa parte collisioni o salvataggio (??buhhh)

void Griglia::Elimina_Riga(int r){
    for (int i = r; i>0; i--){ // riguardare loop, ma credo sia giusto
        for (int index = 0; index<Larghezza; index++){
            grid [i][index]=grid[i-1][index]; //copia riga sopra nella riga corrente, poichè riga corrente è stata eliminata

        }
    }

    for (int index = 0; index < Larghezza; index++){ // svuota la prima riga (?) RICONTROLLA
        grid[0][index]= ' ';
    }
}

void Griglia::Controllo_Er(){

    for (int i = 0; i<Lunghezza; i++){
        bool complete = true;

        for (int index = 0; index <Larghezza; index ++){
            if (grid[i][index]==' '){
                complete = false; //ci sono pezzi ancora vuoti, non faccio nulla
                break;
            }
        }
        if (complete);{
            Elimina_Riga(i);
            i--; //devo aggiornare indice, rige sopra spostate verso il basso (RICONTROLLA)
        }
    }
}

// fine controllo riga completamente piena

bool Griglia::Posiziona(int x, int y, char tetramino[4][4], int larghezza, int lunghezza, char figura){
    if (!Collisione_Non_Avvenuta(x, y, tetramino, larghezza, lunghezza)){// quindi È AVVENUTA una collisione
        return false; //non riesco a posizionarlo perchè c'è qualcosa in mezzo, quindi mi devo fermare
    }
    for (int indice = 0; indice<lunghezza; indice ++){
        for (int indice_secondario = 0; indice_secondario<larghezza; indice_secondario ++){
           if (tetramino[indice][indice_secondario] != ' '){
             grid[y+indice][x+indice_secondario]=figura; // devo aggiornare in base al tetramino, non mi interessano celle vuote
             }



           
        }
    }
    Controllo_Er();
    return true; //posizionamento avvenuto con successo
}

void Griglia::Svuota_Celle(int x, int y, char tetramino[4][4], int larghezza, int lunghezza){

    for (int index = 0; index<lunghezza; index++){
        for (int index_s = 0; index_s<larghezza; index_s++){// stesso procedimento di prima
             if(tetramino[index][index_s]!= ' '){
                grid[y+index][x+index_s]=' ';
             }
          
        }
    }

} 
// Quando usare questa funzione? Quando si deve spostare un determinato tetramino e si deve svuotare il tutto,
// oppure quando il calcolo delle possibile mosse (...???) RIGUARDA
