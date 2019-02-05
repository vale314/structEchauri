#include "tienda.h"

Tienda::Tienda()
{
    cargar();
}

void Tienda::menu()
{
    int opc;
    do
    {
        cout<<"\t\t\t\tTienda"
           <<OPC_AGREGAR<< " Agregar producto"<<endl
           <<OPC_CONSULTAR<< " Consultar"<<endl
          <<OPC_SALIR << "Salir"
           <<endl;
        cin >> opc;
        cin.ignore();
        switch (opc) {
            case OPC_AGREGAR:
                agregar();
            break;

        case OPC_CONSULTAR:
            consultar();
            break;
        case OPC_SALIR:
            break;
        default:
            cout << "Opcion No Valida"<< endl;
        }
    }while(opc != OPC_SALIR);
}

void Tienda::cargar()
{
    string linea;
    ifstream archivo("tienda.txt");
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    while(getline(archivo,linea)){
        Producto p(linea);
        productos._insert(p);
    }
    archivo.close();
}

void Tienda::guardar(const Producto &prod)
{
    ofstream archivo("tienda.txt", ios::app); //remplazar quitar el ios::app

    if(!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
     }

    archivo << prod;
    archivo.close();
}

void Tienda::agregar()
{
    Producto p;
    string nombre;
    int cantidad;
    float precio;

    cout << "Nombre";
    getline(cin,nombre);
    cout << "Cantidad";
    cin>>cantidad;
    cout << "Precio";
    cin>>precio;

    p.setNombre(nombre);
    p.setCantidad(cantidad);
    p.setPrecio(precio);

    productos._insert(p);
    guardar(p);
}

void Tienda::consultar()
{
    for(size_t i=0;i <productos._size(); i++){
        cout << productos[i];
    }
}
