#include <iostream>
using namespace std;
// Función para comparar dos cadenas de caracteres
bool compararCadenas(const char* cadena1, const char* cadena2)
{
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0')
    {
        if (cadena1[i] != cadena2[i])
        {
            return false;
        }
        i++;
    }
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

int main()
{
    const char* c1 = "Hola Mundo";
    const char* c2 = "Hola Mundo";
    const char* c3 = "Hola Mundo!";
    const char* c4 = "Hola MUNDO";

    cout << "Comparando \"" << c1 << "\" con \"" << c2 << "\": "
              << (compararCadenas(c1, c2) ? "Iguales" : "Diferentes") << std::endl;

    cout << "Comparando \"" << c1 << "\" con \"" << c3 << "\": "
              << (compararCadenas(c1, c3) ? "Iguales" : "Diferentes") << std::endl;

    cout << "Comparando \"" << c1 << "\" con \"" << c4 << "\": "
              << (compararCadenas(c1, c4) ? "Iguales" : "Diferentes") << std::endl;

    return 0;
}
