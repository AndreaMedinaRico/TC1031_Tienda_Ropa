/*
* main.cpp
* By: Andrea Medina Rico
* A01705541
* 11.10.23
* version: 4
* Interactive menu with user
*/

#include "doublelist.h"
#include "Sort.h"
#include "archivo.h"
#include <iostream>
#include <string>

int main() {
    DList<int> list;
    DList<int> prueba;
    Sort<int> sort;

    // Prueba
    prueba.add(5);
    prueba.add(3);
    prueba.add(1);

    Archivo archivoR("ropaRead.txt");
    Archivo archivoW("ropaWrite.txt");

    archivoR.read(list);
    archivoW.write(list);
    archivoW.write(prueba);

    // MENU variable
    int opcion = 0;
    // MENU
    while (opcion == 0) {

        std::cout << "¡BIENVENIDX A LA TIENDA DE ROPA!" << std::endl;
        std::cout << "¿Que deseas hacer?" << std::endl;
        std::cout << "1. Ver catalogo" << std::endl
                << "2. Ordenar por precio" << std::endl
                << "3. Agregar precio " << std::endl;

        
        std::cin >> opcion;

        //      1. Ver catálogo
        if (opcion == 1) {
            std::cout << "Articulos actuales: " << std::endl;
            std::cout << list.toString();
            std::cout << prueba.toString();

        //      2. Ordenar por precio
        } else if (opcion == 2) {
            DList<int> ropaOrdenada = sort.selectionSort(list);
            ropaOrdenada.toString();

        //      3. Agregar artículo
        } else if (opcion == 3) {
            int valor;
            std::cin >> valor;
            list.add(valor);
        }

        std::cout << "\n Si deseas regresar al menu, ingresa 0 \n";
        std::cout << "Si deseas salir, ingresa cualquier otro numero \n";
        std::cin >> opcion;
    }
    std::cout << " \n ¡Regresa pronto!" << std::endl;
}