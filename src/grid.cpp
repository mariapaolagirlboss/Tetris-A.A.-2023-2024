#include <iostream>
#include <ncurses.h>
#include "grid.hpp"
using namespace std;

// Tutto ciò che riguarda la griglia

Griglia::Griglia(){
    Lunghezza = 20;
    Larghezza = 10;
    // GrandezzaCella = 30;
    win = newwin(22,12,1,1);

    if (win==nullptr){
        throw runtime_error("Errore nell'apertura della finestra");
    }

    Inizializza();
    
}

void Griglia::Inizializza(){
 box(win,0,0);
    for (int lungh = 0; lungh<Lunghezza; lungh ++){
        for (int largh= 0; largh<Larghezza; largh++){
            grid[lungh][largh]=' ';//inizialmente avevo posto 0, verifica cosa sia meglio
        }
    }
    wrefresh(win);

}

void Griglia::Stampa(){
    for (int lungh=0; lungh<Lunghezza; lungh++){
        for(int largh = 0; largh<Larghezza; largh++){
            mvwaddch (win, lungh+1, largh+1, grid[lungh][largh]);

        }
    }
    wrefresh(win);
} //controlla funzioni stampa



// eliminazione verifica_posizione, non serviva a nulla

void Griglia::Fissa_In_Cella(int x, int y, char tetramino[4][4], int larghezza, int altezza){
    for (int i_r = 0; i_r<altezza; i_r++){
        for (int i_c = 0; i_c<larghezza; i_c ++){
            if (tetramino[i_r][i_c] != ' '){
                int nuovaX = x + i_c;
                int nuovaY = y + i_r;

                if (nuovaX>=0 && nuovaX < Larghezza && nuovaY >=0 && nuovaY < Lunghezza){
                    grid[nuovaY][nuovaX] = tetramino[i_r][i_c];
                }
            }
        }
    }
    
}

// Tutto ciò che riguarda le collisioni

bool Griglia::Collisione_Non_Avvenuta(int x, int y, char tetramino[4][4], int larghezza, int altezza){
    for (int i_r = 0; i_r<altezza; i_r++){ // i_r = indice della riga del tetramino
         for (int i_c = 0; i_c<larghezza; i_c++){ // i_c = indice della colonna del tetramino
            if (tetramino[i_r][i_c] != ' ') {
                int nuovaX = x + i_c;
                int nuovaY = y + i_r; // calcolo nuova posizione in base ai dati forniti


                if (nuovaX<0 || nuovaX >= Larghezza || nuovaY>=Lunghezza){
                    return false; //collisione con i bordi
                }

                if (nuovaY >=0 && grid[nuovaY][nuovaX] != ' '){
                    return false; //collisione con un altro pezzo

                    // controlla tetramino sia in Collisione_Non_Avvenuta che in Fissa_In_Cella, potrebbe esserci inversione
                }
            }
         }
    }

    return true; // nessuna collisione
}


// Sottostante: operazione di eliminare una riga completa, guarda se fa parte collisioni o salvataggio (??buhhh)

void Griglia::Check_Righe (){
    for (int index_righe = Lunghezza -1; index_righe >=0; ){
        bool complete = true;

        // primo controllo, vedo se riga è piena oppure no
        for (int primo = 0; primo<Larghezza; primo ++){
            if (grid[index_righe][primo]==' '){
                complete = false;
                break;
            }
        }
        if (complete){ // se la linea è invece completa (complete = true), devo effettuare l'eliminazione
         for (int secondo = index_righe; secondo >0; secondo--){ //sposto verso basso le righe
            for (int secondo_s = 0; secondo_s <Larghezza; secondo_s ++){
                grid[secondo][secondo_s]=grid[secondo-1][secondo_s];

            }
         }
         for (int j=0; j<Larghezza; j++){
            grid[0][j] = ' '; // ho svuotato prima riga
         }
         
        } else {
           index_righe--; //  non decrementare qua, devo controllare anche nuova posizione poichè ora contiene nuova riga
        }
    }
}
// fine controllo riga completamente piena

bool Griglia::Posiziona(int x, int y, char tetramino[4][4], int larghezza, int altezza){
    if (!Collisione_Non_Avvenuta(x, y, tetramino, larghezza, altezza)){// quindi È AVVENUTA una collisione
        return false; //non riesco a posizionarlo perchè c'è qualcosa in mezzo, quindi mi devo fermare
    }
    Fissa_In_Cella(x,y,tetramino,larghezza,altezza);
    Check_Righe();
    return true; //posizionamento avvenuto con successo
}

void Griglia::Svuota_Celle(int x, int y, char tetramino[4][4], int larghezza, int altezza){

    for (int index = 0; index<altezza; index++){
        for (int index_s = 0; index_s<larghezza; index_s++){// stesso procedimento di prima
             if(tetramino[index][index_s]!= ' '){
                int posizione_x= x + index_s;
                int posizione_y= y + index;

                if (posizione_x >=0 && posizione_x < Larghezza && posizione_y>=0 && posizione_y < Lunghezza) {
                    grid[posizione_y][posizione_x] = ' '; // solo se valido svuoto cella, potrebbe andare in segmentation fault
                }
             }
          
        }
    }

} 
// Quando usare questa funzione? Quando si deve spostare un determinato tetramino e si deve svuotare il tutto,
// oppure quando il calcolo delle possibile mosse (...???) RIGUARDA, UTILE PER AGGIORNARE POSIZIONE DI UN PEZZO IN MOVIMENTO

// distruttore 
Griglia::~Griglia() throw() {
    if (win != nullptr) {
        delwin(win);  
    }
}
