#ifndef TETRIS_CPP_BLOCK_H
#define TETRIS_CPP_BLOCK_H






#include <string>
#include <vector>

// Classe base per rappresentare un blocco
class Block {
protected:
    int xsize;  // Larghezza del blocco
    int ysize;  // Altezza del blocco
    std::string content;  // Contenuto del blocco

public:
    Block();  // Costruttore di default
    Block(int x, int y, const std::string& cont);  // Costruttore con parametri

    // Metodi per ottenere le dimensioni del blocco
    int getXSize() const;
    int getYSize() const;

    // Metodo per ottenere il contenuto del blocco
    std::string getContent() const;

    // Metodo per ruotare il blocco
    virtual void rotate(int rotation);

    // Metodo per convertire il blocco in una matrice di numeri
    std::vector<std::vector<int> > convertToMatrix(int blockNum) const;

    // Metodo per convertire la stringa del blocco in un oggetto Block
    static Block convertFromString(const std::string& bString);
};

#endif //TETRIS_CPP_BLOCK_H













// codice più pulito? confronta con quello sopra
/*
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>

// Classe base per rappresentare un tetramino
class Block {
public:
    // Costruttore che inizializza il blocco con una forma specifica
    Block(const std::string& shape);

    // Metodo per ottenere il contenuto del blocco come stringa
    std::string getContent() const;

    // Metodo per ruotare il blocco
    void rotate(int rotation);

protected:
    std::string content; // Contenuto del blocco come stringa
    int xsize;           // Dimensione orizzontale del blocco
    int ysize;           // Dimensione verticale del blocco

    // Metodo protetto per impostare le dimensioni del blocco
    void setDimensions();

    // Metodo protetto per calcolare l'indice del carattere ruotato
    int rotateIndex(int i, int mode) const;
};

#endif // BLOCK_HPP
*/
