#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Enemigo.h"
#include <iostream>

using namespace std;

class Zombie : public Enemigo
{
    public:
        Zombie();
        virtual ~Zombie();
        void atacar();

    protected:

    private:
};

#endif // ZOMBIE_H
