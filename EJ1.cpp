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

private:
    std::map<std::string, int> symbolTable;
};

int main() {
    // Ejemplo de uso
    Environment env;

    // Agregar símbolos al entorno
    env.addSymbol("x", 10);
    env.addSymbol("y", 20);

    // Obtener valores de símbolos desde el entorno
    int valueX = env.getSymbolValue("x");
    int valueY = env.getSymbolValue("y");

    std::cout << "Value of x: " << valueX << std::endl;
    std::cout << "Value of y: " << valueY << std::endl;

    // Intentar obtener un símbolo que no está en el entorno
    int valueZ = env.getSymbolValue("z");

    // Insertar o actualizar un nuevo símbolo (sobrescribirá si ya existe)
    env.insertSymbol("z", 30);

    // Insertar o actualizar un símbolo existente (sobrescribirá el valor)
    env.insertSymbol("x", 40);
    env.insertSymbol("y", 50);

    // Obtener los nuevos valores de x e y después de la sobrescritura
    int newValueX = env.getSymbolValue("x");
    int newValueY = env.getSymbolValue("y");

    std::cout << "New value of x: " << newValueX << std::endl;
    std::cout << "New value of y: " << newValueY << std::endl;

    return 0;
}