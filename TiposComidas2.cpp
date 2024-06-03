#include "TiposComidas2.h"

Comida::Comida(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos) //constructor
    : nombre(nombre), calorias(calorias), proteinas(proteinas), grasas(grasas), carbohidratos(carbohidratos) {}

void Comida::mostrarInformacion() { //inicializacion y definicion de un metodo que pueden ocupar todas la subclases de comida debido a herencia
    std::cout << "Informacion nutricional:\n";
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
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), tipo(tipo) {} //constructor

void VegetalYFruta::mostrarInformacion() { //sobrescritura
    Comida::mostrarInformacion();
    std::cout << "Tipo de fruta o vegetal: " << tipo << "  \n"; //debido a herencia muestra la informacion completa y se le agrega "tipo"
}

Cereales::Cereales(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, double fibra)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), fibra(fibra) {} //constructor

void Cereales::mostrarInformacion() { //sobrescritura
    Comida::mostrarInformacion();
    std::cout << " Fibra: " << fibra << "  \n"; 
}

LegumbreYOrigenAnimal::LegumbreYOrigenAnimal(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo)
    : Comida(nombre, calorias, proteinas, grasas, carbohidratos), tipo(tipo) {} //constructor

void LegumbreYOrigenAnimal::mostrarInformacion() { //sobrescritura
    Comida::mostrarInformacion();
    std::cout << "Tipo de legumbre o de origen animal: " << tipo << "  \n";
}


