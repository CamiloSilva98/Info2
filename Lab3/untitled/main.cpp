#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
bool actualizarSaldo(string& archivoDesencriptado, unsigned int montoRetirar)
{
    montoRetirar = montoRetirar + 1000;
    size_t pos = archivoDesencriptado.find("Saldo: ");

    if (pos != string::npos)
    {
        pos += 7;
        unsigned int saldoActual = stoi(archivoDesencriptado.substr(pos));

        if (saldoActual >= montoRetirar)
        {
            unsigned int nuevoSaldo = saldoActual - montoRetirar;
            archivoDesencriptado.replace(pos, string::npos, to_string(nuevoSaldo));
            return true;
        }
        else
        {
            cerr << "Saldo insuficiente." << endl;
            return false;
        }
    } else {
        cerr << "No se encontró la línea de saldo." << endl;
        return false;
    }
}
bool archivoExiste(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    bool existe = archivo.is_open();

    if (existe)
    {
        archivo.close();
    }

    return existe;
}
void agregarArchivo(const string& nombreArchivo, const string& datos)
{
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open())
    {
        archivo << datos << endl;
        archivo.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}
// Función para escribir datos en un archivo
void escribirArchivo(const string& nombreArchivo, const string& datos)
{
    ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        archivo << datos;
        archivo.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

// Función para leer datos de un archivo
string leerArchivo(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    string datos, linea;
    if (archivo.is_open())
    {
        while (getline(archivo, linea))
        {
            datos += linea;
        }
        archivo.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo." << endl;
    }
    return datos;
}

// Convierte un carácter a su representación binaria de 8 bits en forma de string
string convertirCharABinario(char c)
{
    string binario;
    for (int i = 7; i >= 0; --i)
    {
        binario += ((c >> i) & 1) ? '1' : '0';
    }
    return binario;
}

// Convierte un texto completo a su representación binaria
string convertirABinario(const string& texto)
{
    string binario;
    for (char c : texto)
    {
        binario += convertirCharABinario(c);
    }
    return binario;
}

// Convierte una cadena de binario de 8 bits a un carácter
char convertirBinarioAChar(const string& binario)
{
    char c = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (binario[i] == '1')
        {
            c |= (1 << (7 - i));
        }
    }
    return c;
}

// Convierte una cadena binaria completa a texto
string convertirBinarioATexto(const string& binario)
{
    string texto;
    for (size_t i = 0; i < binario.size(); i += 8)
    {
        string bloque = binario.substr(i, 8);
        texto += convertirBinarioAChar(bloque);
    }
    return texto;
}

// Encriptación mediante desplazamiento de bits dentro de bloques de tamaño n
string encriptar(const string& texto, int n)
{
    string binario = convertirABinario(texto);
    string resultado;

    // Recorremos los bloques de n bits
    for (size_t i = 0; i < binario.size(); i += n)
    {
        string bloque = binario.substr(i, n);
        string bloqueEncriptado = bloque;
        // Desplazamos los bits una posición dentro del bloque (hacia la derecha)
        for (int j = 0; j < n; ++j)
        {
            bloqueEncriptado[(j + 1) % n] = bloque[j];  // Desplazamos los bits
        }

        resultado += bloqueEncriptado;
    }

    return resultado;
}

// Desencriptación mediante desplazamiento de bits inverso dentro de bloques de tamaño n
string desencriptar(const string& binario, int n)
{
    string resultado;

    // Recorremos los bloques de n bits
    for (size_t i = 0; i < binario.size(); i += n)
    {
        string bloque = binario.substr(i, n);  // Obtenemos un bloque de tamaño n
        string bloqueDesencriptado = bloque;   // Hacemos una copia del bloque

        // Desplazamos los bits una posición hacia la izquierda
        for (int j = 0; j < n; ++j)
        {
            bloqueDesencriptado[j] = bloque[(j + 1) % n];  // Desplazamos los bits a la izquierda
        }

        resultado += bloqueDesencriptado;
    }

    return convertirBinarioATexto(resultado);  // Convertimos el binario desencriptado a texto
}
void borrar(const string& nombreArchivo, const string& fraseInicial, int claveEncriptacion) {
    ifstream archivoEntrada(nombreArchivo);  // Abrir archivo para lectura
    ofstream archivoTemporal("temp.txt");    // Crear archivo temporal para escribir los datos modificados

    string linea;
    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        while (getline(archivoEntrada, linea)) {
            // Desencriptamos la línea para compararla
            string lineaDesencriptada = desencriptar(linea, claveEncriptacion);

            // Buscar la frase inicial en la línea desencriptada
            size_t pos = lineaDesencriptada.find(fraseInicial);

            // Si la frase inicial se encuentra al comienzo de la línea desencriptada
            if (pos == 0) {
                // No agregar la línea al archivo temporal (es decir, eliminarla)
                continue;
            }

            // Encriptamos nuevamente la línea antes de escribirla en el archivo temporal
            archivoTemporal << linea << endl;  // Escribir las líneas que no coinciden
        }

        archivoEntrada.close();
        archivoTemporal.close();

        // Reemplazar el archivo original por el archivo temporal
        remove(nombreArchivo.c_str());            // Eliminar el archivo original
        rename("temp.txt", nombreArchivo.c_str());  // Renombrar el archivo temporal con el nombre original

        cout << "El usuario ha sido eliminado correctamente." << endl;

    } else {
        cerr << "Error al abrir los archivos." << endl;
    }
}
int main()
{
    int rSaldo, num = 0;
    string usuario, cedula, clave, saldo, nDatos, datos;
    bool admin = false;
    cout << "Ingrese su usuario: ";
    getline(cin, usuario);
    cout<<"Ingrese su clave: ";
    getline(cin, clave);
    nDatos = desencriptar(leerArchivo("sudo.txt") ,4);
    if (nDatos.find(usuario) != string::npos && nDatos.find(clave) != string::npos)
    {
        admin = true;
        cout << "BIENVENIDO ADMINISTRADOR\n";
    }
    else
    {
        nDatos = desencriptar(leerArchivo("usuarios.txt") ,4);
        if (nDatos.find(usuario) != string::npos && nDatos.find(clave) != string::npos)
        {

            cout<<"Bienvenido, dijite:\n";
            cout<<"1. Retirar dinero.\n";
            cout<<"2. Consultar saldo.\n";
            cout<<"3. Salir.\n";
            cin>>num;
            while(num != 3)
            {
                nDatos = desencriptar(leerArchivo(usuario+".txt"), 4);
                if(num == 1)
                {
                    cout<<"Ingrese el valor que desea retirar: ";
                    cin>>rSaldo;
                    if (actualizarSaldo(nDatos, rSaldo))
                    {
                        escribirArchivo(usuario + ".txt", encriptar(nDatos, 4));
                        cout << "Su dinero fue retirado.\n";
                    }
                }
                else if(num == 2)
                {

                    if (nDatos.find("Saldo: ") != string::npos)
                    {
                        size_t pos = nDatos.find("Saldo: ");
                        actualizarSaldo(nDatos,0);
                        escribirArchivo(usuario+ ".txt",encriptar(nDatos, 4));
                        cout << nDatos.substr(pos) << endl;
                    }

                }
                cout<<"1. Retirar dinero.\n";
                cout<<"2. Consultar saldo.\n";
                cout<<"3. Salir.\n";
                cin>>num;
            }
        }
        else
        {
            cout<<"Usuario o clave incorrectas.";
        }

    }
    while(admin)
    {
        cout << "1. Agregar usuario nuevo.\n";
        cout << "2. Eliminar usuario.\n";
        cout << "3. Salir.\n";
        cin>> num;
        cin.ignore();
        if(num==1)
        {
            cout << "Ingrese nombre de usuario: ";
            getline(cin, usuario);
            if(archivoExiste(usuario))
            {
                cout<<"el usuario ya existe";
            }
            else
            {
                cout<<"Ingrese la clave: ";
                getline(cin, clave);
                cout << "Ingrese la cedula: ";
                getline(cin, cedula);
                cout << "Ingrese el saldo: ";
                getline(cin, saldo);
                datos = "Usuario: " + usuario + " clave: " + clave + '\n';
                agregarArchivo("usuarios.txt", encriptar(datos, 4));
                datos = "Cedula: " + cedula + "\nSaldo: " + saldo;
                escribirArchivo(usuario+ ".txt",encriptar(datos, 4));
            }
        }
        if(num==2)
        {
            cout << "Ingrese nombre de usuario: ";
            getline(cin, usuario);
            string usuario1 =usuario + ".txt";
            if (remove(usuario1.c_str()) == 0)
            {
                borrar("usuarios.txt","Usuario: "+ usuario, 4);
                cout << "El usuario ha sido eliminado exitosamente." << endl;
            } else {
                perror("Error al intentar eliminar");
            }
        }
        if(num==3)
        {
            admin = false;
        }
    }
    return 0;
}
