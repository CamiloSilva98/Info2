#include <iostream>
using namespace std;
void enteroACadena(int numero, char* cadena)
{
    int i = 0;
    bool esNegativo = false;

    if (numero < 0)
    {
        esNegativo = true;
        numero = -numero;
    }

    do
    {
        cadena[i++] = (numero % 10) + '0';
        numero /= 10;
    }
    while (numero > 0);

    if (esNegativo)
    {
        cadena[i++] = '-';
    }

    cadena[i] = '\0';  // Agregar carácter nulo

    int inicio = 0;
    int fin = i - 1;
    while (inicio < fin)
    {
        char temp = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = temp;
        inicio++;
        fin--;
    }
}

int main()
{
    int numero = 0;
    char cadena[12];
    cout << "Ingrese un numero: ";
    cin >> numero;

    enteroACadena(numero, cadena);
    cout << "El numero " << numero << " como cadena es: " << cadena << '\n';
    return 0;
}

