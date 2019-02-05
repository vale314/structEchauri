#include <iostream>
#include "./include/Estudiante.h"
#include "./include/Empleado.h"
#include "./include/Persona.h"

using namespace std;

int main()
{
    /*
    Estudiante estu;

    estu.setNombre("Hello");
    estu.setNacionaliad("Vietnamita");
    estu.setCodigo("232443542");
    estu.setCreditos(129);

    cout << "Nombre" << estu.getNombre() << endl
        <<"Nacionalidad: " estu.getNacionalidad << endl
        <<"Codigo: "  estu.getCodigo <<endl
        <<"Creditos" estu.getCreditos <<endl;*/

   // Estudiante e;
    Persona empl;

    empl.setNombre("Delsfino Mesa");
    empl.setNacionalidad("Afgano");

    /*
    e.setNombre("Nombre");
    e.setNacionalidad("Mexico");
    e.setCodigo(123);*/

    cout << empl << endl;

    /*
        cout << "Nombre" << empl.getNombre() << endl
        <<"Nacionalidad: " << empl.getNacionalidad()<< endl
        <<"Codigo: "<<  empl.getPuesto() <<endl
        <<"Creditos"<< empl.getSueldo() <<endl;
    */

    return 0;
}
