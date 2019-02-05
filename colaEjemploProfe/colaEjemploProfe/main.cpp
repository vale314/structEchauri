#include <iostream>
#include "cola.h"
using namespace std;

int main()
{
    Cola<int> cola;

    cola.push(7);
    cola.push(5);
    cola.push(3);

    cout << "empty: "<< cola.empty() <<endl
           <<"size: "<< cola.size() <<endl
          <<"front: "<< cola.front()<< endl
         <<"back: "<< cola.back() << endl;
    while(!cola.empty()){
        cout<<cola.front()<<endl;
        cola.pop();
    }
    return 0;
}
