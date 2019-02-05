#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
}

Enemigo::~Enemigo()
{
    //dtor
}

int Enemigo::getFuerza() const{
    return fuerza;
}
void Enemigo::setFuerza(int value){
    fuerza=value;
}

int Enemigo::getEnergia() const{
    return energia;
}
void Enemigo::setEnergia(int value){
    energia=value;
}

string Enemigo::getAtaque() const{
    return ataque;
}
void Enemigo::setAtaque(const string &value){
    ataque=value;
}
