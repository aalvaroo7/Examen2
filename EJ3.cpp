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

