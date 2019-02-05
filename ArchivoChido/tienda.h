#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include "ListaEstatica.h"
#include "Producto.h"
#include <fstream>

using namespace std;

class Tienda
{
public:
    Tienda();
    void menu();
    void cargar();
    void guardar(const Producto& prod);
    void agregar();
    void consultar();

    enum
    {
        OPC_AGREGAR = 1,
        OPC_CONSULTAR,
        OPC_SALIR
    };

private:
    ListaEstatica<Producto> productos;
};

#endif // TIENDA_H
