#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h"

// Declaración de la clase ListaLigada
class ListaLigada {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista ligada

public:
    // Constructor que inicializa la lista vacía
    ListaLigada();

    // Destructor que libera la memoria de todos los nodos
    ~ListaLigada();

    // Método para agregar un nodo al final de la lista
    void agregar(const Persona& persona);

    // Método para imprimir todos los nodos de la lista
    void imprimir() const;
};

#endif // LISTALIGADA_H
