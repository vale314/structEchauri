#ifndef BUSQUEDA_H
#define BUSQUEDA_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Busqueda
{
public:
    Busqueda<T>(): index(0){}
    int secuencial(string );
    int binaria();

  private:
    static const size_t tamanio=30;
    T elements[tamanio];
    size_t index;
};

template<typename T>
int Busqueda<T>::secuencial()
{
    int i;
    for(i = 0; i < tamanio; i++)
    {
    if (lista[i] == clave)
    return i+1;
    }
    return -1;

}

template<typename T>
int Busqueda<T>::binaria()
{
    int izquierdo, derecho, puntomedio;
    izquierdo = 0;
    derecho = tamanio -1;
    while (izquierdo <= derecho)
    {
    puntomedio = (int) ((izquierdo + derecho) / 2);
    if (clave == lista[puntomedio])
    {
    return puntomedio+1;
    }
    else if (clave > lista[puntomedio])
    izquierdo = puntomedio + 1;
    else
    derecho = puntomedio -1;
    }
    return -1;
}


#endif // BUSQUEDA_H

