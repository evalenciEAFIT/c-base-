#include "listaligada.h"
#include <iostream>

// Implementación del constructor de la clase ListaLigada
ListaLigada::ListaLigada() : cabeza(nullptr) {}

// Implementación del destructor de la clase ListaLigada
ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente; // Guardar el puntero al siguiente nodo
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

// Implementación del método para agregar un nodo al final de la lista
void ListaLigada::agregar(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona); // Crear un nuevo nodo
    if (cabeza == nullptr) { // Si la lista está vacía
        cabeza = nuevoNodo; // El nuevo nodo se convierte en la cabeza de la lista
    } else {
        Nodo* actual = cabeza; // Comenzar desde la cabeza de la lista
        while (actual->siguiente != nullptr) { // Recorrer la lista hasta el último nodo
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo; // Enlazar el último nodo con el nuevo nodo
    }
}

// Implementación del método para imprimir todos los nodos de la lista
void ListaLigada::imprimir() const {
    Nodo* actual = cabeza; // Comenzar desde la cabeza de la lista
    while (actual != nullptr) {
        std::cout << actual->data << std::endl; // Imprimir los datos del nodo actual
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}
