#include <iostream>
#include "ldl.h"

using namespace std;

int main()
{

    LDL<int> lista;

    lista.push_front(5);
    lista.push_front(7);
    lista.push_back(3);
    lista.push_back(10);
    //lista.push_back(7);
    //lista.pop_back();
    // lista.pop_back();
    lista.insert(1,10);

//    LDL<int> lista1;


    cout << "empty: "<< lista.empty() <<endl
         <<"size: "<< lista.size() << endl
        <<"front: "<< lista.front()<<endl
       <<"back: "<< lista.back()<<endl;

    for(size_t i = 0; i< lista.size(); i++)
        cout<< lista[i]<<endl;

//    for(size_t i = 0; i< lista.size(); i++)
//        cout<< lista1[i]<<endl;
}
