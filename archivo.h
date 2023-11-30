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
        void read(DList<int> list1, DList<int> list2, DList<int> list3);
        void write(DList<int> list1, DList<int> list2, DList<int> list3);
};

Archivo::Archivo(std::string n) : nombre(n) {}

// Reads information from file and adds attributes to DList
void Archivo::read(DList<int> list1, DList<int> list2, DList<int> list3) {
    std::ifstream archivo(nombre.c_str());
    std::string linea;

    // Si el archivo existe, se lee
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            // Si la letra es texto, la siguiente linea agregarla a la 
            // atoi -> convierte string a int
            if (linea == "Sueter:") {     /* MODIFICAR forma en la que obtiene la linea */
                getline(archivo, linea);
                while (linea != "MomJean:") {
                    list1.add(atoi(linea.c_str()));
                    getline(archivo, linea);
                }
            } else if (linea == "MomJean:") {
                getline(archivo, linea);
                while (linea != "Blusa manga corta:") {
                    list2.add(atoi(linea.c_str()));
                    getline(archivo, linea);
                }
            } else if (linea == "Blusa manga corta:") {
                getline(archivo, linea);
                while (linea != "EOF") {
                    list3.add(atoi(linea.c_str()));
                    getline(archivo, linea);
                }
            }
        }
        archivo.close();

    // Else --> shows error
    } else {
        std::cout << "Error en el archivo" << std::endl;
    }
}


// Writes information from DList to a FILE
void Archivo::write(DList<int> list1, DList<int> list2, DList<int> list3) {
    std::ofstream archivo(nombre.c_str());
    std::string linea;
    int dato;

    // Si el archivo existe, se lee
    if (archivo.is_open()) {
        DLink<int> *p;
                
        p = list1.head;
        archivo << "Sueter:" << std::endl;
        while (p != 0) {
            archivo << p->value << std::endl;
            p = p->next;
        }
                
        p = list2.head;
        archivo << "MomJean:" << std::endl;
        while (p != 0) {
            archivo << p->value << std::endl;
            p = p->next;
        }
            
        p = list3.head;
        archivo << "Blusa manga corta:" << std::endl;
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