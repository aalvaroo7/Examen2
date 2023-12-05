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

