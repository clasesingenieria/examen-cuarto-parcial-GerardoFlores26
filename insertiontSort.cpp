#include <iostream>
#include <vector>
using namespace std;

// Función de ordenamiento por inserción (insertion sort)
void insertionSort(vector<int>& v) {
    // Recorremos el vector desde el segundo elemento hasta el final
    for (size_t i = 1; i < v.size(); ++i) {
        int key = v[i];  // Tomamos el valor actual que vamos a insertar
        int j = i - 1;

        // Comparamos el valor actual con los elementos anteriores
        // Si el valor actual es menor que el anterior, lo movemos hacia la derecha
        // Esto crea espacio para insertar el valor actual en su posición correcta
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];  // Mover el elemento a la derecha
            --j;  // Desplazar el índice para seguir comparando hacia la izquierda
        }
        // Finalmente, insertamos el valor actual (key) en la posición correcta
        v[j + 1] = key;
    }
}

int main() {
    const size_t TAMAÑO{20}; // Número máximo de vectores (limitado a 20 números)
    vector<int> v;  // Creamos un vector para almacenar los números
    size_t subindice{0};  // Variable para llevar cuenta de cuántos números hemos ingresado
    bool duplicado{false};  // Variable para verificar si el número ingresado es duplicado

    cout << "Ingrese 20 numeros enteros entre 10 y 100\n";

    // Recolectar 20 números sin duplicados entre 10 y 100
    unsigned int i{0};  // Contador para controlar cuántos números hemos ingresado

    // Bucle para ingresar hasta 20 números
    while (i < TAMAÑO) {
        duplicado = false;  // Resetear la variable de duplicado
        int valor{0};  // Número ingresado por el usuario

        // Leer el valor desde la entrada estándar (teclado)
        cin >> valor;

        // Validamos que el número esté dentro del rango 10-100
        if (valor >= 10 && valor <= 100) {
            // Verificamos si el número ya existe en el vector (para evitar duplicados)
            for (unsigned int j{0}; j < v.size(); ++j) {
                if (valor == v[j]) {
                    duplicado = true;  // Si el número ya existe, marcamos como duplicado
                    break;  // Salimos del bucle si encontramos el duplicado
                }
            }
            // Si el número no es duplicado, lo agregamos al vector
            if (!duplicado) {
                v.push_back(valor);  // Agregar el número al vector
                ++subindice;  // Incrementar el contador de números ingresados
            }
            else {
                cout << "Numero duplicado.\n";  // Informar que el número es duplicado
            }
            ++i;  // Incrementar el contador de intentos para ingresar números
        }
        else {
            cout << "Numero invalido.\n";  // Si el número no está en el rango, informamos el error
        }
    }

    // Imprimir los números ingresados, sin ordenar
    cout << "\nLos valores no duplicados (sin ordenar) son:\n";
    for (size_t indice{0}; indice < subindice; ++indice) {
        cout << v[indice] << ' ';  // Mostrar cada número en el vector
    }
    cout << endl;

    // Ordenar los números usando el algoritmo de ordenamiento por inserción
    insertionSort(v);

    // Imprimir los números ya ordenados
    cout << "\nLos valores no duplicados ordenados son:\n";
    for (size_t indice{0}; indice < subindice; ++indice) {
        cout << v[indice] << ' ';  // Mostrar cada número ya ordenado
    }
    cout << endl;

    return 0;  // Fin del programa
}
