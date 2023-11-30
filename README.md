# TC1031_Tienda_Ropa

# Manejadora de artículos de ropa de una tienda
Este proyecto busca que el usuario pueda tener acceso a las tallas disponibles de los artículos de ropa especificados. Además, le permite ordenar las tallas disponibles de manera ascendente, buscar entre las listas si existe una talla y eliminar una talla de la lista. Estas acciones se pueden realizar en el menú desplegable.

## SICT0301: Evalúa los componentes
### Análisis de Complejidad correcto para algoritmo de ordenamiento
Complejidad de ordenamiento: Ω(n)
Esta es la complejidad del bubble sort en el mejor de los casos. Se toma este como ejemplo debido a que las listas doblemente ligadas de artículos de ropa no tienen muchos elementos (números), así que no se acercarían al peor de los casos. 

### Análisis de Complejidad correcto para estructuras de datos
Complejidad: 0(n) / 0(n/2)
La complejidad varía dependiendo de la función, ya que en algunas simplemente recorre toda la lista, por lo que su complejidad es de n. En otras, logra bajar la complejidad a n/2 ya que se recorre el doble de rápido, empezando un recorrido por su head y otro por su tail. 

### Análisis de Complejidad correcto para componentes y Complejidad del programa

## SICT0302: Toma de Decisiones
### Algoritmo de Ordenamiento
El algoritmo utilizado es Merge Sort para ordenar de menor a mayor valor los atributos designados cuando el usuario lo indica. 

### Estructura de Datos
La estructura de datos implementada es una lista doblemente ligada. Se utiliza para almacenar datos enteros (int) que representan las tallas disponibles de cada artículo de ropa.

## SICT0303: Implementa acciones científicas
### Mecanismo para consultar información de la estructura 
El programa tiene la opción de buscar una talla dentro de listas, así como de ordenarlas de manera ascendente.

### Mecanismo de lectura de archivos para cargar datos a la estructura
Los artículos de ropa con sus respectivas tallas están registrados en el archivo ropaRead.txt.

### Mecanismo de escritura de archivos para guardar datos de la estructura
Los artículos de ropa con sus respectivas tallas se registran en el archivo ropaWrite.txt. En caso de haber agregado o eliminado una talla, también queda registrado el cambio.
