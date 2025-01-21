#ifndef TETRAMINI_HPP
#define TETRAMINI_HPP
#define QUADRATO 0
#define RETTANGOLO 1

class Tetramini{
protected: 
    int forma;
    char matrice[4][4]; 
    int x; 
    int y; 

    void generaMatrice(); 

public:
    Tetramini(int tipo_forma);

    const char (&getMatrice() const)[4][4];
    void ruota_senso_orario();
    void ruota_senso_antiorario();

    const int getX();
    const int getY();
    void sposta_sinistra();
    void sposta_destra();
    void scendi(); 
};

#endif