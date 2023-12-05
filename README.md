# Examen2

https://github.com/aalvaroo7/Examen2.git

## Parte 1
1) b) rep.resentar cualquier tipo de dato lisp,puesto que la funcion variant se encarga de leer archivos y al usarla aplicada a lisp se usaría para leer archivos de esta librería
2) a) debido a que to_string() se utiliza para convertir un objeto a una representación en cadena de caracteres.
3) b) Este método se utiliza para serializar un objeto Variant en una cadena JSON, lo que significa que convierte la estructura de datos representada por el objeto Variant en una cadena de texto en formato JSON.
4) c) Este método se utiliza para analizar o interpretar una cadena JSON y construir un objeto Variant a partir de la información contenida en la cadena JSON. En otras palabras, toma una representación JSON en forma de cadena y la convierte en una estructura de datos que puede ser manipulada y utilizada como un objeto Variant. Este proceso se conoce comúnmente como "parsing" o "parsing JSON".

## Parte 2
## Ejercicios 1 y 2 resueltos en EJ1.cpp , Ejercicios 3 y 4 en EJ3.cpp,
Ejercicio 1-creo la clase enviorment, la cual recibira valores de x e y incluso manejara una excepcion en caso de leer la variable z la cual no esta creada
Ejercicio 2-creo un void el cual se encarga de almacenar los valores de x e y nuevos y los sobreescribira
Ejercicio 3-el método lookup devuelve true si el símbolo se encuentra en el entorno y actualiza el valor de la variable de salida value. Devuelve false si el símbolo no se encuentra
Ejercicio 4-se maneja una nueva excepcion aparte de la ya manejada en el ejercicio que era cuando la variable z no existia ahora se introduce otro manejo de excepcion, que se encuentre la variable pero que ya tenga un valor asignado
Ejercicio 5-La clase Environment y la clase Variant pueden trabajar juntas para proporcionar un entorno de ejecución para scripts que maneje diferentes tipos de datos de manera dinámica a través de Variant. La clase Variant proporciona una forma de representar y manipular valores de diferentes tipos (enteros, doubles, cadenas, etc.) de manera genérica. La clase Environment, por otro lado, permite la creación de un contexto de ejecución que puede almacenar variables asociadas a valores Variant.nado


