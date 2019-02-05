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

    protected:

    private:
        float volumen;
        string material;
};

#endif // ESCULTURA_H
