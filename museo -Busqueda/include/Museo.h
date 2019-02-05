#ifndef MUSEO_H
#define MUSEO_H
#include "Pintura.h"
#include "Escultura.h"
#include <iostream>
#include <string>

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
            MenuBusquedaSecuencial,
            MenuBusquedaBinaria,
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

        friend bool operator==(Escultura& lhs,string rhs)
        {
            if(!rhs.compare(lhs.getNombre()))
                return true;
            else
                return false;
        }


        void BusquedaBinaria();
        void BusquedaSecuencial();

    protected:

    private:
        int numP;
        int numE;
        Escultura escultura[MAX];
        Pintura pintura[MAX];
};

#endif // MUSEO_H
