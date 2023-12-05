#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

// Definición de la clase Variant
class Variant {
public:
    enum class Type {
        INT,
        DOUBLE,
        STRING
    };
private:
    Type valueType;
    union {
        int intValue;
        double doubleValue;
        std::string stringValue;
    };
public:
    // Constructores para cada tipo de valor
    Variant(int value) : valueType(Type::INT), intValue(value) {}
    Variant(double value) : valueType(Type::DOUBLE), doubleValue(value) {}
    Variant(const std::string& value) : valueType(Type::STRING), stringValue(value) {}

    // Métodos para obtener el valor y el tipo
    int getInt() const { return intValue; }
    double getDouble() const { return doubleValue; }
    std::string getString() const { return stringValue; }
    Type getType() const { return valueType; }
};

// Definición de la clase Environment
class Environment {
private:
    std::map<std::string, Variant> symbolTable;
public:
    // Función para asignar un valor a una variable en el entorno
    void setVariable(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }

    // Función para obtener el valor de una variable del entorno
    Variant getVariable(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Error: Variable '" + name + "' not found in the environment.");
        }
    }
};

int main() {
    // Ejemplo de uso

    // Crear una instancia de Environment
    Environment env;

    // Asignar valores a variables en el entorno utilizando Variant
    env.setVariable("x", Variant(42));          // Entero
    env.setVariable("y", Variant(3.14));        // Double
    env.setVariable("message", Variant("Hola")); // Cadena

    // Obtener valores de variables desde el entorno y mostrarlos
    try {
        Variant resultX = env.getVariable("x");
        std::cout << "Value of x: " << resultX.getInt() << std::endl;

        Variant resultY = env.getVariable("y");
        std::cout << "Value of y: " << resultY.getDouble() << std::endl;

        Variant resultMessage = env.getVariable("message");
        std::cout << "Value of message: " << resultMessage.getString() << std::endl;

        // Intentar obtener una variable que no está en el entorno
        try {
            Variant resultZ = env.getVariable("z");
            // Esto lanzará una excepción
        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}