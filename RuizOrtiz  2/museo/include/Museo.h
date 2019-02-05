#ifndef MUSEO_H
#define MUSEO_H
#include "Escultura.h"
#include "ListaEstatica.h"
#include "Pintura.h"
#include <iostream>

using namespace std;

class Museo
{
    public:
        Museo();
        virtual ~Museo();
        enum Menu{
            MenuAgregarPintura=1,
            MenuAgregarEscultura,
            MenuConsultarPinturas,
            MenuConsultarEsculturas,
            MenuSalir
        };
        struct museo{
            string nombre;
            int alto;
            int ancho;
            float volumen;
            int anio;
            string tecnica;
            string material;
        };
        static const int MAX = 30;
        void menu();
        void AgregarPintura();
        void AgregarEscultura();
        void ConsultarPinturas();
        void ConsultarEsculturas();

    protected:

    private:
        int numP;
        int numE;
        ListaEstatica <Pintura> pintura;
        ListaEstatica <Escultura> escultura;
};

#endif // MUSEO_H
