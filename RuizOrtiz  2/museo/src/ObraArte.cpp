#include "ObraArte.h"
#include <iostream>

using namespace std;

ObraArte::ObraArte()
{
    //ctor
}

ObraArte::~ObraArte()
{
    //dtor
}


string ObraArte::getNombre(){
    return nombre;
}

int ObraArte::getAnio(){
    return anio;
}

void ObraArte::setAnio(int anio){
    this->anio = anio;
}
void ObraArte::setNombre(string nombre){
    this->nombre = nombre;
}
ostream& operator <<(ostream& os, const ObraArte& obj){
    os << "Nombre " << obj.nombre <<endl <<  "Anio " << obj.anio << endl;

    return os;
}
