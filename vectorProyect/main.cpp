#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    vector<int> a;

    vector<int> c;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;

    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"PopBack"<<endl;
    a.pop_back();
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"Insert"<<endl;
    a.insert(2,21);
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"Erease"<<endl;
    a.erease(1);
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"Resize"<<endl;
    a.resize();
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"[]"<<endl;
    a[1]=33;
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;



    cout<<endl<<"="<<endl;
    c=a;
    cout<<endl<<"a"<<endl;
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"c"<<endl;
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"pushBack A"<<endl<<endl;
    a.push_back(40);
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;

    cout<<endl<<"pushBack C"<<endl;
    c.push_back(48);
    for(size_t i=0;i<c.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<c.at(i)<<endl;



    cout<<endl<<"Clear"<<endl;
    a.clear();
    cout<<"Size: "<<a.size()<<endl;
    cout<<"Capacidad: "<<a.capacity()<<endl;
    for(size_t i=0;i<a.size();i++)
        cout<<"Posicion: "<<i<<" Valor: "<<a.at(i)<<endl;


    return 0;
}
