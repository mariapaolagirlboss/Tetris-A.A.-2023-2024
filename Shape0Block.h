#ifndef TETRIS_CPP_SHAPE0BLOCK_H
#define TETRIS_CPP_SHAPE0BLOCK_H






#include "Block.h"

// Classe derivata per il blocco di forma 0 (SHAPE_0)
class Shape0Block : public Block {
public:
    Shape0Block();  // Costruttore di default
    Shape0Block(const std::string& cont);  // Costruttore con parametri

    // Implementazione della rotazione specifica per il blocco di forma 0
    void rotate(int rotation) override;
};

#endif //TETRIS_CPP_SHAPE0BLOCK_H









//Codice più pulito?? non lo so, confronta
/*#include "Block.h"

// Classe derivata per rappresentare un tetramino di forma 0
class Shape0Block : public Block {
public:
    // Costruttore che definisce la forma del tetramino Shape0
    Shape0Block();
};

#endif //TETRIS_CPP_SHAPE0BLOCK_H*/

