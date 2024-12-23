#ifndef MENU_HPP
#define MENU_HPP

#include "Classifica.hpp"
#include <iostream>

using namespace std;

class menu {

    private:
    Classifica& classifica; //riguarda, dubbio!
    void avviopartita(); // creala! ha a che fare con salvataggio file?
    void visualclassifica(); //riguarda file Greta

    public:
    void mostramenu(); //per utente
    menu(Classifica& classificaref); //identico dubbio, riguarda ppt classi e costruttori
    

};


#endif 
