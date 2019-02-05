#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Producto
{
public:
    Producto();
    Producto(const string& linea);

    string getNombre() const;
    void setNombre(const string &value);

    int getCantidad() const;
    void setCantidad(int value);

    float getPrecio() const;
    void setPrecio(float value);

    friend ostream& operator<< (ostream &os, const Producto& obj);

private:
    string nombre;
    int cantidad;
    float precio;


};

#endif // PRODUCTO_H
