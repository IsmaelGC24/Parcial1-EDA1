#include <iostream>
#include <vector>

using namespace std;

/* 
 * Recorre e imprime los elementos de un arreglo (vector de enteros) en consola.
 *
 * Parámetros de entrada:
 *   - vector<int> arr: vector de enteros que se desea mostrar.
 *
 * Salida:
 *   - No retorna ningún valor.
 *   - Escribe en pantalla todos los valores del vector separados con " --> ".
 *   - El último elemento se imprime sin flecha al final, seguido de un salto de línea.
 */
void mostrarArreglo(vector<int> arr){
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        cout << arr[i] << " --> " ;
    }
    cout << arr[size - 1] << endl;
}

/* 
 * Crea una nueva copia del vector con los elementos en orden inverso.
 *
 * Parámetros de entrada:
 *   - vector<int> arr: vector de enteros a invertir.
 *
 * Salida:
 *   - Retorna un nuevo vector<int> que contiene los mismos valores que arr pero en orden invertido.
 */
vector<int> invertirArreglo(vector<int> arr) {
    int size = arr.size();
    vector<int> invertido(size);
    for (int i = 0; i < size; i++) {
        invertido[i] = arr[size - 1 - i];
    }
    return invertido;
}

int main() {
    vector<int> numbers = {3, 8, 15, 42, 7, -23, 11, 99, 15, 0};
    cout << "Arreglo original:" << endl;
    mostrarArreglo(numbers);
    numbers = invertirArreglo(numbers);
    cout << "Arreglo invertido:" << endl;
    mostrarArreglo(numbers);
    return 0;
}
