#include "escultura.h"

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

ostream& operator <<(ostream& os,const Escultura &obj){
    os << obj.material <<"|"
       << obj.volumen <<"|"
       << obj<<endl;
       return os;
}


float Escultura::getVolumen(){
    return volumen;
}

string Escultura::getMaterial(){
    return material;
}
