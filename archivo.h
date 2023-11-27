/*
* archivo.h 
* By: Andrea Medina Rico
* 11.10.23
* version: 2
* File Manager Class
*/ 

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "doublelist.h"

class Archivo {
    private:
        std::string nombre;

    public:
        Archivo(std::string);
        void read(DList<int> list);
        void write(DList<int> list);
};

Archivo::Archivo(std::string n) : nombre(n) {}

// Reads information from file and adds attributes to DList
void Archivo::read(DList<int> list) {
    std::ifstream archivo(nombre.c_str());
    std::string linea;

    // Si el archivo existe, se lee
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            list.add(stoi(linea));
        }
        archivo.close();

    // Else --> shows error
    } else {
        std::cout << "Error en el archivo" << std::endl;
    }
}

// Writes information from DList to a FILE
void Archivo::write(DList<int> list) {
    std::ofstream archivo(nombre.c_str());
    std::string linea;
    int dato;

    if (archivo.is_open()) {
        DLink<int> *p;
        p = list.head;
        
        while (p != 0) {
            archivo << p->value << std::endl;
            p = p->next;
        }
        archivo.close();

    } else {
        std::cout << "Error en el archivo" << std::endl;
    }
}

#endif