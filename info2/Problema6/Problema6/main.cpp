#include <iostream>
using namespace std;
int main()
{
    int num, fact=1;
    cout<<"Ingrese un numero: ";
    cin>>num;
    float div, e=0;
    for(int i=1;i<=num;i++)
    {
        div=1.0/fact;
        e=e+div;
        fact=fact*i;
    }
    cout<<e;
    return 0;
}
