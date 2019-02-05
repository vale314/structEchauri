#ifndef MUSEO_H
#define MUSEO_H
#include "Pintura.h"
#include "Escultura.h"
#include <iostream>
#include <string>
#include <fstream> /*Manejar el archivo*/
#include <vector>

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

        struct EsculturaS{
            string nombre;
            string material;
            int volumen;
            int anio;
        };

        struct PinturaS{
           string nombre;
           int anio;
           string tecnica;
           int ancho;
           int alto;
        };

        void BusquedaBinaria();
        void BusquedaSecuencial();
        void guardar( Escultura& obj);
        void guardar( Pintura& obj);
        void cargar();
        void comprar();
        friend ostream& operator <<(ostream& os,const Pintura &obj);
        friend ostream& operator <<(ostream& os,const Escultura &obj);

    protected:

    private:
        int numP;
        int numE;
        vector <Escultura> esculturas;
        vector <Pintura> pinturas;
};

#endif // MUSEO_H
