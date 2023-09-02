//Recibe un numero y dice si es o no un cuadrado perfecto/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, a, y;
    cout<<"Ingrese un numero: ";
    cin>>x;
    a=sqrt(x);
    y= a*a;
    if(y==x)
    {
        cout<<x<<" Es un cuadrado perfecto.";
    }
    else
    {
        cout<<x<<" No es un cuadrado perfecto.";
    }
    return 0;
}
