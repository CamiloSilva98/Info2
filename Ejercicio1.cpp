//Recibe dos numeros y dice cual es el menor/

#include <iostream>
using namespace std;

int ejercicio1()
{
    int a, b;
    cout<<"Ingrese el numero A:";
    cin>>a;
    cout<<"Ingrese el numero B:";
    cin>>b;
    if(a>b)
    {
        cout<<"El numero menor es: "<<b;
    }
    if(a<b)
    {
        cout<<"El numero menor es: "<<a;
    }
    else
    {
        cout<<"Son iguales";
    }
    return 0;
}
