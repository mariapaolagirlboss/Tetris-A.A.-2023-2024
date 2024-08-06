#ifndef TETRIS_CPP_SHAPE1BLOCK_H
#define TETRIS_CPP_SHAPE1BLOCK_H





#include "Block.h"

// Classe derivata per il blocco di forma 1 (SHAPE_1)
class Shape1Block : public Block {
public:
    Shape1Block();  // Costruttore di default
    Shape1Block(const std::string& cont);  // Costruttore con parametri

    // Implementazione della rotazione specifica per il blocco di forma 5
    void rotate(int rotation) override;
};

#endif // TETRIS_CPP_SHAPE1BLOCK_H










//stessa cosa dell'altro tetramino
/*
#include "Block.h"

// Classe derivata per rappresentare un tetramino di forma 5
class Shape5Block : public Block {
public:
    // Costruttore che definisce la forma del tetramino Shape5
    Shape5Block();
};

#endif // TETRIS_CPP_SHAPE1BLOCK_H
*/

