#include "Blocks.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

/*
wstring tetramino[2];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;
*/


/*
        VISIONE

                Dimensione Tab: 8
                Indentazione: Spazi

        SCOPO

                Questo file è responsabile della manipolazione dei blocchi.
                1.      Rotazione dei blocchi
                2.      Conversione degli oggetti blocco
*/


// Definizioni dei tetramini
/*
#define SHAPE_0  "..#...#...#...#."  // Tetramino rettangolare
#define SHAPE_5  ".....##..##....."  // Tetramino quadrato

#define BLOCK_SHAPE_COUNT       7
#define BLOCK_WIDTH             4
#define BLOCK_WIDTH_SQR         16
#define BLOCK_EMPTY_LINE        "...."
#define DELETE_CHAR             'X'

// Riceve un array di stringhe di lunghezza BLOCK_SHAPE_COUNT
// e riempie tutte le variazioni disponibili dei blocchi in blocks[]
void getBlocksReady(string blocks[BLOCK_SHAPE_COUNT])
{
    // Cancella tutta la spazzatura esistente in blocks[BLOCK_SHAPE_COUNT]
    for (int i = 0; i < BLOCK_SHAPE_COUNT; ++i)
    {
        blocks[i] = "";  // Inizializza ogni elemento dell'array blocks a una stringa vuota
    }

    // Crea i blocchi assegnando le costanti definite in precedenza
    blocks[0] = SHAPE_0;
    blocks[1] = SHAPE_5;
}

// Restituisce l'indice di rimappatura della rotazione di una stringa di blocco
// dall'indice originale (intero i) e l'angolo di rotazione (intero mode)
// Mode 1 = 90 gradi in senso orario, Mode -1 = 90 gradi in senso antiorario
int rotateBlock(int i, int mode)
{
    if (mode == 1)  // 90 gradi in senso orario
    {
        // Calcola l'indice del blocco ruotato di 90 gradi in senso orario
        return 12 - 4 * (i % 4) + (i / 4);
    }
    else if (mode == -1) // 90 gradi in senso antiorario
    {
        // Calcola l'indice del blocco ruotato di 90 gradi in senso antiorario
        return 3 + 4 * (i % 4) - (i / 4);
    }
    return i; // Nessuna rotazione, restituisce l'indice originale
}

// Restituisce una copia ruotata di una stringa di 16 caratteri blockContent
// int rotation: modalità di rotazione, 1 per 90 gradi in senso orario, -1 per 90 gradi in senso antiorario
// blockString bString: stringa di 16 caratteri da ruotare
blockString rotateBlock(int rotation, blockString bString)
{
    string output = "";  // Stringa di output per il blocco ruotato
    for (int j = 0; j < BLOCK_WIDTH_SQR; ++j)
    {
        if (isprint(bString[j]))  // Controlla se il carattere è stampabile
            output += bString[rotateBlock(j, rotation)];  // Aggiunge il carattere ruotato all'output
    }
    return output;  // Restituisce la stringa del blocco ruotato
}

// Converte la blockString in un array di interi da inserire
// nella plancia di gioco
blockMatrix convertToBlockMatrix(block blockShape, int blockNum)
{
    blockMatrix bMatrix;  // Matrice di blocco risultante
    vector<int> row;  // Riga temporanea per costruire la matrice

    for (int i = 0; i < blockShape.ysize; ++i)  // Itera sulle righe del blocco
    {
        for (int j = 0; j < blockShape.xsize; ++j)  // Itera sulle colonne del blocco
        {
            // Controlla se il carattere corrente è un blocco occupato
            if (blockShape.content.substr(i * blockShape.xsize, blockShape.xsize)[j] == OCCUPIED_CHAR)
                row.push_back(blockNum);  // Aggiunge il numero del blocco alla riga
            else
                row.push_back(0);  // Aggiunge uno 0 alla riga per le celle vuote
        }
        bMatrix.push_back(row);  // Aggiunge la riga alla matrice del blocco
        row.clear();  // Pulisce la riga temporanea per la prossima iterazione
    }
    return bMatrix;  // Restituisce la matrice del blocco
}

// Prende una blockString di 16 caratteri e la converte in un oggetto blocco
// blockString bString: La blockString da convertire
block convertBlockStringToBlockObj(blockString bString)
{
    int xsize = BLOCK_WIDTH, ysize = BLOCK_WIDTH;  // Dimensioni iniziali del blocco
    string temp = "";  // Stringa temporanea per il controllo
    string output = bString;  // Stringa di lavoro

    // Controlla colonne vuote
    for (int j = 0; j < BLOCK_WIDTH; ++j)
    {
        for (int i = 0; i < BLOCK_WIDTH; ++i)
        {
            temp.push_back(bString[4 * i + j]);  // Aggiunge il carattere corrente alla stringa temporanea
        }
        if (temp == BLOCK_EMPTY_LINE)  // Se la colonna è vuota
        {
            xsize -= 1;  // Riduce la dimensione in larghezza del blocco
            // Segna i caratteri da eliminare con DELETE CHAR
            for (size_t i = 0; i < BLOCK_WIDTH; ++i)
            {
                output[4 * i + j] = DELETE_CHAR;  // Segna i caratteri della colonna per l'eliminazione
            }
        }
        temp = "";  // Pulisce la stringa temporanea per la prossima iterazione
    }

    // Rimuove i caratteri segnati per l'eliminazione
    output.erase(remove(output.begin(), output.end(), DELETE_CHAR), output.end());
    // Le righe
    // Questo codice è tratto da https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string

    temp = "";  // Stringa temporanea per il controllo delle righe
    string emptyXsizeLine(xsize, '.');  // Crea una stringa di lunghezza xsize composta da punti

    // Controlla righe vuote
    for (int i = 0; i < BLOCK_WIDTH; ++i)
    {
        for (int j = 0; j < xsize; ++j)
        {
            temp.push_back(output[xsize * i + j]);  // Aggiunge il carattere corrente alla stringa temporanea
        }
        if (temp == emptyXsizeLine)  // Se la riga è vuota
        {
            ysize -= 1;  // Riduce la dimensione in altezza del blocco
            // Segna questi caratteri da eliminare con DELETE CHAR
            for (int j = 0; j < xsize; ++j)
            {
                output[xsize * i + j] = DELETE_CHAR;  // Segna i caratteri della riga per l'eliminazione
            }
        }
        temp = "";  // Pulisce la stringa temporanea per la prossima iterazione
    }

    output.erase(remove(output.begin(), output.end(), DELETE_CHAR), output.end());  // Rimuove i caratteri segnati

    // Crea e restituisce l'oggetto blocco con le dimensioni e il contenuto aggiornati
    block result;
    result.ysize = ysize;  // Assegna l'altezza del blocco
    result.xsize = xsize;  // Assegna la larghezza del blocco
    result.content = output;  // Assegna il contenuto del blocco

    return result;  // Restituisce l'oggetto blocco
}
*/
