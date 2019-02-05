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
        << MenuBusquedaSecuencial << " busqueda secuencial" <<endl
        << MenuBusquedaBinaria << "busqueda binaria" << endl
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

            case MenuBusquedaSecuencial:
                BusquedaSecuencial();
            break;

            case MenuBusquedaBinaria:
                BusquedaBinaria();
            break;

            case MenuSalir:
            break;

            default:
                cout << "Opcion Incorrecta" <<  endl;
        }
    }while(opcion != MenuSalir);
}


void Museo::BusquedaBinaria(){

  for (int i = 0; i< numE -1 ; i++)
    for (int j = 0; j< numE -1 ; j++)
      if (escultura[j+1] < escultura[j]){
          Escultura tmp = escultura[j];
          escultura[j] = escultura[j+1];
          escultura[j+1] = tmp;
      }
}

int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}

void Museo::BusquedaSecuencial(){
    int j,i;
    bool a=false,b=false;
    string elem;
    cout << "nombre de obra que desea buscar" <<endl;
    cin>>elem;
    string aux;

    for(i=0;i<numE;i++){

            if(elem.compare(escultura[i].getNombre())){
                a=true;
                break;
            }
    }
    if(a){
        cout << "nombre " << escultura[i].getNombre() << endl
         << "Material " << escultura[i].getMaterial() << endl
         << "Volumen " << escultura[i].getVolumen() <<endl
         << "Anio " << escultura[i].getAnio() << endl;
    }

    for(j=0;j<numP;j++){
        if(pintura[j].getNombre()==elem){
            b=true;
            break;
        }
    }
    if(b){
        cout << "nombre " << escultura[j].getNombre() << endl
         << "Material " << escultura[j].getMaterial() << endl
         << "Volumen " << escultura[j].getVolumen() <<endl
         << "Anio " << escultura[j].getAnio() << endl;
    }

    if(!a && !b)
        cout << "No Encontrado" <<endl;

}


void Museo:: AgregarPintura(){
    museo obra;
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

        pintura[numP].setNombre(obra.nombre);
        pintura[numP].setAnio(obra.anio);
        pintura[numP].setAncho(obra.ancho);
        pintura[numP].setAlto(obra.alto);
        pintura[numP].setTecnica(obra.tecnica);

    numP++;

}

void  Museo:: AgregarEscultura(){
    museo obra;
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

        escultura[numE].setNombre(obra.nombre);
        escultura[numE].setMaterial(obra.material);
        escultura[numE].setVolumen(obra.volumen);
        escultura[numE].setAnio(obra.anio);

    numE++;
}

void Museo:: ConsultarPinturas(){
    if(!numP){
    cout <<"No hay pinturas" << endl;
    }
    for(int i=0; i<numP; i++){
        cout << "nombre " << pintura[i].getNombre() << endl
         << "anio " << pintura[i].getAnio() << endl
         << "alto " << pintura[i].getAlto() <<endl
         << "ancho " << pintura[i].getAncho() << endl
         << "Tecnica " << pintura[i].getTecnica()  << endl;
    }
}

void Museo:: ConsultarEsculturas(){
    if(!numE){
        cout << "No hay esculturas" << endl;
    }
    for(int i=0; i<numE; i++){
        cout << "nombre " << escultura[i].getNombre() << endl
         << "Material " << escultura[i].getMaterial() << endl
         << "Volumen " << escultura[i].getVolumen() <<endl
         << "Anio " << escultura[i].getAnio() << endl;
    }
}
