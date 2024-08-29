//Dice cuales son los multimplos de un numero menores de 100

#include <iostream>
using namespace std;
int main()
{
    int x, n;
    cout<<"Ingrese un numero: ";
    cin>>x;
    if(x==1)
    {
        cout<<"Los multiplos de 1 menores que 100 son todos los numeros del 1 al 100";
    }
    if(x>50)
    {
        cout<<"Los multiplos de "<<x<<" menores de 100 son: "<<x;
    }
    else
    {
        cout<<"Los multiplos de "<<x<<" menores de 100 son: ";
        while(n<100)
        {
            for(int i=1;i<51;i++)
            {
                n=x*i;
                if(n<=100)
                {
                cout <<n<<'\n';
                }
            }
        }
    }
    return 0;
}
