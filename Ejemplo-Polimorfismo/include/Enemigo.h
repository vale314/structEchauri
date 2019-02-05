#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>

using namespace std;



class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();

        int getFuerza() const;
        void setFuerza(int value);

        int getEnergia() const;
        void setEnergia(int value);

        string getAtaque() const;
        void setAtaque(const string &value);

        virtual void atacar() =0;

    protected:

    private:
        int fuerza;
        int energia;
        string ataque;
};

#endif // ENEMIGO_H
