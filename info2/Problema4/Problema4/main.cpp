#include <iostream>
using namespace std;
int main()
{
    int min, hor, tot, sum, mins, hors, mint, hort, D;
    cout<<"Ingrese un numero de 4 dijitos o menos: ";
    cin>>tot;
    min=tot%100;
    hor=tot/100;
    while(min>59 || hor>23)
    {
        cout<<tot<<" No es un tiempo valido, Ingrese otro valor: ";
        cin>>tot;
        min=tot%100;
        hor=tot/100;
    }
    cout<<"Ingrese otro valor de 4 dijitos o menos: ";
    cin>>sum;
    mins=sum%100;
    hors=sum/100;
    while(mins>59 || hors>23)
    {
        cout<<sum<<" No es un tiempo valido, Ingrese otro valor: ";
        cin>>sum;
        mins=sum%100;
        hors=sum/100;
    }
    hort=hor+hors;
    mint=min+mins;
    if(mint>59)
    {
        mint=mint-60;
        hort++;
        if(hort>24)
        {
            D=hort/24;
            hort=hort%24;
        }
    }
    cout<<D<<hort<<mint<<'\n';
}
