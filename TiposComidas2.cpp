#include "TiposComidas2.h"
#include <iostream>

Comida::Comida(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos) //constructor
    : nombre(nombre), calorias(calorias), proteinas(proteinas), grasas(grasas), carbohidratos(carbohidratos) {}

void Comida::mostrarInformacion() { //inicializacion y definicion de un metodo que pueden ocupar todas la subclases de comida debido a herencia
    std::cout << "\nInformacion nutricional de " << nombre << ":\n\n";
    std::cout << " Calorias: " << calorias << "  \n";
    std::cout << " Proteinas: " << proteinas << "  \n";
    std::cout << " Grasas: " << grasas << "  \n";
    std::cout << " Carbohidratos: " << carbohidratos << "\n";
}

double Comida::getCalorias() { return calorias; } //definicion de getters
double Comida::getProteinas() { return proteinas; }
double Comida::getGrasas() { return grasas; }
double Comida::getCarbohidratos() { return carbohidratos; }

VegetalYFruta::VegetalYFruta(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), tipo(tipo) {} //constructor de vegetal y frutas

void VegetalYFruta::mostrarInformacion() { //sobrescritura del metodo de comida
    Comida::mostrarInformacion();
    std::cout << " Tipo: " << tipo << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "tipo"
}

Cereales::Cereales(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, double fibra)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), fibra(fibra) {} //constructor de cereal

void Cereales::mostrarInformacion() { //sobrescritura del metodo de comida
    Comida::mostrarInformacion();
    std::cout << " Fibra: " << fibra << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "fibra"
}

LegumbreYOrigenAnimal::LegumbreYOrigenAnimal(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), tipo(tipo) {} //constructor de legumbre y origen animal

void LegumbreYOrigenAnimal::mostrarInformacion() { //sobrescritura
    Comida::mostrarInformacion();
    std::cout << " Tipo: " << tipo << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "tipo"
}
