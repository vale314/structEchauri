#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha
{
    public:
        Fecha();
        virtual ~Fecha();

        int getDay();
        void setDay(int value);

        int getMonth()const;
        void setMonth(int value);

        int getYear()const;
        void setYear(int value);

        // el operador que ses esta sobrecarcagado es el <<
        // a lo cual recibe el flujo donde esta el ostream& os
        //friend permite hacer uso de los atributos de oestram
        friend ostream& operator <<(ostream& os, const Fecha& obj);
    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // FECHA_H
