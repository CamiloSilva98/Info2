#include <iostream>
using namespace std;
int main()
{
    int num;
    long long int fact=1;
    cout<<"Ingrese un numero entre 1 y 65: ";
    cin>>num;
    while(num>65 || num<=0)
        {
            cout<<"Ingrese un numero entre 1 y 65: ";
            cin>>num;
        }
    float div, e=1;
    for(int i=1;i<=num;i++)
    {
        fact=fact*i;
        div=1.0/fact;
        e=e+div;
    }
    cout<<"e es aproximadamente: "<<e;
    return 0;
}
