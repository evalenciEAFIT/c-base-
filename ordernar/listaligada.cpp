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
        delete actual;
        actual = siguiente;
    }
}

// Método para agregar un nodo al final de la lista
void ListaLigada::agregar(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona);
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
void ListaLigada::swap(Nodo* nodo1, Nodo* nodo2) {
    Persona temp = nodo1->data;
    nodo1->data = nodo2->data;
    nodo2->data = temp;
}

// Método para ordenar la lista usando el método de burbuja
void ListaLigada::ordenarBurbuja() {
    if (cabeza == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->data > actual->siguiente->data) {
                swap(actual, actual->siguiente);
                swapped = true;
            }
            actual = actual->siguiente;
        }
    } while (swapped);
}

// Método auxiliar para dividir la lista en dos mitades
Nodo* ListaLigada::split(Nodo* head) {
    if (head == nullptr || head->siguiente == nullptr) {
        return nullptr; // La lista está vacía o tiene un solo nodo
    }

    Nodo* slow = head;
    Nodo* fast = head;
    while (fast->siguiente != nullptr && fast->siguiente->siguiente != nullptr) {
        slow = slow->siguiente; // Avanzar el puntero lento
        fast = fast->siguiente->siguiente; // Avanzar el puntero rápido
    }

    Nodo* mitad = slow->siguiente; // La segunda mitad comienza en el siguiente nodo del puntero lento
    slow->siguiente = nullptr; // Dividir la lista en dos mitades
    return mitad;
}

// Método auxiliar para fusionar dos listas ordenadas
Nodo* ListaLigada::merge(Nodo* left, Nodo* right) {
    if (left == nullptr) return right; // Si la lista izquierda está vacía, devolver la lista derecha
    if (right == nullptr) return left; // Si la lista derecha está vacía, devolver la lista izquierda

    if (left->data < right->data) {
        left->siguiente = merge(left->siguiente, right); // Fusionar el resto de la lista izquierda con la lista derecha
        return left;
    } else {
        right->siguiente = merge(left, right->siguiente); // Fusionar la lista izquierda con el resto de la lista derecha
        return right;
    }
}

// Método auxiliar para realizar el Merge Sort de manera recursiva
Nodo* ListaLigada::mergeSortRec(Nodo* head) {
    if (head == nullptr || head->siguiente == nullptr) {
        return head; // Si la lista está vacía o tiene un solo nodo, ya está ordenada
    }

    Nodo* mitad = split(head); // Dividir la lista en dos mitades
    Nodo* izquierda = mergeSortRec(head); // Ordenar la primera mitad
    Nodo* derecha = mergeSortRec(mitad); // Ordenar la segunda mitad

    return merge(izquierda, derecha); // Fusionar las dos mitades ordenadas
}

// Método para ordenar la lista usando el método de Merge Sort
void ListaLigada::mergeSort() {
    cabeza = mergeSortRec(cabeza); // Ordenar la lista y actualizar la cabeza
}
