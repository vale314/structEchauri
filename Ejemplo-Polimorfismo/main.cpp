#include <iostream>
#include "Enemigo.h"
#include "Zombie.h"
#include "Vampiro.h"

using namespace std;

int main()
{
    Enemigo* enemigos[2];
    Zombie*  zombie;
    //zombie.atacar();
    zombie = new Zombie();

    Vampiro* vampiro;
    //vampiro.atacar();
    vampiro = new Vampiro();

    enemigos[0] = vampiro;
    enemigos[1] = zombie;

    enemigos[0] -> atacar();
    enemigos[1] -> atacar();
    return 0;
}
