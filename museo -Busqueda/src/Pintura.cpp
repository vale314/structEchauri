#include "Pintura.h"

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
