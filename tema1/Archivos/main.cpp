/*
Comandos para compilar: g++ -c archivo.cpp
                        g++ main.cpp archivo.o -o demo
                        
Conado para ejecutar: ./demo
*/

#include <iostream>
#include "archivo.h"

int main() {
    Archivo lista;
    lista.leerDesdeArchivo("nombres.txt");

    std::cout << "Lista de items:" << std::endl;
    lista.imprimirItems();

    // Obtener y mostrar un item aleatorio
    std::string itemAleatorio = lista.obtenerItemAleatorio();
    std::cout << "Item aleatorio de la lista: " << itemAleatorio << std::endl;

    // Generar y mostrar una fecha aleatoria
    int añoInicial = 2000;
    int fechaTope = 2024;
    std::string fecha = lista.fechaAleatoria(añoInicial, fechaTope);
    std::cout << "\nFecha aleatoria entre los años(" << añoInicial << " - " << fechaTope << "): " << fecha << std::endl;

    // Generar y mostrar un número entero aleatorio en un rango
    int minEntero = 1;
    int maxEntero = 100;
    int numeroEntero = lista.generarNumeroEntero(minEntero, maxEntero);
    std::cout << "\nNúmero entero aleatorio entre " << minEntero << " y " << maxEntero << ": " << numeroEntero << std::endl;

    // Generar y mostrar un número flotante aleatorio en un rango
    float minFloat = 1.0;
    float maxFloat = 100.0;
    float numeroFloat = lista.generarNumeroFloat(minFloat, maxFloat);
    std::cout << "\nNúmero flotante aleatorio entre " << minFloat << " y " << maxFloat << ": " << numeroFloat << std::endl;


    return 0;
}
