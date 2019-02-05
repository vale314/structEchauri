#include <iostream>
#include <stdlib.h>

#define MAX 30

using namespace std;

int index=0;
int i;
string z[MAX];

class ObraArte{
public:
    void obtener_datos();
    void mostrar_obras();
    void secuencial();
    void binaria();
private:
    string NombreObra, Material, NombreAutor,Obra;
    int Anio;
};

void ObraArte::obtener_datos(){
    if(index==MAX){
        cout<<"El arreglo esta lleno, no se pueden añadir mas obras de arte."<<endl;
    }else{
    cout<<"Nombre de la obra:"<<endl;
    cin>>NombreObra;

    cout<<"En que año se hizo:"<<endl;
    cin >> Anio;

    cout<<"Material del que esta hecho:"<<endl;
    cin >> Material;

    cout<<"Nombre del autor:"<<endl;
    cin >> NombreAutor;

    z[i]=NombreObra;
    index++;
    }
}

void ObraArte::mostrar_obras(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Nombre de la obra: "<<NombreObra<<endl;
    cout<<"Material: "<<Material<<endl;
    cout<<"Nombre del autor: "<<NombreAutor<<endl;
    cout<<"Año de creacion: "<<Anio<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

}

void ObraArte::secuencial(){
    int x=0;
    cout<<"Nombre de la obra que desea buscar"<<endl;
    cin>>Obra;
            for(i = 0; i < index; i++)
            {
                if (z[i] == Obra){
                cout<<"La obra se encuentra en la posicion "<<i+1<<endl;
                x++;
                }
            }
            if(x==0){
                cout<<"La obra que usted busca no se encuentra en la lista"<<endl;
                     }
}

void ObraArte::binaria(){
    int izquierdo, derecho, puntomedio,x=0;
    izquierdo = 0;
    derecho = index -1;
    cout<<"Nombre de la obra que desea buscar"<<endl;
    cin>>Obra;
    while (izquierdo <= derecho)
    {
    puntomedio = (int) ((izquierdo + derecho) / 2);
    if (Obra == z[puntomedio])
    {
    cout<<"La obra se encuentra en la posicion "<<puntomedio+1<<endl;
    x++;
    izquierdo=derecho+1;
    }
    else if (Obra > z[puntomedio])
    izquierdo = puntomedio + 1;
    else
    derecho = puntomedio -1;
    }
    if(x==0){
    cout<<"La obra que usted busca no se encuentra en la lista"<<endl;
    }

}

int main()
{
    ObraArte arreglo[MAX];
int opc,opc2;
do{
    cout << "\tMenu:" << endl<<"1)Agregar Obra de arte."<<endl<<"2)Mostrar las obras de arte"<<endl<<"3)Buscar una obra de arte"<<endl<<"4)Salir"<<endl;
    cin >> opc;
    switch (opc) {
    case 1:
        arreglo[index].obtener_datos();
        system("pause");
        system("cls");
        break;
    case 2:
        for(i=0;i<index;i++){
            arreglo[i].mostrar_obras();
        }
        system("Pause");
        system("cls");
        break;
    case 3:
    cout<<"Que metodo de busqueda desea usar:"<<endl<<"1)Secuencial"<<endl<<"2)Binaria"<<endl;
    cin>>opc2;
            switch (opc2) {
    case 1:
           arreglo[i].secuencial();
           system("pause");
           system("cls");
            break;
        case 2:
            arreglo[i].binaria();
            system("pause");
            system("cls");
            break;
        default:
            cout<<"La opcion que usted escribio no existe"<<endl;
            system("pause");
            system("cls");
            break;
    }
        break;
    default:
        cout<<"La opcion que usted escribio no existe"<<endl;
        system("pause");
        system("cls");
        break;
    }
}while(opc!=4);
    return 0;
}
