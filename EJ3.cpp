#include <map>
#include <string>
#include <iostream>
#include <stdexcept> // Necesario para trabajar con excepciones estándar

class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor (no es necesario en este caso, se proporciona como ejemplo)
    ~Environment() {}

    // Función para agregar un símbolo y su valor al entorno
    void addSymbol(const std::string& name, int value) {
        symbolTable[name] = value;
    }

    // Función para obtener el valor de un símbolo desde el entorno
    int getSymbolValue(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Error: Symbol '" + name + "' not found in the environment.");
        }
    }

    // Método para insertar un símbolo en el entorno (sobrescribiendo si ya existe)
    void insertSymbol(const std::string& name, int value) {
        auto it = symbolTable.find(name);
        if (it == symbolTable.end()) {
            // Si no existe, insertar o actualizar el valor del símbolo
            symbolTable[name] = value;
        } else {
            // Si ya existe, verificar si el valor es diferente
            if (it->second != value) {
                throw std::runtime_error("Error: Symbol '" + name + "' already exists in the environment with a different value.");
            }
        }
    }

    // Método para buscar un símbolo en el entorno
    bool lookup(const std::string& name, int& value) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            value = it->second;
            return true; // Símbolo encontrado
        } else {
            // Símbolo no encontrado
            throw std::runtime_error("Warning: Symbol '" + name + "' not found in the environment.");
            return false;
        }
    }

private:
    std::map<std::string, int> symbolTable;
};

int main() {
    try {
        // Ejemplo de uso
        Environment env;

        // Agregar símbolos al entorno
        env.addSymbol("x", 10);
        env.addSymbol("y", 20);

        // Buscar valores de símbolos en el entorno
        int valueX;
        if (env.lookup("x", valueX)) {
            std::cout << "Value of x: " << valueX << std::endl;
        }

        int valueY;
        if (env.lookup("y", valueY)) {
            std::cout << "Value of y: " << valueY << std::endl;
        }

        // Intentar buscar un símbolo que no está en el entorno
        int valueZ;
        if (env.lookup("z", valueZ)) {
            std::cout << "Value of z: " << valueZ << std::endl;
        }

        // Intentar insertar un símbolo ya existente con un valor diferente
        env.insertSymbol("x", 15);

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}