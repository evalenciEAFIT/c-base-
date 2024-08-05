#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h" // Incluir la declaración de la clase Nodo

// Declaración de la clase ListaLigada
class ListaLigada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista ligada

    // Método auxiliar para dividir la lista en dos partes según el pivote
    Nodo* dividir(Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto);

    // Método auxiliar para realizar el QuickSort de manera recursiva
    void quickSortRec(Nodo* bajo, Nodo* alto);

    // Método auxiliar para obtener el último nodo de una lista
    Nodo* obtenerUltimo(Nodo* cabeza);

    // Método auxiliar para dividir la lista en dos mitades para MergeSort
    Nodo* mergeSortRec(Nodo* cabeza);

    // Método auxiliar para unir dos listas ordenadas en una sola lista
    Nodo* unir(Nodo* primero, Nodo* segundo);

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
    void intercambiar(Nodo* nodo1, Nodo* nodo2);

    // Método para ordenar la lista usando el método de burbuja
    void ordenarBurbuja();

    // Método para ordenar la lista usando el método de Merge Sort
    void mergeSort();

    // Método para ordenar la lista usando el método de QuickSort
    void quickSort();
};

#endif // LISTALIGADA_H
