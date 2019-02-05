#include <iostream>

using namespace std;

int main()
{
    int *arreglo;

    arreglo = new int[20];

    for(int i=0; i<20;i++){
        *(arreglo + i)=i;

    }


    for(int i=0;i<20;i++){
        cout << *(arreglo + i) <<endl;
    }

    delete [] arreglo;

    return 0;
}
