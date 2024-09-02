#include "Shape0Block.h"






Shape0Block::Shape0Block() : Block() {}

Shape0Block::Shape0Block(const std::string& cont) : Block(4, 4, cont) {}

void Shape0Block::rotate(int rotation) {
    Block::rotate(rotation);  // Utilizza l'implementazione di base della rotazione
}






//conftonta con il codice più in alto
// Costruttore che inizializza la forma del tetramino Shape0
//Shape0Block::Shape0Block() : Block("..#...#...#...#.") {
    // La forma è predefinita nel costruttore della classe base
//}
