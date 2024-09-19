#include <iostream>

// Función para contar el número de estrellas en la matriz
int contarEstrellas(int** matriz, int filas, int columnas)
{
    int contador = 0;

    // Iterar sobre cada elemento que no esté en el borde
    for (int i = 1; i < filas - 1; ++i)
    {
        for (int j = 1; j < columnas - 1; ++j)
        {
            int suma = matriz[i][j] +
                       matriz[i][j - 1] +
                       matriz[i][j + 1] +
                       matriz[i - 1][j] +
                       matriz[i + 1][j];
            suma=suma/5;
            if (suma > 6)
            {
                ++contador;
            }
        }
    }

    return contador;
}

int main()
{
    // Definir la matriz de ejemplo
    const int filas = 7;
    const int columnas = 8;
    int datos[filas][columnas] =
        {
        {0, 3, 4, 6, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 10, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 8, 7, 12, 6, 9, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    // Crear un puntero a la matriz
    int* matriz[filas];
    for (int i = 0; i < filas; ++i)
    {
        matriz[i] = datos[i];
    }

    // Contar y mostrar el número de estrellas
    int estrellas = contarEstrellas(matriz, filas, columnas);
    std::cout << "Numero de estrellas encontradas: " << estrellas << std::endl;

    return 0;
}
