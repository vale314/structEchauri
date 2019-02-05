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

    protected:

    private:
        string nombre;
        int anio;
};

#endif // OBRAARTE_H
