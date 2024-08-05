#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "archivo.h"
#include "persona.h"
#include "listaligada.h"

Archivo generador;
Archivo generador2;

void cargarDatos(Archivo &gener, const std::string& file) {
    gener.leerDesdeArchivo(file);
}

std::string SimularNombreCompleto() {
    std::string nombreCompleto = generador.obtenerItemAleatorio() + " " +
                                 generador2.obtenerItemAleatorio() + " " +
                                 generador2.obtenerItemAleatorio();
    return nombreCompleto;
}

int main() {
    cargarDatos(generador, "nombres.txt");
    cargarDatos(generador2, "apellidos.txt");

    ListaLigada lista;
    for (int i = 0; i < 1000; i++) {
        lista.agregar(Persona(SimularNombreCompleto(), 
                              generador.generarNumeroEntero(12, 89),
                              generador.fechaAleatoria(1972, 2023)));
    }

    std::cout << "Lista antes de ordenar:" << std::endl;
    lista.imprimir();

    // Medir el tiempo de ordenación
    auto inicio = std::chrono::high_resolution_clock::now(); // Captura el tiempo de inicio
      //lista.ordenarBurbuja(); // Llama al método de ordenación
      lista.mergeSort();
    auto fin = std::chrono::high_resolution_clock::now(); // Captura el tiempo de fin
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count(); // Calcula la duración en milisegundos

    std::cout << "Lista después de ordenar:" << std::endl;
    lista.imprimir();
    std::cout << "Tiempo de ordenación: " << duracion << " ms" << std::endl; // Imprime la duración
    
    return 0;
}
