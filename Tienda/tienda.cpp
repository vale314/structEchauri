#include "tienda.h"
#include "tienda.h"
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
        cout<<"\t\t\t\tTienda"<<endl
           <<OPC_AGREGAR<< " Agregar producto"<<endl
           <<OPC_CONSULTAR<< " Consultar"<<endl
           <<OPC_BUSCAR<< " Buscar" << endl
           <<OPC_VENDER<< " Vender"<< endl
           <<OPC_ELIMINAR<< " Eliminar"<< endl
          <<OPC_SALIR << " Salir"
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
        case OPC_BUSCAR:
            buscar();
            break;
        case OPC_VENDER:
            vender();
            break;
        case OPC_ELIMINAR:
            drop();
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

void Tienda::buscar(){
    string nombre;
    bool t;
    size_t i;

    cout << "Nombre";
    getline(cin,nombre);

    t=false;
    for(i=0;i<productos._size();i++){
        if(!nombre.compare(productos[i].getNombre())){
            t=true;
            break;
        }

    }

    if(t)
        cout<<productos[i];
    else
        cout << "Producto No Encontrado"<< endl;
}

void Tienda::borrarDocumento(){
    const int result = remove( "tienda.txt" );
    if( result == 0 )
        printf( "success\n" );
     else
        printf( "%s\n", strerror( errno ) );
}

void Tienda::cargarADocumento(){
   for(size_t i=0;i<productos._size();i++)
        guardar(productos[i]);
}

int Tienda::buscar(string nombre){
    bool t;
    size_t i;

    t=false;
    for(i=0;i<productos._size();i++){
        if(!nombre.compare(productos[i].getNombre())){
            t=true;
            break;
        }

    }

    if(t)
        return (static_cast<int>(i));
    else
        return(-1);
}

void Tienda::vender(){
    string nombre;
    cout << "Nombre" <<endl;
    getline(cin,nombre);
    int pos=-1;
    pos=buscar(nombre);

    if(pos<0)
        cout<< "El Producto No Se Encuentra"<< endl;
    else{

        int cantidad;
        float precio;

        cout << "Nuevo Nombre";
        getline(cin,nombre);
        cout << "Nueva Cantidad";
        cin>>cantidad;
        cout << "Nuevo Precio";
        cin>>precio;

        productos[static_cast<size_t>(pos)].setNombre(nombre);
        productos[static_cast<size_t>(pos)].setPrecio(precio);
        productos[static_cast<size_t>(pos)].setCantidad(cantidad);

        borrarDocumento();
        cargarADocumento();
    }
}

void Tienda::drop(){
    string nombre;
    cout << "Nombre" <<endl;
    getline(cin,nombre);
    int pos=-1;
    pos=buscar(nombre);

    if(pos<0)
        cout<< "El Producto No Se Encuentra"<< endl;
    else{
        productos._remove(static_cast<size_t>(pos));

        borrarDocumento();
        cargarADocumento();
    }
}
