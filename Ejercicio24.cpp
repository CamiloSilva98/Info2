//Dibuja un cuadrado con cruces dado un numero/
#include <iostream>
using namespace std;
int main()
{
    int x;
    cout <<"Ingrese un numero: ";
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cout<<"+";
    }
    cout<<'\n';
    for (int i=0;i<x-2;i++)
    {
        cout<<"+";
        for (int i=0;i<x-2;i++)
        {
            cout<<" ";
        }
        cout<<"+"<<'\n';
    }
    for(int i=0;i<x;i++)
    {
        cout<<"+";
    }
    cout<<'\n';
    return 0;
}
