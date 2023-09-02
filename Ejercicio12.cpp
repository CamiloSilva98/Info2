//un numero elevado a cada numero del 1 al 5//

#include <iostream>
    using namespace std;
int main()
{
    int a, b, c=2;
    cout << "Ingrese un numero: ";
    cin >> a;
    b=a;
    for(int i=0;i<4;i++)
    {
        a = a*b;
        cout <<b<<"^"<<c<<"="<<a <<'\n';
        c++;
    }
    return 0;
}
