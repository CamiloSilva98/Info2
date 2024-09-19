#include <iostream>
using namespace std;
// Función para eliminar caracteres repetidos de una cadena
void eliminarRepetidos(const char* original, char* sinRepetidos) {
    bool visto[256] = { false };
    int j = 0;
    for (int i = 0; original[i] != '\0'; ++i)
    {
        char c = original[i];
        if (!visto[(unsigned char)c])
        {
            visto[(unsigned char)c] = true;
            sinRepetidos[j++] = c;
        }
    }

    // Terminar la cadena sin repetidos con el carácter nulo
    sinRepetidos[j] = '\0';
}

int main()
{
    char cadenaOriginal[256];
    char cadenaSinRepetidos[256];
    cout <<"Ingrese una palabra: ";
    cin.getline(cadenaOriginal, sizeof(cadenaOriginal));
    eliminarRepetidos(cadenaOriginal, cadenaSinRepetidos);
    cout << "Original: " << cadenaOriginal <<'\n';
    cout << "Sin repetidos: " << cadenaSinRepetidos << '\n';

    return 0;
}
