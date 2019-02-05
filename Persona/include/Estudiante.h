#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include "./Persona.h"

using namespace std;

class Estudiante : public Persona
{
    public:
        Estudiante();
        virtual ~Estudiante();
        void setNombre(const string nombre);
        int getCodigo()const;

        void setCodigo(int value);

        friend ostream& operator << (ostream& os, const Estudiante& obj);
    protected:

    private:
        int codigo;
};

#endif // ESTUDIANTE_H
