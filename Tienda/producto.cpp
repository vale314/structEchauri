#include "Producto.h"

Producto::Producto()
{

}

Producto::Producto(const string &linea)
{
    string aux;
    stringstream stream(linea);

    getline(stream,aux,'|');
    nombre=aux;
    getline(stream,aux,'|');
    cantidad=stoi(aux);
    getline(stream,aux);
    precio=stof(aux);
}

string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(const string &value)
{
    nombre = value;
}

int Producto::getCantidad() const
{
    return cantidad;
}

void Producto::setCantidad(int value)
{
    cantidad = value;
}

float Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(float value)
{
    precio = value;
}


ostream& operator<<(ostream& os, const Producto& obj)
{
    os << obj.getNombre() << "|" << obj.getCantidad() << "|" << obj.getPrecio() << endl;

    return os;
}
