#include "Tetramini.hpp"

Tetramini::Tetramini(int tipo_forma){
    if(tipo_forma == QUADRATO || tipo_forma == RETTANGOLO){
        forma = tipo_forma;
    }else{
        forma = QUADRATO;
    }
    x = 0;
    y = 0;
    generaMatrice();
}

const char (&Tetramini::getMatrice() const)[4][4]{
    return matrice;
}


void Tetramini::ruota_senso_orario(){
    char tmp[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            tmp[j][3-i] = matrice[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrice[i][j] = tmp[i][j];
        }
    }
}

void Tetramini::ruota_senso_antiorario(){
    char tmp[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            tmp[3-j][i] = matrice[i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrice[i][j] = tmp[i][j];
        }
    }
}

const int Tetramini::getX(){
    return x;
}

const int Tetramini::getY(){
    return y;
}

void Tetramini::sposta_sinistra(){
    x--;
}

void Tetramini::sposta_destra(){
    x++;
}

void Tetramini::scendi(){
    y++;
}

void Tetramini::generaMatrice(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrice[i][j] = ' ';
        }
    }

    if(forma == QUADRATO){ 
        matrice[1][1] = '#';
        matrice[1][2] = '#';
        matrice[2][1] = '#';
        matrice[2][2] = '#';
    }else if(forma == RETTANGOLO){ 
        matrice[1][0] = '#';
        matrice[1][1] = '#';
        matrice[1][2] = '#';
        matrice[1][3] = '#';
    }
}