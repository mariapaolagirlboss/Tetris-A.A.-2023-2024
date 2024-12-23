//
// Created by Greta La China on 25/08/24.
//
#include "Classifica.hpp"
#include <fstream>
#include <algorithm>
#include <ncurses.h>

// Costruttore: inizializza la classifica e carica i punteggi dal file
Classifica::Classifica(const std::string& file) : nomeFile(file) {
    caricaPunteggi();
}

// Aggiunge un nuovo punteggio e lo salva nel file
void Classifica::aggiungiPunteggio(int punteggio) {
    punteggi.push_back(punteggio);
    salvaPunteggi();
}

// Mostra la classifica ordinata in modo decrescente
void Classifica::mostraClassifica() const {
    clear();
    mvprintw(0, 0, "Classifica:");

    if (punteggi.empty()) {
        mvprintw(2, 0, "Non ci sono punteggi da visualizzare.");
    } else {
        std::vector<int> classifica = punteggi;
        std::sort(classifica.rbegin(), classifica.rend()); // Ordinamento discendente

        for (size_t i = 0; i < classifica.size(); ++i) {
            mvprintw(2 + i, 0, "%d. %d punti", static_cast<int>(i + 1), classifica[i]);
        }
    }

    mvprintw(10, 0, "Premi un tasto per tornare al menu...");
    getch();
}

// Carica i punteggi dal file
void Classifica::caricaPunteggi() {
    std::ifstream file(nomeFile);
    if (file.is_open()) {
        int punteggio;
        while (file >> punteggio) {
            punteggi.push_back(punteggio);
        }
        file.close();
    }
}

// Salva i punteggi nel file
void Classifica::salvaPunteggi() const {
    std::ofstream file(nomeFile);
    if (file.is_open()) {
        for (int punteggio : punteggi) { 
            file << punteggio << std::endl;
        }
        file.close();
    }
}
