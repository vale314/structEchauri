#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include "ListaEstatica.h"
#include "Producto.h"
#include <fstream>
#include <string.h>

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
    void buscar();
    void vender();
    int buscar(string);
    void borrarDocumento();
    void cargarADocumento();
    void drop();
    enum
    {
        OPC_AGREGAR = 1,
        OPC_CONSULTAR,
        OPC_BUSCAR,
        OPC_VENDER,
        OPC_ELIMINAR,
        OPC_SALIR
    };

private:
    ListaEstatica<Producto> productos;
};

#endif // TIENDA_H
