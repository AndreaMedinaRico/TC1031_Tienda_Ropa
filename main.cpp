/*
* main.cpp
* By: Andrea Medina Rico
* A01705541
* 11.10.23
* version: 4
* Interactive menu with user
*/

#include "doublelist.h"
#include "archivo.h"
#include <iostream>
#include <string>

int main() {
    // Artículos
    DList<std::string> articulos;
    articulos.add("Sueter");
    articulos.add("Mom jean");
    articulos.add("Blusa manga corta");

    // Tallas
    DList<int> sueter;
    DList<int> momJean;
    DList<int> blusa;

    DList<int> sueterOrd;
    DList<int> momJeanOrd;
    DList<int> blusaOrd;

    sueter.add(4);
    sueter.add(10);
    sueter.add(8);
    sueter.add(14);

    momJean.add(6);
    momJean.add(9);
    momJean.add(8);
    momJean.add(12);

    blusa.add(12);
    blusa.add(8);
    blusa.add(6);
    blusa.add(10);

    Archivo archivoR("ropaRead.txt");
    Archivo archivoW("ropaWrite.txt");

    archivoR.read(sueter, momJean, blusa);

    // MENU variable
    int opcion = 0;
    int opcion_1 = 0;
    int talla = 0;
    // MENU
    while (opcion == 0) {

        std::cout << "¡BIENVENIDX A LA TIENDA DE ROPA!" << std::endl;
        std::cout << "Este sistema te ayuda a verificar el catalogo de articulos disponibles con sus respectivas tallas. \n";
        std::cout << "La información se obtiene del archivo ropaRead.txt \n";
        std::cout << "¿Que deseas hacer?" << std::endl;
        std::cout << "1. Ver catalogo de articulos y tallas" << std::endl
                << "2. Ordenar por talla" << std::endl
                << "3. Agregar una talla disponible" << std::endl
                << "4. Buscar una talla" << std::endl
                << "5. Salir" << std::endl;

        std::cin >> opcion;

        //      1. Ver catálogo
        if (opcion == 1) {
            std::cout << "Articulos actuales: " << std::endl;
            std::cout << articulos.toStringA() << std::endl;

                std::cout << "Sueter: \n" << sueter.toString();
                std::cout << "\nMom jean:\n" << momJean.toString();
                std::cout << "\nBlusa manga corta:\n" << blusa.toString();


        //      2. Ordenar por talla
        } else if (opcion == 2) {
            std::cout << "Articulos ordenados: \n";
                sueter.bubbleSort();
                momJean.bubbleSort();
                blusa.bubbleSort();

                std::cout << "Sueter: \n" << sueter.toString();
                std::cout << "\nMomJean: \n" << momJean.toString();
                std::cout << "\nBlusa Manga Corta: \n" << blusa.toString();


        //      3. Agregar talla
        } else if (opcion == 3) {
            std::cout << "Ingresa la talla a agregar: \n";
            std::cin >> talla;

            std::cout << "¿A que articulo deseas agregarle la talla? \n";
            std::cout << articulos.toStringA();
            std::cin >> opcion_1;

            if (opcion_1 == 1)
                sueter.add(talla);
            else if (opcion_1 == 2)
                momJean.add(talla);
            else if (opcion_1 == 3)
                blusa.add(talla);

        //      4. Buscar talla
        }  else if (opcion == 4) {
            std::cout << "Ingresa la talla que deseas buscar: \n";
            std::cin >> talla;

            std::cout << "¿En que articulo deseas agregarle la talla? \n";
            std::cout << articulos.toStringA();
            std::cin >> opcion_1;

            bool found;
            if (opcion_1 == 1)
                found = sueter.find(talla);
            else if (opcion_1 == 2)
                found = momJean.find(talla);
            else if (opcion_1 == 3)
                found = blusa.find(talla);

            if (found == true)
                std::cout << "La talla " << talla << " SÍ se encuentra en el articulo. " << std::endl;
            else
                std::cout << "La talla " << talla << " NO se encuentra en el articulo." << std::endl;

        } else {
            std::cout << "\n Si deseas regresar al menu, ingresa 0 \n";
        }

        std::cout << "\n Si deseas regresar al menu, ingresa 0 \n";
        std::cout << "Si deseas salir, ingresa cualquier otro numero \n";
        std::cin >> opcion;
    }
    archivoW.write(sueter, momJean, blusa);
    std::cout << "La información ha sido actualizada en el archivo ropaWrite.txt \n";
    std::cout << " \n ¡Regresa pronto!" << std::endl;
}