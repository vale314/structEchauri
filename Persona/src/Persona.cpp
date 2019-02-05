#include "../include/Persona.h"

Persona::Persona()
{
    //ctor
}

Persona::~Persona()
{
    //dtor
}

void Persona:: setNombre(string nombre){
    this->nombre=nombre;
}

void Persona:: setNacionalidad(string nacionalidad){
    this->nacionalidad=nacionalidad;
}

string Persona:: getNombre(){
    return nombre;
}

string Persona:: getNacionalidad(){
    return nacionalidad;
}

ostream& operator <<(ostream& os, const Persona& obj){
    os << "Nombre " << this->obj.getNombre() <<endl <<  "Nacionalidad " << this->obj.getNacionalidad();

    return os;
}
