#include <iostream>

using namespace std;

// Definir el tamaño de la sala
const int FILAS = 15;
const int ASIENTOS_POR_FILA = 20;

// Función para inicializar la sala
void inicializarSala(char sala[FILAS][ASIENTOS_POR_FILA])
{
    for (int i = 0; i < FILAS; ++i)
    {
        for (int j = 0; j < ASIENTOS_POR_FILA; ++j)
        {
            sala[i][j] = '-';
        }
    }
}

// Función para mostrar la sala
void mostrarSala(const char sala[FILAS][ASIENTOS_POR_FILA])
{
    cout << "   ";
    for (int j = 1; j <= ASIENTOS_POR_FILA; ++j)
    {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < FILAS; ++i)
    {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < ASIENTOS_POR_FILA; ++j)
        {
            cout << sala[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para reservar un asiento
void reservarAsiento(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int numero)
{
    int indiceFila = fila - 'A';
    int indiceAsiento = numero - 1;

    if (indiceFila >= 0 && indiceFila < FILAS && indiceAsiento >= 0 && indiceAsiento < ASIENTOS_POR_FILA)
    {
        if (sala[indiceFila][indiceAsiento] == '-')
        {
            sala[indiceFila][indiceAsiento] = '+';
            cout << "Asiento reservado con exito.\n";
        }
        else
        {
            cout << "El asiento ya esta reservado\n.";
        }
    }
    else
    {
        cout << "Numero de asiento o fila invalido.\n";
    }
}

// Función para cancelar una reserva
void cancelarReserva(char sala[FILAS][ASIENTOS_POR_FILA], char fila, int numero)
{
    int indiceFila = fila - 'A';
    int indiceAsiento = numero - 1;

    if (indiceFila >= 0 && indiceFila < FILAS && indiceAsiento >= 0 && indiceAsiento < ASIENTOS_POR_FILA)
    {
        if (sala[indiceFila][indiceAsiento] == '+')
        {
            sala[indiceFila][indiceAsiento] = '-'; // '-' indica que el asiento está disponible
            cout << "Reserva cancelada con éxito.\n";
        }
        else
        {
            cout << "El asiento no esta reservado.\n";
        }
    }
    else
    {
        cout << "Numero de asiento o fila invalido.\n";
    }
}

int main()
{
    char sala[FILAS][ASIENTOS_POR_FILA];
    inicializarSala(sala);

    int opcion;
    do
    {
        cout << "1. Mostrar sala\n";
        cout << "2. Reservar asiento\n";
        cout << "3. Cancelar reserva\n";
        cout << "4. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            mostrarSala(sala);
        }
        else if (opcion == 2)
        {
            char fila;
            int numero;
            cout << "Ingrese fila (A-O): ";
            cin >> fila;
            if (fila>=97)
            {
                fila= fila-32;
            }
            cout << "Ingrese numero de asiento (1-20): ";
            cin >> numero;
            reservarAsiento(sala, fila, numero);
        }
        else if (opcion == 3)
        {
            char fila;
            int numero;
            cout << "Ingrese fila (A-O): ";
            cin >> fila;
            if (fila>=97)
            {
                fila= fila-32;
            }
            cout << "Ingrese numero de asiento (1-20): ";
            cin >> numero;
            cancelarReserva(sala, fila, numero);
        }
        else if (opcion != 4)
        {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }

    }
    while (opcion != 4);

    return 0;
}

