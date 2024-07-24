#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

// Declaración de la clase Persona
class Persona {
private:
    std::string nombre; // Atributo para almacenar el nombre de la persona
    int edad;           // Atributo para almacenar la edad de la persona

public:
    // Constructor que inicializa los atributos nombre y edad
    Persona(const std::string& nombre, int edad);

    // Métodos para obtener los valores de los atributos
    std::string getNombre() const;
    int getEdad() const;

    // Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);
};

#endif // PERSONA_H
