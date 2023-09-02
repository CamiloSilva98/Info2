/Escribe dos columnas una del 50 al 1 y la otra del 1 al 50/


#include <iostream>
using namespace std;

int main()
{
    int x=50;
    for (int i=1;i<=50;i++)
    {
        cout<<x<<"   "<<i<<'\n';
        x--;
    }
    return 0;
}
