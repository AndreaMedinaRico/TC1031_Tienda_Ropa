/*
* Main
* Por: Andrea Medina Rico
* A01705541
* 18/09/2023
* versión: 1
* Interacción con usuario
*/

#include "Sort.h"

int main() {
    // Creación objetos PRUEBA
    std::vector<Ropa> ropa;
    ropa.push_back(Ropa(001, "rojo", "algodon", "playera", 190, 'M'));
    ropa.push_back(Ropa(002, "azul", "poliester", "playera", 170, 'M'));
    ropa.push_back(Ropa(003, "verde", "algodon", "playera", 200, 'M'));

    Sort<Ropa> sort;

    // Variable MENÚ
    int opcion = 0;
    // MENÚ
    while (opcion == 0) {

        std::cout << "¡BIENVENIDX A LA TIENDA DE ROPA!" << std::endl;
        std::cout << "¿Que deseas hacer?" << std::endl;
        std::cout << "1. Ver catalogo" << std::endl
                << "2. Ordenar por precio" << std::endl
                << "3. Agregar articulo" << std::endl;
        
        std::cin >> opcion;

        //      1. Ver catálogo
        if (opcion == 1) {
            std::cout << "Articulos actuales: " << std::endl;
            for (int i = 0; i < ropa.size(); i++) {
                std::cout << i + 1 << ": " << std::endl;
                ropa[i].imprimir();
            }

        //      2. Ordenar por precio
        } else if (opcion == 2) {
            std::vector<Ropa> ropaOrdenada = sort.mergeSort(ropa);

            for (int i = 0; i < ropaOrdenada.size(); i++) {
                std::cout << i + 1 << ": " << std::endl;
                ropaOrdenada[i].imprimir();
            }

        //      3. Agregar artículo
        } else if (opcion == 3) {
            Ropa nueva;
            nueva.crear();
            ropa.push_back(nueva);
        }

        std::cout << "\n Si deseas regresar al menu, ingresa 0 \n";
        std::cin >> opcion;
    }
    std::cout << " \n ¡}Regresa pronto!" << std::endl;
}