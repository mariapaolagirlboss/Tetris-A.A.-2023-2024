#include "Block.h"
#include <ncurses.h>
#include <algorithm>
#include <cctype>

Block::Block() : xsize(0), ysize(0), content("") {}

Block::Block(int x, int y, const std::string& cont) : xsize(x), ysize(y), content(cont) {}

int Block::getXSize() const {
    return xsize;
}

int Block::getYSize() const {
    return ysize;
}

std::string Block::getContent() const {
    return content;
}

void Block::rotate(int rotation) {
    std::string rotatedContent = "";
    if (rotation == 1) {
        // Rotazione di 90 gradi in senso orario
        for (int j = 0; j < xsize; ++j) {
            for (int i = ysize - 1; i >= 0; --i) {
                rotatedContent += content[i * xsize + j];
            }
        }
    } else if (rotation == -1) {
        // Ruotazione di 90 gradi in senso antiorario
        for (int j = xsize - 1; j >= 0; --j) {
            for (int i = 0; i < ysize; ++i) {
                rotatedContent += content[i * xsize + j];
            }
        }
    }
    content = rotatedContent;
    std::swap(xsize, ysize);
}

std::vector<std::vector<int> > Block::convertToMatrix(int blockNum) const {
    std::vector<std::vector<int> > matrix(ysize, std::vector<int>(xsize, 0));
    for (int i = 0; i < ysize; ++i) {
        for (int j = 0; j < xsize; ++j) {
            if (content[i * xsize + j] != '.') {
                matrix[i][j] = blockNum;
            }
        }
    }
    return matrix;
}

Block Block::convertFromString(const std::string& bString) {
    int xsize = 4, ysize = 4;  // Dimensioni iniziali del blocco
    std::string temp = "";  // Stringa temporanea per il controllo
    std::string output = bString;  // Stringa di lavoro

    // Controlla colonne vuote
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            temp.push_back(bString[4 * i + j]);  // Aggiunge il carattere corrente alla stringa temporanea
        }
        if (temp == "....")  // Se la colonna è vuota
        {
            xsize -= 1;  // Riduce la dimensione in larghezza del blocco
            // Segna i caratteri da eliminare con DELETE_CHAR
            for (size_t i = 0; i < 4; ++i) {
                output[4 * i + j] = 'X';  // Segna i caratteri della colonna per l'eliminazione
            }
        }
        temp = "";  // Pulisce la stringa temporanea per la prossima iterazione
    }

    // Rimuove i caratteri segnati per l'eliminazione
    output.erase(remove(output.begin(), output.end(), 'X'), output.end());
    // Le righe
    temp = "";  // Stringa temporanea per il controllo delle righe
    std::string emptyXsizeLine(xsize, '.');  // Crea una stringa di lunghezza xsize composta da punti

    // Controlla righe vuote
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < xsize; ++j) {
            temp.push_back(output[xsize * i + j]);  // Aggiunge il carattere corrente alla stringa temporanea
        }
        if (temp == emptyXsizeLine)  // Se la riga è vuota
        {
            ysize -= 1;  // Riduce la dimensione in altezza del blocco
            // Segna questi caratteri da eliminare con DELETE_CHAR
            for (int j = 0; j < xsize; ++j) {
                output[xsize * i + j] = 'X';  // Segna i caratteri della riga per l'eliminazione
            }
        }
        temp = "";  // Pulisce la stringa temporanea per la prossima iterazione
    }

    output.erase(remove(output.begin(), output.end(), 'X'), output.end());  // Rimuove i caratteri segnati

    // Crea e restituisce l'oggetto blocco con le dimensioni e il contenuto aggiornati
    return Block(xsize, ysize, output);
}








//Codice èiù pulito? confronta con quello sopra
/*
#include <algorithm>

// Costruttore che inizializza il blocco con una forma specifica e imposta le dimensioni
Block::Block(const std::string& shape) : content(shape), xsize(4), ysize(4) {
    setDimensions(); // Imposta le dimensioni del blocco in base al contenuto
}

// Restituisce il contenuto del blocco come stringa
std::string Block::getContent() const {
    return content;
}

// Ruota il blocco in base alla modalità di rotazione (1 = orario, -1 = antiorario)
void Block::rotate(int rotation) {
    std::string rotatedContent = content; // Crea una copia del contenuto per la rotazione
    for (int j = 0; j < 16; ++j) { // Itera su ogni carattere del blocco
        rotatedContent[j] = content[rotateIndex(j, rotation)]; // Calcola l'indice ruotato
    }
    content = rotatedContent; // Aggiorna il contenuto con quello ruotato
}

// Imposta le dimensioni del blocco rimuovendo righe e colonne vuote
void Block::setDimensions() {
    std::string temp; // Stringa temporanea per il controllo delle righe e colonne
    std::string emptyLine(4, '.'); // Stringa di linea vuota per il confronto

    // Rimuove le colonne vuote
    for (int j = 0; j < 4; ++j) {
        temp.clear();
        for (int i = 0; i < 4; ++i) {
            temp.push_back(content[4 * i + j]); // Costruisce la colonna corrente
        }
        if (temp == emptyLine) { // Se la colonna è vuota
            --xsize; // Riduce la dimensione orizzontale
            for (int i = 0; i < 4; ++i) {
                content[4 * i + j] = 'X'; // Segna i caratteri della colonna per l'eliminazione
            }
        }
    }

    // Rimuove i caratteri segnati
    content.erase(std::remove(content.begin(), content.end(), 'X'), content.end());

    // Rimuove le righe vuote
    temp.clear();
    std::string emptyXsizeLine(xsize, '.');
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < xsize; ++j) {
            temp.push_back(content[xsize * i + j]);
        }
        if (temp == emptyXsizeLine) {
            --ysize; // Riduce la dimensione verticale
            for (int j = 0; j < xsize; ++j) {
                content[xsize * i + j] = 'X'; // Segna i caratteri della riga per l'eliminazione
            }
        }
        temp.clear();
    }

    // Rimuove i caratteri segnati
    content.erase(std::remove(content.begin(), content.end(), 'X'), content.end());
}

// Calcola l'indice del carattere ruotato in base alla modalità di rotazione
int Block::rotateIndex(int i, int mode) const {
    if (mode == 1) { // Rotazione di 90 gradi in senso orario
        return 12 - 4 * (i % 4) + (i / 4);
    } else if (mode == -1) { // Rotazione di 90 gradi in senso antiorario
        return 3 + 4 * (i % 4) - (i / 4);
    }
    return i; // Nessuna rotazione
}
*/
