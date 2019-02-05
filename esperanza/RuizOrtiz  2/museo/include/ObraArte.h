#ifndef OBRAARTE_H
#define OBRAARTE_H
#include <string>

using namespace std;

class ObraArte
{
    public:
        ObraArte();
        virtual ~ObraArte();
        string getNombre();
        int getAnio();

        void setNombre(string);
        void setAnio(int);
        friend ostream& operator <<(ostream& os, const ObraArte& obj);
    protected:

    private:
        string nombre;
        int anio;
};

#endif // OBRAARTE_H
