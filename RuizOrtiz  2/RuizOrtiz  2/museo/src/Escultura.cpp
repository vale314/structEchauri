#include "Escultura.h"
#include <iostream>

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



ostream& operator << (ostream& os, const Escultura& obj){
    //Hacemos un cast
    //imprimimos los atrubutos que ya estan en la clase padre
    ObraArte p = (ObraArte) obj;
    os << p << endl
    //os << "Nombre: " << obj.getNombre()
    << "Volumen: " << obj.volumen << "Material: " <<obj.material;


    return os;
}
