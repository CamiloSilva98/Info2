#include <iostream>

// Función para convertir una cadena a un entero
int cadenaAEntero(const char* cadena, int longitud) {
    int numero = 0;
    for (int i = 0; i < longitud; ++i) {
        numero = numero * 10 + (cadena[i] - '0'); // Convierte el carácter a entero
    }
    return numero;
}

// Función para calcular la longitud de la cadena
int calcularLongitud(const char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

// Función para sumar números de n cifras extraídos de una cadena de caracteres
int sumarSegmentos(const char* cadena, int n) {
    int longitud = calcularLongitud(cadena);
    int suma = 0;

    for (int i = 0; i < longitud; i += n) {
        int longitudSegmento = n;
        if (i + n > longitud) {
            longitudSegmento = longitud - i;
        }

        char segmento[20]; // Tamaño suficiente para el segmento
        int j = 0;

        // Rellenar con ceros a la izquierda si el segmento es más corto
        if (longitudSegmento < n) {
            for (int k = 0; k < n - longitudSegmento; ++k) {
                segmento[j++] = '0';
            }
        }

        // Copiar el segmento
        for (int k = 0; k < longitudSegmento; ++k) {
            segmento[j++] = cadena[i + k];
        }
        segmento[j] = '\0'; // Terminar la cadena

        // Convertir el segmento a entero y sumarlo
        suma += cadenaAEntero(segmento, n);
    }

    return suma;
}

int main() {
    int n;
    char cadena[100]; // Asume un tamaño máximo para la cadena

    // Leer el valor de n
    std::cout << "Ingrese el numero de cifras (n): ";
    std::cin >> n;
    std::cin.ignore(); // Limpiar el buffer del cin

    // Leer la cadena de caracteres numéricos
    std::cout << "Ingrese la cadena de caracteres numericos: ";
    std::cin.getline(cadena, 100);

    // Calcular la suma de los segmentos
    int suma = sumarSegmentos(cadena, n);

    // Imprimir los resultados
    std::cout << "Original: " << cadena << std::endl;
    std::cout << "Suma: " << suma << std::endl;

    return 0;
}
//revisar
