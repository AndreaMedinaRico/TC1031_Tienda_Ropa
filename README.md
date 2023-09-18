# TC1031_Tienda_Ropa

## Manejadora de artículos de ropa de una tienda
Este proyecto busca que el usuario pueda ordenar artículos de ropa de acuerdo a sus atributos. Por ahora, puede ordenarse de acuerdo al precio. 

### Análisis de Complejidad
Complejidad de ordenamiento: 0(n log(n) )
Esta complejidad se debe a que el algoritmo divide el arreglo cada vez a la mitad y va ordenando las mitades que generó. Este proceso, conforme pasa el tiempo, permite que el arreglo sea ordenado más rápido que si fuera solo lineal. Esta parte se representa con el log(n). Sin embargo, el código no sólo se va dividiendo, sino que también une las partes divididas en un solo arreglo en una complejidad 0(n).

### Algoritmo de Ordenamiento
El algoritmo utilizado es Merge Sort para ordenar de menor a mayor valor los atributos designados. 
