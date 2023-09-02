//recibe numeros y se detiene cuando recibe un cero y da el promedio de los numeros dados antes excluyendo el 0/
#include <iostream>
using namespace std;
int main()
{
    int x, c, a=0;
    cout <<"Ingrese un numero: ";
    cin >> x;
    while(x!=0)
    {
        a=a+x;
        c++;
        cout << "Ingrese otro numero: ";
        cin >> x;
    }
    cout <<"El promedio es: "<<a/c;
    return 0;
}
