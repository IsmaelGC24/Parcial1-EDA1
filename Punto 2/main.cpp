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
 *
 * Parámetros de entrada:
 *   - Nodo* cabeza: puntero al primer nodo de la lista (puede ser NULL si está vacía).
 *
 * Salida:
 *   - No retorna valores, pero escribe en pantalla la secuencia de datos de la lista,
 *     mostrando un " --> " entre elementos y finalizando con "NULL".
 */
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