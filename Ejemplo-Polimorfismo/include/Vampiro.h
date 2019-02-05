#ifndef VAMPIRO_H
#define VAMPIRO_H
#include "Enemigo.h"
#include <iostream>

using namespace std;

class Vampiro : public Enemigo
{
    public:
        Vampiro();
        virtual ~Vampiro();
        void atacar();

    protected:

    private:
};

#endif // VAMPIRO_H
