#include <iostream>
#include <vector>

using namespace std;

void mostrarArreglo(vector<int> arr){
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        cout << arr[i] << " --> " ;
    }
    cout << arr[size - 1] << endl;
}

vector<int> invertirArreglo(vector<int> arr) {
    int size = arr.size();
    vector<int> invertido(size);
    for (int i = 0; i < size; i++) {
        invertido[i] = arr[size - 1 - i];
    }
    return invertido;
}

int main() {
    vector<int> numbers = {3, 8, 15, 42, 7};
    cout << "Arreglo original:" << endl;
    mostrarArreglo(numbers);
    numbers = invertirArreglo(numbers);
    cout << "Arreglo invertido:" << endl;
    mostrarArreglo(numbers);
    return 0;
}