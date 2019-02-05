#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    Pila<int> pila;
    pila.push(3);
    pila.push(5);
    pila.push(7);

    cout<<"empty: "<<pila.empty()<<endl
       <<"size: "<<pila.size()<<endl
      <<"top: "<<pila.top()<<endl;


    while(!pila.empty()){
        cout << pila.top() <<endl;
        pila.pop();
    }

}
