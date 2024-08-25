#ifndef CLASSIFICA_HPP
#define CLASSIFICA_HPP

#include <vector>
#include <string>

class Classifica {
private:
    std::vector<int> punteggi;  // Vettore che contiene i punteggi
    std::string nomeFile;       // Nome del file dove i punteggi sono salvati

public:
    // Costruttore: inizializza la classifica e carica i punteggi dal file
    Classifica(const std::string& file);

    // Aggiunge un nuovo punteggio e lo salva nel file
    void aggiungiPunteggio(int punteggio);

    // Mostra la classifica ordinata in modo decrescente
    void mostraClassifica() const;

private:
    // Carica i punteggi dal file
    void caricaPunteggi();

    // Salva i punteggi nel file
    void salvaPunteggi() const;
};

#endif // CLASSIFICA_HPP
