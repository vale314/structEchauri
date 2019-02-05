#include <iostream>
#include <lsl.h>

using namespace std;

int main()
{
    LSL<int> lista;

    lista.push_front(5);
    lista.push_back(3);
    lista.push_back(7);
    lista.insert(2,4);
    lista.push_back(9);
    lista.push_back(9);
    lista.push_back(9);
    lista.remove(9);

//    cout << lista.empty() << endl
//         << lista.size() << endl
//         << lista.front() << endl
//         << lista.back() << endl;

    for(size_t i=0; i< lista.size(); i++)
        cout << lista[i]<<endl;

    LSL<int> lista2(lista);

    for(size_t i=0; i< lista2.size(); i++)
        cout << lista2[i]<<endl;

    return 0;
}
