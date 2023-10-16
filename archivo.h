/*
* archivo.h 
* By: Andrea Medina Rico
* 11.10.23
* version: 1
* File Manager Class
*/ 

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Ropa.h"
#include "doublelist.h"

class Archivo {
    private:
        std::string nombre;

    public:
        Archivo(std::string);
        void leer(DList<Ropa> lista);
};

Archivo::Archivo(std::string n) : nombre(n) {}

// Función que lee información de un archivo y la agrega a atributos de un objeto de la clase Ropa
void Archivo::leer(DList<Ropa> lista) {
    std::ifstream archivo(nombre.c_str());
    std::string linea;
    std::string dato;
    std::string valor;

    // Si el archivo existe, se lee
    if (archivo.is_open()) {
        // Crear objeto de ropa donde se almacenará información
        Ropa ropa;

        while (getline(archivo, linea)) {
            std::stringstream stream(linea);
            int i = 0;
            // Se separa la línea por comas y se almacena en un objeto de la clase Ropa
            while (getline(stream, dato, ',')) {
                if (i == 0) {
                    ropa.set_codigo(stoi(dato));     
                } else if (i == 1) {
                    ropa.set_color(dato);
                } else if (i == 2) {
                    ropa.set_tela(dato);
                } else if (i == 3) {
                    ropa.set_tipo(dato);
                } else if (i == 4) {
                    ropa.set_precio(stoi(dato));
                } else if (i == 5) {
                    ropa.set_talla(dato[0]);
                }
                i++;

                // Se agrega el objeto a la lista si ya están llenos los atributos
                if (i == 6) {
                    lista.add(ropa);
                    ropa = Ropa();
                }
            } 
        }
        archivo.close();

    // Else --> shows error
    } else {
        std::cout << "Error en el archivo" << std::endl;
    }
}

#endif