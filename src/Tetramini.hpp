#ifndef TETRAMINI_HPP
#define TETRAMINI_HPP

struct Forma{
    int quadrato = 0;
    int rettangolo = 1;
};

class Tetramini{
protected: 
    Forma forme[2];
    char matrice[4][4]; 
    int x; 
    int y; 

    void generaMatrice(); 

public:
    Tetramini(Forma f[]);/*{
        for(int i=0; i<2; i++){ 
            forme[i] = f[i];
        }
        x = 0;
        y = 0;
        generaMatrice();
    };*/ //forse il costruttore va implementato nel file .cpp

    const char* const* getMatrice() const;
    void ruota_senso_orario();
    void ruota_senso_antiorario();

    const int getX();
    const int getY();
    void sposta_sinistra();
    void sposta_destra();
    void scendi(); 
};

#endif
