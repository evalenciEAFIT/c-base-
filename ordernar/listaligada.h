#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h" // Incluir la declaración de la clase Nodo

// Declaración de la clase ListaLigada
class ListaLigada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista ligada

    // Método auxiliar para dividir la lista en dos mitades
    Nodo* split(Nodo* head);

    // Método auxiliar para fusionar dos listas ordenadas
    Nodo* merge(Nodo* left, Nodo* right);

    // Método auxiliar para realizar el Merge Sort de manera recursiva
    Nodo* mergeSortRec(Nodo* head);

public:
    // Constructor que inicializa la lista vacía
    ListaLigada();

    // Destructor que libera la memoria de todos los nodos
    ~ListaLigada();

    // Método para agregar un nodo al final de la lista
    void agregar(const Persona& persona);

    // Método para imprimir todos los nodos de la lista
    void imprimir() const;

    // Método para intercambiar dos nodos si el primero es mayor que el segundo
    void swap(Nodo* nodo1, Nodo* nodo2);



    // Método para ordenar la lista usando el método de burbuja
    void ordenarBurbuja();

    // Método para ordenar la lista usando el método de Merge Sort
    void mergeSort();
};

#endif // LISTALIGADA_H
