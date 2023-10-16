# TC1031_Tienda_Ropa

## Manejadora de artículos de ropa de una tienda
Este proyecto busca que el usuario pueda ordenar artículos de ropa de acuerdo a sus atributos. Por ahora, puede ordenarse de acuerdo al precio. 

## SICT0301: Evalúa los componentes
### Análisis de Complejidad correcto para algoritmo de ordenamiento
Complejidad de ordenamiento: 0(n log(n) )
Esta complejidad se debe a que el algoritmo divide el arreglo cada vez a la mitad y va ordenando las mitades que generó. Este proceso, conforme pasa el tiempo, permite que el arreglo sea ordenado más rápido que si fuera solo lineal. Esta parte se representa con el log(n). Sin embargo, el código no sólo se va dividiendo, sino que también une las partes divididas en un solo arreglo en una complejidad 0(n).

### Análisis de Complejidad correcto para estructuras de datos

## SICT0302: Toma de Decisiones
### Algoritmo de Ordenamiento
El algoritmo utilizado es Merge Sort para ordenar de menor a mayor valor los atributos designados. 

### Estructura de Datos
La estructura de datos implementada es una lista doblemente ligada

## SICT0303: Implementa acciones científicas
### Mecanismo para consultar información de la estructura 
El programa tiene la opción de ordenas artículos de ropa por precio.

### Mecanismo de lectura de archivos para cargar datos a la estructura
Los artículos de ropa están registrados en el archivo ropa.txt
