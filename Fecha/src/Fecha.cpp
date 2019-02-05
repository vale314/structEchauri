#include "../include/Fecha.h"

Fecha::Fecha()
{
    //ctor
}

Fecha::~Fecha()
{
    //dtor
}

void Fecha::setDay(){
}

void Fecha::setMonth(){
}

void Fecha::setYear(){
}

int Fecha::getDay(){
}

int Fecha::getMonth(){
}

int Fecha::getYear(){

}

ostream& operator <<(ostream& os, const Fecha& obj){
        os << obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear();

        return os
