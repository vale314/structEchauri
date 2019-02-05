#include <iostream>
#include "PILA_ESTATICA.h"

using namespace std;

int main()
{
    Pila_Estatica<int> pila;

    pila.push(8);
    pila.push(1);
    pila.push(3);

    cout << "Vacia: " << pila._empty()
         << "LlENA: " << pila.full()
         << "Taman: " << pila._size()
         << "Cima: " << pila.top() << endl;

    pila.pop();

        cout << "cima: " << pila.top() << endl;

        while(!pila._empty()){

            cout << pila.top() << " ";
            pila.pop();
        }

    return 0;
}
