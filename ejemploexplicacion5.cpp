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