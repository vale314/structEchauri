#include "Zombie.h"

Zombie::Zombie()
{
    setEnergia(30);
    setFuerza(5);
    setAtaque("Mordizco");
}

Zombie::~Zombie()
{
    //dtor
}

void Zombie::atacar()
{
    cout << "Zombie ha usado " << getAtaque() << endl;
}
