/genera un numero aleatorio  y le pide al usuario advinarlo/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int x, y, a=1;
    x=rand()%100;
    cout<< "Advina el numero: ";
    cin>>y;
    while(x!=y)
    {
        if (x>y)
        {
            cout <<"El numero debe ser mayor, ingresa otro: ";
            cin >>y;
            a++;
        }
        if (x<y)
        {
            cout <<"El numero debe ser menor, ingresa otro: ";
            cin>>y;
            a++;
        }
    }
    cout<< "Adivinaste, el numero correcto era "<< x << " y tus intentos fueron: "<< a;
    return 0;
}
