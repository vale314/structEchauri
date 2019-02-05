#include "Museo.h"
#include "Museo.h"
#include "museo.h"
#include "museo.h"
#include "museo.h"
#include "museo.h"
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


void Museo::guardar(Escultura& obj){
    //(nameFile,modo de apertura)
    ofstream archivo("album.txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivo << obj;
    archivo.close();
}

void Museo::guardar(Pintura& obj){
    //(nameFile,modo de apertura)
    ofstream archivo("pintura.txt", ios::app);

    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    archivo << obj;
    archivo.close();
}

void Museo::cargar(){
    ifstream archivo("album.txt");
    string linea;
    if(!archivo.is_open()){
        cout <<" No se pudo abrir el archivo";
        return;
    }
    while(getline(archivo,linea)){
        //Escultura s(linea);
        //esculturas.push_back(s);
    }
}

void Museo::comprar(){

}




void Museo::BusquedaBinaria(){

  for (int i = 0; i< numE -1 ; i++)
    for (int j = 0; j< numE -1 ; j++)
      if (esculturas[j+1] < esculturas[j]){
          Escultura tmp = esculturas[j];
          esculturas[j] = esculturas[j+1];
          esculturas[j+1] = tmp;
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

            if(elem.compare(esculturas[i].getNombre())){
                a=true;
                break;
            }
    }
    if(a){
        cout << "nombre " << esculturas[i].getNombre() << endl
         << "Material " << esculturas[i].getMaterial() << endl
         << "Volumen " << esculturas[i].getVolumen() <<endl
         << "Anio " << esculturas[i].getAnio() << endl;
    }

    for(j=0;j<numP;j++){
        if(pinturas[j].getNombre()==elem){
            b=true;
            break;
        }
    }
    if(b){
        cout << "nombre " << esculturas[j].getNombre() << endl
         << "Material " << esculturas[j].getMaterial() << endl
         << "Volumen " << esculturas[j].getVolumen() <<endl
         << "Anio " << esculturas[j].getAnio() << endl;
    }

    if(!a && !b)
        cout << "No Encontrado" <<endl;

}


void Museo:: AgregarPintura(){
    PinturaS pinturaS;
    Pintura pintura1;

    if(numP > 30){
        cout << "Pintura Llenas" << endl;
        return;
    }
        cin.ignore();
        cout << "Ingrese el nombre" << endl;
        getline(cin, pinturaS.nombre);
        cout << "Ingrese el anio" << endl;
        cin >> pinturaS.anio;
        cin.ignore();
        cout << "Ingrese el ancho" << endl;
        cin >>  pinturaS.ancho;
        cin.ignore();
        cout << "Ingrese el alto" << endl;
        cin >> pinturaS.alto;
        cin.ignore();
        cout << "Ingrese la tecnica" << endl;
        getline(cin,pinturaS.tecnica);

        //pintura.push_back();


        pintura1.setNombre(pinturaS.nombre);
        pintura1.setAnio(pinturaS.anio);
        pintura1.setAncho(pinturaS.ancho);
        pintura1.setAlto(pinturaS.alto);
        pintura1.setTecnica(pinturaS.tecnica);


        pinturas.push_back(pintura1);

        guardar(pintura1);

    numP++;

}

void  Museo:: AgregarEscultura(){
    Escultura escultura1;
    EsculturaS esculturaS;

    cin.ignore();
    cout << "Ingrese la marca" << endl;
    getline(cin,esculturaS.nombre);
    cout << "Ingrese la Descipcion" << endl;
    getline(cin,esculturaS.material);
    cout << "Ingrese la anio" << endl;
    cin >> esculturaS.anio;
    cout << "Ingrese el volumen" << endl;
    cin >> esculturaS.volumen;

    escultura1.setNombre(esculturaS.nombre);
    escultura1.setMaterial(esculturaS.material);
    escultura1.setVolumen(esculturaS.volumen);
    escultura1.setAnio((esculturaS.anio));

    esculturas.push_back(escultura1);

    numE++;

    guardar(escultura1);
}

void Museo:: ConsultarPinturas(){
    if(!numP){
    cout <<"No hay pinturas" << endl;
    }
    for(int i=0; i<numP; i++){
        cout << "nombre " << pinturas[i].getNombre() << endl
         << "anio " << pinturas[i].getAnio() << endl
         << "alto " << pinturas[i].getAlto() <<endl
         << "ancho " << pinturas[i].getAncho() << endl
         << "Tecnica " << pinturas[i].getTecnica()  << endl;
    }
}

void Museo:: ConsultarEsculturas(){
    if(!numE){
        cout << "No hay esculturas" << endl;
    }
    for(int i=0; i<numE; i++){
        cout << "nombre " << esculturas[i].getNombre() << endl
         << "Material " << esculturas[i].getMaterial() << endl
         << "Volumen " << esculturas[i].getVolumen() <<endl
         << "Anio " << esculturas[i].getAnio() << endl;
    }
}
