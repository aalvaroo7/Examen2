# Examen2

https://github.com/aalvaroo7/Examen2.git

## Parte 1
1) b) rep.resentar cualquier tipo de dato lisp,puesto que la funcion variant se encarga de leer archivos y al usarla aplicada a lisp se usaría para leer archivos de esta librería
2) a) debido a que to_string() se utiliza para convertir un objeto a una representación en cadena de caracteres.
3) b) Este método se utiliza para serializar un objeto Variant en una cadena JSON, lo que significa que convierte la estructura de datos representada por el objeto Variant en una cadena de texto en formato JSON.
4) a) en términos generales, un método con ese nombre probablemente cumpliría la función de convertir una cadena JSON en un objeto Variant. Este tipo de método sería útil si se está trabajando con datos en formato JSON y se desea convertirlos en una representación interna que pueda ser manejada por la clase Variant.

La conversión de una cadena JSON a un objeto Variant generalmente implicaría analizar la cadena JSON y asignar los valores correspondientes al objeto Variant según su tipo (int, double, string, etc.). Este proceso es común al trabajar con datos JSON en aplicaciones que utilizan estructuras flexibles como la clase Variant para manejar diferentes tipos de valores.

## Parte 2
## Ejercicios 1 y 2 resueltos en EJ1.cpp , Ejercicios 3 y 4 en EJ3.cpp, Ejercicio 5 resuelto en el readme(teoria) y en ejemploexplicacion5, Ejercicio 6 en EJ6 .cpp y Ejercicio 7 resuelto en readme(teoria) y en Ejercicio7.cpp
Ejercicio 1-creo la clase enviorment, la cual recibira valores de x e y incluso manejara una excepcion en caso de leer la variable z la cual no esta creada

Ejercicio 2-creo un void el cual se encarga de almacenar los valores de x e y nuevos y los sobreescribira

Ejercicio 3-el método lookup devuelve true si el símbolo se encuentra en el entorno y actualiza el valor de la variable de salida value. Devuelve false si el símbolo no se encuentra

Ejercicio 4-se maneja una nueva excepcion aparte de la ya manejada en el ejercicio que era cuando la variable z no existia ahora se introduce otro manejo de excepcion, que se encuentre la variable pero que ya tenga un valor asignado

Ejercicio 5-La clase Environment y la clase Variant pueden trabajar juntas para proporcionar un entorno de ejecución para scripts que maneje diferentes tipos de datos de manera dinámica a través de Variant. La clase Variant proporciona una forma de representar y manipular valores de diferentes tipos (enteros, doubles, cadenas, etc.) de manera genérica. La clase Environment, por otro lado, permite la creación de un contexto de ejecución que puede almacenar variables asociadas a valores Variant.nado

Ejercicio 6-he agregado las funciones removeSymbol y symbolExists para eliminar un símbolo del entorno y verificar si un símbolo existe, respectivamente.

Ejercicio 7-Imagina que estás desarrollando un juego y deseas utilizar la clase Environment en conjunto con Variant para personalizar el comportamiento del juego. Aquí tienes un ejemplo simple donde se utiliza Environment para almacenar variables relacionadas con el estado del jugador y configuraciones del juego.

Ejercicio7.cpp-En este ejemplo:

La clase Environment se utiliza para almacenar variables relacionadas con el estado del jugador, como "health" y "score".
La función processPlayerState utiliza el entorno para obtener y mostrar el estado actual del jugador.
Se simulan cambios en el juego actualizando las variables del entorno, lo que refleja el cambio en el estado del jugador.
Este es un enfoque básico, pero en un juego más complejo, podrías utilizar Environment y Variant para gestionar configuraciones del juego, características desbloqueadas, progreso del jugador y más. La flexibilidad de Variant permite almacenar diferentes tipos de datos, mientras que Environment proporciona un contexto para organizar y acceder a estos datos de manera estructurada.







