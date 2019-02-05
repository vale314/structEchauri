#ifndef ESCULTURA_H
#define ESCULTURA_H
#include "ObraArte.h"

class Escultura: public ObraArte
{
    public:
        Escultura();
        virtual ~Escultura();

        void setVolumen(float volumen);
        void setMaterial(string material);

        float getVolumen();
        string getMaterial();
        friend bool operator< (Escultura& lhs, Escultura& rhs)
        {
           return lhs.getNombre() < rhs.getNombre();
        }

    protected:

    private:
        float volumen;
        string material;
};

#endif // ESCULTURA_H
