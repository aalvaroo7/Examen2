
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Variant {
public:
    enum class Type {
        INT,
        DOUBLE,
        STRING,
        //definicion de la clase variant que puede ser int, double o string
    };
private:
    Type valueType;
    union {
        int intValue;
        double doubleValue;
        std::string stringValue;
        //union que contiene los valores de los tipos de variant y no puede ser modificado(es un private)
    };
public:
};
class Environment {
private:
    std::map<std::string, Variant> symbolTable;
public:
    // Constructor
    Environment() {}
    // Función para asignar un valor a una variable en el entorno
    void setVariable(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }
    // Función para obtener el valor de una variable del entorno
    Variant getVariable(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;