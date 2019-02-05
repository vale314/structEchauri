#include "Vampiro.h"

Vampiro::Vampiro()
{
    setEnergia(50);
    setFuerza(6);
    setAtaque("Chupa vida");
}

Vampiro::~Vampiro()
{
    //dtor
}

void Vampiro:: atacar(){
    cout << "Vampiro ha usuado " << getAtaque() << endl;
}

