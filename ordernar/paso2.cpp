#include <iostream>
#include <chrono> // Biblioteca para medir el tiempo de ejecución
#include "archivo.h"
#include "persona.h"
#include "listaligada.h"

Archivo generador;
Archivo generador2;

void cargarDatos(ListaLigada &lista) {
    // Cargar datos en el archivo generador y generador2
    generador.leerDesdeArchivo("nombres.txt");
    generador2.leerDesdeArchivo("apellidos.txt");
    
    for (int i = 0; i < 10; i++) {
        // Agregar personas con nombres aleatorios, edades y fechas aleatorias a la lista
        lista.agregar(Persona(
            generador.obtenerItemAleatorio() + " " +
            generador2.obtenerItemAleatorio() + " " +
            generador2.obtenerItemAleatorio(),
            generador.generarNumeroEntero(12, 89),
            generador.fechaAleatoria(1972, 2023)
        ));
    }
}

template <typename Func>
void medirTiempoOrdenamiento(Func funcionOrdenamiento, ListaLigada &lista, const std::string &nombreMetodo) {
    // Medir el tiempo que tarda el método de ordenamiento en ordenar la lista
    auto inicio = std::chrono::high_resolution_clock::now();
    
    funcionOrdenamiento();
    
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    
    std::cout << "Tiempo de " << nombreMetodo << ": " << duracion.count() << " segundos" << std::endl;
}

int main() {
    // Crear una lista ligada y cargar datos
    ListaLigada lista;

    cargarDatos(lista);
    
    std::cout << "Lista original:" << std::endl;
    lista.imprimir();
    
    // Clonar la lista para las pruebas de ordenamiento
    ListaLigada listaBurbuja = lista;
    ListaLigada listaMergeSort = lista;
    ListaLigada listaQuickSort = lista;
    
    // Medir tiempo para Burbuja
    medirTiempoOrdenamiento([&]() { listaBurbuja.ordenarBurbuja(); }, listaBurbuja, "ordenarBurbuja");
    std::cout << "Lista ordenada por Burbuja:" << std::endl;
    listaBurbuja.imprimir();
    
    // Medir tiempo para MergeSort
    medirTiempoOrdenamiento([&]() { listaMergeSort.mergeSort(); }, listaMergeSort, "mergeSort");
    std::cout << "Lista ordenada por MergeSort:" << std::endl;
    listaMergeSort.imprimir();
    
    // Medir tiempo para QuickSort
    medirTiempoOrdenamiento([&]() { listaQuickSort.quickSort(); }, listaQuickSort, "quickSort");
    std::cout << "Lista ordenada por QuickSort:" << std::endl;
    listaQuickSort.imprimir();
    
    return 0;
}
