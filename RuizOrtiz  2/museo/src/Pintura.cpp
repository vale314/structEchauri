#include "Pintura.h"
#include <iostream>

Pintura::Pintura()
{
    //ctor
}

Pintura::~Pintura()
{
    //dtor
}


void Pintura::setAlto(int alto){
    this->alto= alto;
}

void Pintura::setAncho(int ancho){
    this->ancho = ancho;
}

void Pintura::setTecnica(string tecnica){
    this->tecnica = tecnica;
}

int Pintura::getAlto(){
    return alto;
}

int Pintura::getAncho(){
    return ancho;
}

string Pintura::getTecnica(){
    return tecnica;
}


ostream& operator << (ostream& os, const Pintura& obj){
    //Hacemos un cast
    //imprimimos los atrubutos que ya estan en la clase padre
    ObraArte p = (ObraArte) obj;
    os << p << endl
    //os << "Nombre: " << obj.getNombre()
    << "Ancho: " << obj.ancho << "Alto: " <<obj.alto << "Tecnica: "<<obj.tecnica;


    return os;
}
