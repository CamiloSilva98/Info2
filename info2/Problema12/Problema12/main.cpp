#include <iostream>
using namespace std;
int main()
{
    int n, mPrim, x=0;
    mPrim=1;
    cout<<"Ingrese un numero: ";
    cin>>n;
    int divisores[n/2];
    for(int i=1;i<n/2+1;i++)
    {
        if(n%i==0)
        {
            divisores[x]=i;
            x++;
        }
    }
    for(int j=0;j<x;j++)
    {
        bool pri_o=true;
        for(int i=2;i*i<=divisores[j];i++)
        {
            if(divisores[j]%i==0)
            {
                pri_o=false;
                break;
            }
        }
        if(pri_o)
        {
            mPrim=max(mPrim,divisores[j]);
        }
    }

    cout<<"El mayor factor primo de "<<n<<" es: "<<mPrim;
    return 0;
}

