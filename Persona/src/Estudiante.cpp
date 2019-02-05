#include "../include/Estudiante.h"

Estudiante::Estudiante()
{
    //ctor
}

Estudiante::~Estudiante()
{
    //dtor
}

int Estudiante:: getCodigo()const{
    return codigo;
}

void Estudiante:: setCodigo(int value){
    codigo = value;
}

ostream& operator << (ostream& os, const Estudiante& obj){
    //Hacemos un cast
    //imprimimos los atrubutos que ya estan en la clase padre
    Persona p = (Persona) obj;
    os << p << endl
    //os << "Nombre: " << obj.getNombre()
    << "Codigo: " << obj.codigo;


    return os;
}
