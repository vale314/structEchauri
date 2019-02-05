#ifndef PINTURA_H
#define PINTURA_H
#include "ObraArte.h"


class Pintura: public ObraArte
{
    public:
        Pintura();
        virtual ~Pintura();
        void setAlto(int);
        void setAncho(int);
        void setTecnica(string);

        int getAlto();
        int getAncho();
        string getTecnica();
        friend ostream& operator << (ostream& os, const Pintura& obj);
    protected:

    private:
        int alto;
        int ancho;
        string tecnica;
};

#endif // PINTURA_H
