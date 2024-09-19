#include <iostream>
using namespace std;

void formarRectangulo(const int rectangulo1[4], const int rectangulo2[4], int (&rectangulo3)[4])
{
    if(rectangulo1[0] >= rectangulo2[0])
    {
        if(rectangulo2[0]+rectangulo2[2]>=rectangulo1[0])
        {
            rectangulo3[0]=rectangulo1[0];
        }
        else
        {
            cout<<"No se forma un rectangulo.";
           // break;
        }
    }
    else
    {
        if(rectangulo1[0]+rectangulo1[2]>=rectangulo2[0])
        {
            rectangulo3[0]=rectangulo2[0];
        }
        else
        {
            cout<<"No se forma un rectangulo.";
            // break;
        }
    }
    if(rectangulo1[1] >= rectangulo2[1])
    {
        if(rectangulo2[1]+rectangulo2[3]>=rectangulo1[1])
        {
            rectangulo3[1]=rectangulo1[1];
        }
        else
        {
            cout<<"No se forma un rectangulo.";
            // break;
        }
    }
    else
    {
        if(rectangulo2[1]+rectangulo2[3]>=rectangulo1[1])
        {
            rectangulo3[1]=rectangulo2[1];
        }
        else
        {
            cout<<"No se forma un rectangulo.";
            // break;
        }
    }
    if(rectangulo1[0]+rectangulo1[2]<rectangulo2[0]+rectangulo2[2])
    {
        rectangulo3[2] = (rectangulo1[0]+rectangulo1[2]) - rectangulo3[0];
    }
    else
    {
        rectangulo3[2] = (rectangulo2[0]+rectangulo2[2]) - rectangulo3[0];
    }
    if(rectangulo1[1]+rectangulo1[3]<rectangulo2[1]+rectangulo2[3])
    {
        rectangulo3[3] = (rectangulo1[1]+rectangulo1[3]) - rectangulo3[1];
    }
    else
    {
        rectangulo3[3] = (rectangulo2[1]+rectangulo2[3]) - rectangulo3[1];
    }
}
int main()
{
    int arreglo1[4];
    int arreglo2[4];
    int resultado[4];

    cout << "Ingrese los elementos del primer arreglo (4 numeros enteros): " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo1[i];
    }

    cout << "Ingrese los elementos del segundo arreglo (4 numeros enteros): " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo2[i];
    }

    formarRectangulo(arreglo1, arreglo2, resultado);

    cout << "Resultado: ";
    for (int i = 0; i < 4; ++i) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
}
