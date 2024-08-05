#include "persona.h"

// Constructor que inicializa los atributos nombre, edad y fecha
Persona::Persona(const std::string& nombre, int edad, const std::string& fecha) 
    : nombre(nombre), edad(edad), fecha(fecha) {}

// Método para obtener el nombre de la persona
std::string Persona::getNombre() const {
    return nombre;
}

// Método para obtener la edad de la persona
int Persona::getEdad() const {
    return edad;
}

// Método para obtener la fecha de nacimiento de la persona
std::string Persona::getFecha() const {
    return fecha;
}

// Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Fecha: " << persona.fecha;
    return os;
}

// Sobrecarga del operador > para comparar dos objetos Persona por edad
bool Persona::operator>(const Persona& otra) const {
    return edad > otra.edad;
}

// Sobrecarga del operador < para comparar dos objetos Persona por edad
bool Persona::operator<(const Persona& otra) const {
    return edad < otra.edad;
}

// Sobrecarga del operador == para comparar dos objetos Persona por edad
bool Persona::operator==(const Persona& otra) const {
    return edad == otra.edad;
}
