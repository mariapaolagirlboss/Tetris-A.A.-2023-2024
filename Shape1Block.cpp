//
// Created by Gaia Righi on 06/08/24.
//

#include "Shape1Block.h"






Shape1Block::Shape1Block() : Block() {}

Shape1Block::Shape1Block(const std::string& cont) : Block(4, 4, cont) {}

void Shape1Block::rotate(int rotation) {
    // I blocchi di forma 5 non cambiano con la rotazione, quindi non fare nulla
}




//Idem con l'altro tetramino
// Costruttore che inizializza la forma del tetramino Shape5
//Shape1Block::Shape1Block() : Block(".....##..##.....") {
    // La forma è predefinita nel costruttore della classe base
//}
