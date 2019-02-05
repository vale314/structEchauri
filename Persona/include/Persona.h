#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>

using namespace std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();

        string getNombre();
        string getNacionalidad();

        void setNombre(string);
        void setNacionalidad(string);

        friend ostream& operator <<(ostream& os, const Persona& obj);

    protected:

    private:
        string nombre;
        string nacionalidad;
};

#endif // PERSONA_H
