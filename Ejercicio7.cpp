#include <iostream>
#include <string>

class Variant {
public:
    // Definir un tipo para representar valores flexibles
    using Value = std::variant<int, double, std::string>;

    // Constructor que acepta un valor inicial
    Variant(const Value& val) : value(val) {}

    // Obtener el valor almacenado en Variant
    Value getValue() const {
        return value;
    }

    // Imprimir el valor almacenado
    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }
private:
    Value value;
};

class Environment {
public:
    // Método para agregar un símbolo y su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }

    // Método para obtener el valor asociado a un símbolo en la tabla de símbolos
    Variant::Value getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second; // Devuelve el valor asociado al símbolo
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido." << std::endl;
            return Variant::Value{}; // Devuelve un valor predeterminado
        }
    }

private:
    std::map<std::string, Variant::Value> symbolTable;
};
// Función para procesar el estado del jugador usando Environment
void processPlayerState(const Environment& env) {
    // Obtener valores relacionados con el estado del jugador
    Variant::Value playerHealth = env.getSymbolValue("health");
    Variant::Value playerScore = env.getSymbolValue("score");

    // Mostrar información del estado del jugador
    std::cout << "Player Health: ";
    Variant(playerHealth).printValue();

    std::cout << "Player Score: ";
    Variant(playerScore).printValue();
}

int main() {
    Environment gameEnvironment;

    // Configurar variables relacionadas con el estado del jugador
    gameEnvironment.addSymbol("health", 100);
    gameEnvironment.addSymbol("score", 0);

    // Mostrar el estado inicial del jugador
    std::cout << "Estado inicial del jugador:" << std::endl;
    processPlayerState(gameEnvironment);

    // Simular cambios en el juego y actualizar el entorno
    gameEnvironment.addSymbol("health", 75);
    gameEnvironment.addSymbol("score", 50);

    // Mostrar el estado actualizado del jugador
    std::cout << "\nEstado actualizado del jugador:" << std::endl;
    processPlayerState(gameEnvironment);

    return 0;
}