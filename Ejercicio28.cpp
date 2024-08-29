//Recibe un numero y calcula pi

#include <iostream>
using namespace std;
int main()
{
    int x, n;
    float y, pi=0;
    cout<<"Ingrese un numero: ";
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        n=(i*2)-1;
        if(i%2!=0)
        {
            y = 1.0 / n;
            pi= pi + y;
        }
        if(i%2==0)
        {
            y = 1.0 / n;
            pi= pi - y;
        }
    }
    pi=pi*4;
    cout<<"Pi vale "<<pi;
    return 0;
}
