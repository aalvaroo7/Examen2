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
