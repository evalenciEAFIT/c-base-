#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor
    Persona(const std::string& nombre, int edad);

    // Destructor
    ~Persona();

    // Métodos para establecer y obtener el nombre
    void setNombre(const std::string& nombre);
    std::string getNombre() const;

    // Métodos para establecer y obtener la edad
    void setEdad(int edad);
    int getEdad() const;

    // Método para imprimir información de la persona
    void imprimirInfo() const;

    // Sobrecarga de operadores de comparación
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
};

#endif // PERSONA_H
