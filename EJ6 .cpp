#include <map>
#include <string>
#include <iostream>

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
            std::cerr << "Error: Symbol '" << name << "' not found in the environment." << std::endl;
            return 0; // Puedes cambiar esto según tus necesidades
        }
    }

    // Método para insertar un símbolo en el entorno (sobrescribiendo si ya existe)
    void insertSymbol(const std::string& name, int value) {
        // Insertar o actualizar el valor del símbolo
        symbolTable[name] = value;
    }

    // Método para eliminar un símbolo del entorno
    void removeSymbol(const std::string& name) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
            std::cout << "Symbol '" << name << "' removed from the environment." << std::endl;
        } else {
            std::cerr << "Error: Symbol '" << name << "' not found in the environment. Unable to remove." << std::endl;
        }
    }

    // Método para verificar si un símbolo existe en el entorno
    bool symbolExists(const std::string& name) const {
        return symbolTable.find(name) != symbolTable.end();
    }