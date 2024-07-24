#include "persona.h"

// Implementación del constructor de la clase Persona
Persona::Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

// Implementación del método para obtener el nombre
std::string Persona::getNombre() const {
    return nombre;
}

// Implementación del método para obtener la edad
int Persona::getEdad() const {
    return edad;
}

// Implementación de la sobrecarga del operador << para la clase Persona
std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
    return os;
}
