#include <iostream>
using namespace std;
int main()
{
    int bil, con;
    cout<<"Ingrese el valor: ";
    cin>>bil;
    if(bil/50000!=0)
    {
        con=bil/50000;
        bil=bil%50000;
        cout<<con<<" Billetes de 50.000"<<'\n';

    }
    if(bil/20000!=0)
    {
        con=bil/20000;
        bil=bil%20000;
        cout<<con<<" Billetes de 20.000"<<'\n';
    }
    if(bil/10000!=0)
    {
        con=bil/10000;
        bil=bil%10000;
        cout<<con<<" Billete de 10.000"<<'\n';
    }
    if(bil/5000!=0)
    {
        con=bil/5000;
        bil=bil%5000;
        cout<<con<<" Billetes de 5.000"<<'\n';
    }
    if(bil/2000!=0)
    {
        con=bil/2000;
        bil=bil%2000;
        cout<<con<<" Billetes de 2.000"<<'\n';
    }
    if(bil/1000!=0)
    {
        con=bil/1000;
        bil=bil%1000;
        cout<<con<<" Moneda de 1.000"<<'\n';
    }
    if(bil/500!=0)
    {
        con=bil/500;
        bil=bil%500;
        cout<<con<<" Moneda de 500"<<'\n';
    }
    if(bil/200!=0)
    {
        con=bil/200;
        bil=bil%200;
        cout<<con<<" Monedas de 200"<<'\n';
    }
    if(bil/100!=0)
    {
        con=bil/100;
        bil=bil%100;
        cout<<con<<" Moneda de 100"<<'\n';
    }
    if(bil/50!=0)
    {
    con=bil/50;
    bil=bil%50;
    cout<<con<<" Moneda de 50"<<'\n';
    }
    cout<<"Faltante: "<<bil;
}
