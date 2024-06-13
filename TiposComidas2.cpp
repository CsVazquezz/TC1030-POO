#include "TiposComidas2.h"
#include <iostream>

Comida::Comida(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos) //constructor con parametros de comida
    : nombre(nombre), calorias(calorias), proteinas(proteinas), grasas(grasas), carbohidratos(carbohidratos) {}


//definicion de getters
double Comida::getCalorias() { return calorias; } 
double Comida::getProteinas() { return proteinas; }
double Comida::getGrasas() { return grasas; }
double Comida::getCarbohidratos() { return carbohidratos; }

VegetalYFruta::VegetalYFruta(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), tipo(tipo) {} //constructor con parametros de vegetal y frutas

void VegetalYFruta::mostrarInformacion() { //sobrescritura del metodo de comida
    std::cout << "\nInformacion nutricional de " << nombre << ":\n\n";
    std::cout << " Calorias: " << calorias << "  \n";
    std::cout << " Proteinas: " << proteinas << "  \n";
    std::cout << " Grasas: " << grasas << "  \n";
    std::cout << " Carbohidratos: " << carbohidratos << "\n";
    std::cout << " Tipo: " << tipo << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "tipo"
}

Cereales::Cereales(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, double fibra)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), fibra(fibra) {} //constructor con parametros de cereal

void Cereales::mostrarInformacion() { //sobrescritura del metodo de comida
    std::cout << "\nInformacion nutricional de " << nombre << ":\n\n";
    std::cout << " Calorias: " << calorias << "  \n";
    std::cout << " Proteinas: " << proteinas << "  \n";
    std::cout << " Grasas: " << grasas << "  \n";
    std::cout << " Carbohidratos: " << carbohidratos << "\n";
    std::cout << " Fibra: " << fibra << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "fibra"
}

LegumbreYOrigenAnimal::LegumbreYOrigenAnimal(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, int vitaminas)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), vitaminas(vitaminas) {} //constructor con parametros de legumbre y origen animal

void LegumbreYOrigenAnimal::mostrarInformacion() { //sobrescritura del metodo de comida
    std::cout << "\nInformacion nutricional de " << nombre << ":\n\n";
    std::cout << " Calorias: " << calorias << "  \n";
    std::cout << " Proteinas: " << proteinas << "  \n";
    std::cout << " Grasas: " << grasas << "  \n";
    std::cout << " Carbohidratos: " << carbohidratos << "\n";
    std::cout << " Vitaminas: " << vitaminas << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "vitaminas"
}
