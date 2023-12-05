
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
        // Agrega más tipos según sea necesario
        //definicion de la clase variant que puede ser int, double o string
    };
