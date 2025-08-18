#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void insertarOrdenado(Nodo** cabeza, int dato) {
    struct Nodo* nuevo = new Nodo();
    nuevo->dato = dato;

    if (*cabeza == NULL || (*cabeza)->dato > dato) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL && actual->siguiente->dato < dato) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << actual->dato << " --> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    Nodo* cabeza = NULL;

    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 5);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 2);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 8);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 1);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 3);
    mostrarLista(cabeza);
    return 0;
}