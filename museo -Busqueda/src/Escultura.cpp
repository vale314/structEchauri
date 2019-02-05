#include "Escultura.h"

Escultura::Escultura()
{
    //ctor
}

Escultura::~Escultura()
{
    //dtor
}


void Escultura::setVolumen(float  volumen){
    this->volumen = volumen;
}

void Escultura::setMaterial(string material){
    this->material = material;
}


float Escultura::getVolumen(){
    return volumen;
}

string Escultura::getMaterial(){
    return material;
}
