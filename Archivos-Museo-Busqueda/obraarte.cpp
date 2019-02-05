#include "obraArte.h"
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
