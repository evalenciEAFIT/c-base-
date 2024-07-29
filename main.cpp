/*
Para compilar: g++ -o programa main.cpp persona.cpp nodo.cpp listaligada.cpp
*/

#include <iostream>
#include "persona.h"
#include "listaligada.h"

int main() {
    ListaLigada lista; // Crear una lista ligada vacía

    // Agregar varias personas a la lista
    lista.agregar(Persona("Edison", 52));
    lista.agregar(Persona("Ana", 20));
    lista.agregar(Persona("Pedro", 35));

    // Imprimir todas las personas en la lista
    lista.imprimir();
    std::cout << "===============\n";
    lista.agregar(Persona("Luisa", 35));

    // Imprimir todas las personas en la lista
    lista.imprimir();

    return 0;
}
