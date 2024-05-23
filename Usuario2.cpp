#include "Usuario2.h"
#include <iostream>

Usuario::Usuario(std::string nombre, int edad, double peso, double altura)
    : nombre(nombre), edad(edad), peso(peso), altura(altura) {} //constructor

void Usuario::agregarComida( ComidaDiaria& comidaDiaria) {
    diario.push_back(comidaDiaria);  //agrega comidaDiaria a diario con metodo push_back
}

void Usuario::mostrarResumenDiario() { //muestra la informacion de la comida diaria del usuario
    std::cout << "Resumen diario de: " << nombre << "\n";
    for (auto& comidaDiaria : diario) {
        comidaDiaria.mostrarInformacion(); 
    }
}

std::string Usuario::getNombre() { return nombre; } //getter

ComidaDiaria::ComidaDiaria(std::string fecha) : fecha(fecha) {} //constructor

void ComidaDiaria::agregarComida(Comida* comida) { //agrega comida a lista de comidas con metodo push_back
    listaComidas.push_back(comida);
}

double ComidaDiaria::calcularCaloriasTotales() { //este metodo recorre el vector ListaComidas con el ciclo for y suma la calorias de los objetos
    double totalCalorias = 0;
    for ( auto& comida : listaComidas) {
        totalCalorias += comida-> getCalorias(); //se accede a comida para ocupar el getter de calorias
    }
    return totalCalorias; //regresa el total de calorias
}

std::map<std::string, double> ComidaDiaria::calcularMacrosTotales() {  //uso de std::map para mejor organizacion y claridad
    std::map<std::string, double> macros;
    double totalProteinas = 0; //inicializamos las variables que almacenan los macronutrientes
    double totalGrasas = 0;
    double totalCarbohidratos = 0;
    for ( auto& comida : listaComidas) { //el opereador -> se ocupa para acceder a comida y ocupar los getters de esta clase
        totalProteinas += comida->getProteinas();
        totalGrasas += comida->getGrasas();
        totalCarbohidratos += comida->getCarbohidratos();
    }
    macros["Proteinas"] = totalProteinas;
    macros["Grasas"] = totalGrasas;
    macros["Carbohidratos"] = totalCarbohidratos;
    return macros; //regresamos el vector con los valores de proteinas, grasas y carbohidratos
}

void ComidaDiaria::mostrarInformacion() {
    std::cout << "Fecha: " << fecha << "\n";
    for ( auto& comida : listaComidas) {
        comida->mostrarInformacion(); //se accede a comida y ocupa el metodo de mostrarInformacion
    }
}

ComidaDiaria::~ComidaDiaria() {
    for (auto& comida : listaComidas) {
        delete comida; //este es para liberar memoria
    }
}
