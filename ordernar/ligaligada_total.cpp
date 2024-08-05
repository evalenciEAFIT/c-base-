#include "listaligada.h"
#include <iostream>
#include <chrono> // Biblioteca para medir el tiempo de ejecución

// Constructor que inicializa la lista vacía
ListaLigada::ListaLigada() : cabeza(nullptr) {}

// Destructor que libera la memoria de todos los nodos
ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

// Método para agregar un nodo al final de la lista
void ListaLigada::agregar(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona); // Crear un nuevo nodo con los datos de persona
    if (cabeza == nullptr) {
        cabeza = nuevoNodo; // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente; // Avanzar hasta el último nodo
        }
        actual->siguiente = nuevoNodo; // Añadir el nuevo nodo al final
    }
}

// Método para imprimir todos los nodos de la lista
void ListaLigada::imprimir() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->data << std::endl; // Imprimir los datos del nodo actual
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}

// Método para intercambiar dos nodos si el primero es mayor que el segundo
void ListaLigada::intercambiar(Nodo* nodo1, Nodo* nodo2) {
    Persona temp = nodo1->data; // Guardar temporalmente los datos de nodo1
    nodo1->data = nodo2->data; // Copiar los datos de nodo2 a nodo1
    nodo2->data = temp; // Copiar los datos originales de nodo1 a nodo2
}

// Método para ordenar la lista usando el método de burbuja
void ListaLigada::ordenarBurbuja() {
    if (cabeza == nullptr) return; // Si la lista está vacía, no hacer nada

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->data > actual->siguiente->data) {
                intercambiar(actual, actual->siguiente); // Intercambiar nodos si están en el orden incorrecto
                intercambiado = true;
            }
            actual = actual->siguiente; // Avanzar al siguiente nodo
        }
    } while (intercambiado); // Repetir hasta que no haya intercambios
}

// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo* ListaLigada::dividir(Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto) {
    if (bajo == nullptr || alto == nullptr) return nullptr; // Verificar si la lista es válida

    Nodo* pivote = alto; // El último nodo es el pivote
    Nodo* previo = nullptr;
    Nodo* actual = bajo;
    Nodo* cola = pivote;

    while (actual != pivote) {
        if (actual->data < pivote->data) {
            if (*nuevoBajo == nullptr) *nuevoBajo = actual;
            previo = actual;
            actual = actual->siguiente; // Avanzar al siguiente nodo
        } else {
            if (previo) previo->siguiente = actual->siguiente;
            Nodo* temp = actual->siguiente;
            actual->siguiente = nullptr;
            cola->siguiente = actual;
            cola = actual;
            actual = temp;
        }
    }

    if (*nuevoBajo == nullptr) *nuevoBajo = pivote;
    *nuevoAlto = cola;

    return pivote;
}

// Método auxiliar para realizar el QuickSort de manera recursiva
void ListaLigada::quickSortRec(Nodo* bajo, Nodo* alto) {
    if (bajo != nullptr && alto != nullptr && bajo != alto && bajo != alto->siguiente) {
        Nodo* nuevoBajo = nullptr;
        Nodo* nuevoAlto = nullptr;

        Nodo* pivote = dividir(bajo, alto, &nuevoBajo, &nuevoAlto);

        if (nuevoBajo != pivote) {
            Nodo* temp = nuevoBajo;
            while (temp->siguiente != pivote) temp = temp->siguiente;
            temp->siguiente = nullptr;

            quickSortRec(nuevoBajo, temp);

            temp = obtenerUltimo(nuevoBajo);
            temp->siguiente = pivote;
        }

        quickSortRec(pivote->siguiente, nuevoAlto);
    }
}

// Método auxiliar para obtener el último nodo de una lista
Nodo* ListaLigada::obtenerUltimo(Nodo* cabeza) {
    while (cabeza != nullptr && cabeza->siguiente != nullptr) {
        cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
    }
    return cabeza; // Retornar el último nodo
}

// Método para ordenar la lista usando el método de QuickSort
void ListaLigada::quickSort() {
    Nodo* cola = obtenerUltimo(cabeza);
    quickSortRec(cabeza, cola);
}

// Método auxiliar para dividir la lista en dos mitades para MergeSort
Nodo* ListaLigada::mergeSortRec(Nodo* cabeza) {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return cabeza; // Lista vacía o con un solo nodo

    Nodo* medio = cabeza;
    Nodo* fin = cabeza;
    while (fin->siguiente != nullptr && fin->siguiente->siguiente != nullptr) {
        fin = fin->siguiente->siguiente;
        medio = medio->siguiente;
    }

    Nodo* mitad = medio->siguiente;
    medio->siguiente = nullptr;

    Nodo* izquierda = mergeSortRec(cabeza);
    Nodo* derecha = mergeSortRec(mitad);

    return unir(izquierda, derecha);
}

// Método auxiliar para unir dos listas ordenadas en una sola lista
Nodo* ListaLigada::unir(Nodo* primero, Nodo* segundo) {
    if (primero == nullptr) return segundo;
    if (segundo == nullptr) return primero;

    if (primero->data < segundo->data) {
        primero->siguiente = unir(primero->siguiente, segundo);
        primero->siguiente->siguiente = nullptr;
        return primero;
    } else {
        segundo->siguiente = unir(primero, segundo->siguiente);
        segundo->siguiente->siguiente = nullptr;
        return segundo;
    }
}

// Método para ordenar la lista usando el método de Merge Sort
void ListaLigada::mergeSort() {
    cabeza = mergeSortRec(cabeza);
}
