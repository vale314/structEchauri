#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include "Persona.h"

class Empleado:public Persona
{
    public:
        Empleado();
        virtual ~Empleado();

        string getPuesto()const;
        void setPuesto(const string &value);

        float getSueldo()const;
        void setSueldo(float value);

    protected:

    private:
        string puesto;
        float sueldo;
};

#endif // EMPLEADO_H
