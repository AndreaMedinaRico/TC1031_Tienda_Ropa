/*
* Clase Ropa
* Por: Andrea Medina Rico
* A01705541
* 18/09/2023
* versión: 1
*/

#ifndef ROPA_H_
#define ROPA_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Ropa {
    protected:
        int codigo;
        std::string color;
        std::string tela;
        std::string tipo;
        int precio;
        char talla;

    public:
        Ropa(): codigo(0), color(""), tela(""), tipo(""), precio(0), talla(' ') {};
        Ropa(int cod, std::string col, std::string tel, std::string tip, int pre, char tal):
            codigo(cod), color(col), tela(tel), tipo(tip), precio(pre), talla(tal) {};

        // Getters y setters
        int getPrecio() { return precio; };

        void setCodigo() { 
            std::cout << "Codigo: "; std::cin >> codigo; 
        }
        void setColor() {
            std::cout << "Color: "; std::cin >> color; 
        }
        void setTela() { 
            std::cout << "Tela: "; std::cin >> tela; 
        }
        void setTipo() {
            std::cout << "Tipo: "; std::cin >> tipo; 
        }
        void setPrecio() { 
            std::cout << "Precio: "; std::cin >> precio; 
        }
        void setTalla() {
            std::cout << "Talla: "; std::cin >> talla; 
        }

        void imprimir();
        void crear() {
            setCodigo();
            setColor();
            setTela();
            setTipo();
            setPrecio();
            setTalla();
        }

};

void Ropa::imprimir() {
    std::cout << "Codigo: " << codigo << std::endl
            << "Color: " << color << std::endl
            << "Tela: " << tela << std::endl
            << "Tipo: " << tipo << std::endl
            << "Precio: " << precio << std::endl
            << "Talla: " << talla << std::endl << std::endl;
}

#endif