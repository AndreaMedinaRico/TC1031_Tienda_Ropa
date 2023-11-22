# TC1031_Tienda_Ropa

## Manejadora de artículos de ropa de una tienda
Este proyecto busca que el usuario pueda ordenar artículos de ropa de acuerdo a su precio. 

## SICT0301: Evalúa los componentes
### Análisis de Complejidad correcto para algoritmo de ordenamiento
Complejidad de ordenamiento: 0(n log(n) )
Esta complejidad se debe a que el algoritmo divide el arreglo cada vez a la mitad y va ordenando las mitades que generó. Este proceso, conforme pasa el tiempo, permite que el arreglo sea ordenado más rápido que si fuera solo lineal. Esta parte se representa con el log(n). Sin embargo, el código no sólo se va dividiendo, sino que también une las partes divididas en un solo arreglo en una complejidad 0(n).

### Análisis de Complejidad correcto para estructuras de datos
Complejidad: 0(n) / 0(n/2)
La complejidad varía dependiendo de la función, ya que en algunas simplemente recorre toda la lista, por lo que su complejidad es de n. En otras, logra bajar la complejidad a n/2 ya que se recorre el doble de rápido, empezando un recorrido por su head y otro por su tail. 

### Análisis de Complejidad correcto para componentes y Complejidad del programa

## SICT0302: Toma de Decisiones
### Algoritmo de Ordenamiento
El algoritmo utilizado es Merge Sort para ordenar de menor a mayor valor los atributos designados. 

### Estructura de Datos
La estructura de datos implementada es una lista doblemente ligada

## SICT0303: Implementa acciones científicas
### Mecanismo para consultar información de la estructura 
El programa tiene la opción de ordenas artículos de ropa por precio.

### Mecanismo de lectura de archivos para cargar datos a la estructura
Los artículos de ropa están registrados en el archivo ropaRead.txt

### Mecanismo de escritura de archivos para guardar datos de la estructura
Los artículos de ropa se registran en el archivo ropaWrite.txt
