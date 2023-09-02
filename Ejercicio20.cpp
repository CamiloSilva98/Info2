//Recibe un numero y dice si es o no un palindromo/
#include <iostream>
using namespace std;
int main()
{
    int a, b, n, x=0;
    cout<<"Ingrese un numero: ";
    cin>>a;
    b=a;
    while(a!=0)
    {
        n=a%10;
        a=a/10;
        x=10*x+n;
    }
    if (x==b)
    {
        cout<<b<<" Es un numero palindromo.";
    }
    else
    {
        cout<<b<<" No es un numero palindromo.";
    }
    return 0;
}
