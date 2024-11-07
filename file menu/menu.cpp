#include <iostream>
#include <cstring>
#include "classifica.hpp"
#include "menu.hpp"

using namespace std;

menu::menu(Classifica& ClassificaRef) : classifica(ClassificaRef){} // riguarda

void mostramenu(){
    int scelta;


    do {

    cout<< "0. Nuova partita"<<endl;
    cout<<"1. Visualizza classifica"<<endl;
    cout<<"Inserisci la tua scelta: "<<endl;
    
    cin>>scelta;

    switch (scelta){
        case 0:
        cout<<"Inizio nuova partita";
        void avviopartita();
        break;

        case 1:
        void mostraclassifica();
        break;

        default: // c'è un caso che non è compatibile
        cout<<"Scelta non valida, per favore inserisci 0 o 1!"<<endl;
        
    }
    }while (scelta!=0 && scelta !=1);
    

}

void menu::avviopartita(){
    //aggiungi punteggio iniziale 0 che poi aumenterà, capire se nel file Greta oppure no
}

void menu::visualclassifica(){
    Classifica.mostraClassifica(); // funzione nel file di Greta, errore???
}
int main (){
    Classifica classifica ("punteggi.txt");

    menu menu(classifica);

    menu.mostramenu();

    return 0;

    
}