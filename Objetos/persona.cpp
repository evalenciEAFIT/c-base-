#include "persona.h"
#include <iostream>

// Constructor
Persona::Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

// Destructor
Persona::~Persona() {
    std::cout << "Destructor llamado para " << nombre << std::endl;
}

// Métodos para establecer y obtener el nombre
void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Persona::getNombre() const {
    return nombre;
}

// Métodos para establecer y obtener la edad
void Persona::setEdad(int edad) {
    this->edad = edad;
}

int Persona::getEdad() const {
    return edad;
}

// Método para imprimir información de la persona
void Persona::imprimirInfo() const {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
}

// Sobrecarga del operador ==
bool Persona::operator==(const Persona& otra) const {
    return (this->nombre == otra.nombre) && (this->edad == otra.edad);
}

// Sobrecarga del operador !=
bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}
