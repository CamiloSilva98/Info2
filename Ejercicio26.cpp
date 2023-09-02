//Recibe tres numeros y dice si se puede hacer o no un triangulo con esas medidas y que tipo de triangulo es/

#include <iostream>
using namespace std;
int main()
{
    int a, b, c, g, m, p;
    cout<<"Ingrese el numero A: ";
    cin>>a;
    cout<<"Ingrese el numero B: ";
    cin>>b;
    cout<<"Ingrese el numero C: ";
    cin>>c;
    if(a==b && b==c)
    {
        cout<<"El triangulo es equilatero.";
    }
    else
    {
        g=max(max(a,b),c);
        p=min(min(a,b),c);
        m=a+b+c-g-p;
        if(g==m)
        {
            cout<<"El triangulo es isoseles.";
        }
        if(m==p)
        {
            if(m+p<=g)
            {
                cout<<"No se puede hacer un trianguolo con esas medidas.";
            }
            else
            {
                cout<<"El triangulo es isoseles.";
            }
        }
        else
        {
            if(p+m<=g)
            {
                cout<<"No se puede hacer un trianguolo con esas medidas.";
            }
            else
            {
                cout<<"El triangulo es escaleno";
            }
        }
    }
        
        
    return 0;
}
