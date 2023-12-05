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
