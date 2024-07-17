/*
Para compilar:  g++ -c persona.cpp
                g++ main.cpp persona.o -o demo
                
Para ejecutar:  ./demo
*/

#include <iostream>
#include "persona.h"

int main() {
    // Crear dos objetos Persona
    Persona persona1("Juan", 30);
    Persona persona2("Carlos", 35);
    Persona persona3("Juan", 30);

    // Usar métodos para obtener información
    std::cout << "Persona 1 - ";
    persona1.imprimirInfo();
    std::cout << "Persona 2 - ";
    persona2.imprimirInfo();
    std::cout << "Persona 3 - ";
    persona3.imprimirInfo();

    // Comparar objetos
    if (persona1 == persona2) {
        std::cout << "Persona 1 y Persona 2 son iguales." << std::endl;
    } else {
        std::cout << "Persona 1 y Persona 2 son diferentes." << std::endl;
    }

    if (persona1 == persona3) {
        std::cout << "Persona 1 y Persona 3 son iguales." << std::endl;
    } else {
        std::cout << "Persona 1 y Persona 3 son diferentes." << std::endl;
    }

    return 0;
}
