#include "Museo.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Museo::Museo()
{
    numP=0;
    numE=0;
}

Museo::~Museo()
{
    //dtor
}

void Museo:: menu(){
    int opcion;
    do{
        cout <<MenuAgregarPintura << "Agregar Pintura" <<endl
        << MenuAgregarEscultura <<"Agregar Escultura" << endl
        << MenuConsultarPinturas <<"Consultar Pintura" << endl
        << MenuConsultarEsculturas <<"Consultar Escultura" << endl
        << MenuSalir <<"Salir" << endl;
        cin >>  opcion ;
        switch(opcion){
            case MenuAgregarPintura:
                AgregarPintura();
            break;

            case MenuAgregarEscultura:
                AgregarEscultura();
            break;

            case MenuConsultarPinturas:
                ConsultarPinturas();
            break;

            case MenuConsultarEsculturas:
                ConsultarEsculturas();
            break;

            case MenuSalir:
            break;

            default:
                cout << "Opcion Incorrecta" <<  endl;
        }
    }while(opcion != MenuSalir);
}


void Museo:: AgregarPintura(){
    museo obra;
    Pintura pin;
    if(numP > 30){
        cout << "Pintura Llenas" << endl;
        return;
    }
        cin.ignore();
        cout << "Ingrese el nombre" << endl;
        getline(cin, obra.nombre);
        cout << "Ingrese el anio" << endl;
        cin >> obra.anio;
        cin.ignore();
        cout << "Ingrese el ancho" << endl;
        cin >>  obra.ancho;
        cin.ignore();
        cout << "Ingrese el alto" << endl;
        cin >> obra.alto;
        cin.ignore();
        cout << "Ingrese la tecnica" << endl;
        getline(cin,obra.tecnica);

        pin.setNombre(obra.nombre);
        pin.setAnio(obra.anio);
        pin.setAncho(obra.ancho);
        pin.setAlto(obra.alto);
        pin.setTecnica(obra.tecnica);

        this->pintura._insert(pin);
}

void  Museo:: AgregarEscultura(){
    museo obra;
    Escultura esc;
    if(numP > 30){
        cout<< "Obras Llenas" << endl;
        return;
    }
        cin.ignore();
        cout << "Ingrese el nombre" << endl;
        getline(cin, obra.nombre);
        cout << "Ingrese el anio" << endl;
        cin >> obra.anio;
        cin.ignore();

        cout << "Ingrese la material" << endl;
        getline(cin,obra.material);

        cout << "Ingrese el volumen" << endl;
        cin >>  obra.volumen;

        esc.setNombre(obra.nombre);
        esc.setMaterial(obra.material);
        esc.setVolumen(obra.volumen);
        esc.setAnio(obra.anio);

        this->escultura._insert(esc);
}

void Museo:: ConsultarPinturas(){
    if(!pintura._size()){
    cout <<"No hay pinturas" << endl;
    }
    for(int i=0; i<pintura._size(); i++){
        cout <<  pintura[i] << endl;
    }
}

void Museo:: ConsultarEsculturas(){
    if(!escultura._size()){
        cout << "No hay esculturas" << endl;
    }
    for(int i=0; i<escultura._size(); i++){
        cout << escultura[i] <<  endl;
    }
}
