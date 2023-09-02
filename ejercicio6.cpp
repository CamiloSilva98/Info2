//Recibe un numero a y un b y devuelve el resultado de a eleado en b/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout<<"Ingrese el numero A: ";
    cin>>a;
    cout<<"Ingrese el numero B: ";
    cin>>b;
    c=a;
    for(int i=1;i<b;i++)
    {
        c=c*a;
    }
    cout<<c;
    return 0;
}
