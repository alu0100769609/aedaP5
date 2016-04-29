# Algoritmos y Estructuras de Datos Avanzadas

## Práctica 5: Ordenación

### Enunciado
Desarrollar en lenguaje **C++** diferentes algoritmos de ordenación y realizar un análisis de rendimiento de los algoritmos implementados.

* [x] **Inserción**
* [x] **Burbuja**
* [ ] **ShellSort:** Debe permitir seleccionar la constante de reducción alfa, siendo `0 < alfa < 1`
* [x] **QuickSort**
* [ ] **MergeSort**

La implementación se realizará mediante una plantilla de función en la que se especifique el tipo de elementos a ordenar y que deberá tener esta forma: `funcion(secuenciaAOrdenar,tamañoDeSecuencia)`.

Las secuencias a ordenar se generan de forma aleatoria y deben ser del tipo DNI.

Se deben realizar dos programas para ejecutar el código implementado:

* **Modo demostración:** Secuencias de hasta 25 elementos para comprobar el funcionamiento de un algoritmo determinado. El programa solicitará el tamaño de secuencia a ordenar y el algoritmo a ejecutar.

 Deberá ir  mostrando paso por paso los elementos que son comparados y cómo queda la secuencia tras la comparación y la acción correspondiente.

* **Modo estadísticas:** El programa cuenta las comparaciones para ordenar los elementos en cada algoritmo. El programa solicitará el tamaño de la secuencia a ordenar y las pruebas que se realizarán (número de veces que se repite la ejecución de cada método).

 Para cada algoritmo se genera un banco de pruebas y se ordena contando el numero de comparaciones realizadas y actualizando los valores mínimo, máximo y medio.

 La salida para este modo debe ser similar a esta:

 **Número de comparaciones:**

|            | Mínimo   |  Medio   |  Máximo  |
|------------|----------|----------|----------|
|**Método 1**|   xxxx   |   xxxx   |   xxxx   |
|**Método 2**|   xxxx   |   xxxx   |   xxxx   |
|  **....**  |   ....   |   ....   |   ....   |

De forma **opcional** se puede:
* Realizar el programa desarrollado para un estudio de la variación del comportamiento cuando se incremente el tamaño de la secuencia a ordenar.
* Implementar el resto de algoritmos de ordenación vistos en la asignatura

### Objetivo
El objetivo de esta práctica es la implementación de los **algoritmos de ordenación y su estudio** mediante los modos `estadístico` y `demostración` además de recordar la **sobrecarga de operadores**, el **manejo de excepciones** mediante try-catch y la definición de **plantillas** que se han implementado en prácticas anteriores.

### Forma de uso

Al ejecutar el programa nos pedirá la inserción de un DNI. Los formatos permitidos para el DNI son los siguientes:

| MAYÚSCULAS | MINÚSCULAS |   ESPACIOS   |
|------------|------------|--------------|
| 12345678A  | 12345678a  | 12345678 a   |
| 12345678-A | 12345678-a | 12345678 - a |

#### Compilación

```bash
$ g++ main/main.cpp cpp/*.cpp -std=c++11 -o main.out
```

#### Ejecución

```bash
$ ./main.out
```

### Autor

* [Adexe Sabina Pérez](http://alu0100769609.github.io)
* [Adexe en GitHub](http://github.com/alu0100769609)
