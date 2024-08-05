#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

// Declaración de la clase Persona
class Persona {
private:
    std::string nombre; // Atributo para almacenar el nombre de la persona
    int edad;           // Atributo para almacenar la edad de la persona
    std::string fecha;  // Atributo para almacenar la fecha de nacimiento de la persona

public:
    // Constructor que inicializa los atributos nombre, edad y fecha
    Persona(const std::string& nombre, int edad, const std::string& fecha);

    // Métodos para obtener los valores de los atributos
    std::string getNombre() const;
    int getEdad() const;
    std::string getFecha() const;

    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);

    // Sobrecarga de los operadores de comparación
    bool operator>(const Persona& otra) const;
    bool operator<(const Persona& otra) const;
    bool operator==(const Persona& otra) const;
};

#endif // PERSONA_H
