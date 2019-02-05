#include <iostream>
#include "./include/Fecha.h"

using namespace std;

int main()
{
    Fecha f;
    f.setDay(12);
    f.setMonth(8);

    f.setYear(1998);

    cout << f;
    cout << "Hello world!" << endl;
    return 0;
}
