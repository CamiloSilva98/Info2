/recibe un numero y dice a cuantos dias horas minutos y segundos equivale/
#include <iostream>
using namespace std;
int main()
{
    int t, s, m, h, d;
    cout <<"Ingrese el tiempo total en segundos: ";
    cin>> t;
    s=t%60;
    t=t/60;
    m=t%60;
    t=t/60;
    h=t%24;
    d=t/24;
    cout<<d<<" Dias con "<<h<<":"<<m<<":"<<s;
    return 0;
}
