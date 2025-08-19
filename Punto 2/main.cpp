#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

/* 
 * Inserta un nuevo nodo en una lista enlazada simple manteniendo el orden ascendente.
 *
 * Parámetros de entrada:
 *   - Nodo** cabeza: puntero a un puntero de tipo Nodo que apunta al primer elemento de la lista.
 *   - int dato: valor entero que se desea insertar en la lista.
 *
 * Salida:
 *   - La lista enlazada queda modificada, conteniendo el nuevo nodo en la posición ordenada.
 */
void insertarOrdenado(Nodo** cabeza, int dato) {
    struct Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

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

/* 
 * Recorre y muestra todos los elementos de la lista enlazada en consola.
 */
void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << actual->dato << " --> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

/* 
 * Libera la memoria de todos los nodos de la lista enlazada.
 *
 * Parámetros de entrada:
 *   - Nodo*& cabeza: referencia al puntero que apunta al primer nodo de la lista.
 *
 * Salida:
 *   - La lista queda vacía y toda la memoria asignada se libera con delete.
 */
void liberarLista(Nodo*& cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual; // Guardar el nodo actual en un puntero temporal
        actual = actual->siguiente; // Avanzar al siguiente nodo
        delete temp; // Liberar la memoria del nodo actual
    }
    cabeza = NULL; // Al final, la lista queda vacía
}

int main() {
    Nodo* cabeza = NULL;

    cout << "Lista inicial:" << endl;
    mostrarLista(cabeza);

    insertarOrdenado(&cabeza, 25);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 10);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 30);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 1);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 3);
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 3); // valor repetido
    mostrarLista(cabeza);
    insertarOrdenado(&cabeza, 501); // mayor al final
    mostrarLista(cabeza);

    // Liberar memoria al final del programa
    liberarLista(cabeza);
    cout << "Memoria liberada, lista final:" << endl;
    mostrarLista(cabeza);

    return 0;
}
