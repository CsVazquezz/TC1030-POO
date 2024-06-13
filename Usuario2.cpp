#include "Usuario2.h"
#include <iostream>

Usuario::Usuario(std::string nombre, int edad, double peso, double altura)
    : nombre(nombre), edad(edad), peso(peso), altura(altura) {} //constructor con parametros de Usuario

Usuario::~Usuario() { //destructor
    for (auto comidaDiaria : diario) {
        delete comidaDiaria;
    }
}

void Usuario::agregarComida(ComidaDiaria* comidaDiaria) {
    diario.push_back(comidaDiaria); //agrega comidaDiaria a diario con metodo push_back
}

void Usuario::mostrarResumenDiario() { //esta funcion muestra la informacion de la comida diaria del usuario ya que itera en diario para mostrar cada una de las comidas diarias
    std::cout << "Resumen diario de: " << nombre << "\n"; 
    for (auto comidaDiaria : diario) {
        comidaDiaria->mostrarInformacion(); //muestra la informacion de cada ComidaDiaria
    }
}

void Usuario::MostrarCaloriasMacros() { //funcion que imprime en pantalla las calorias y macronutrientes totales al ocupar los metodos de comida Diaria
    double totalCalorias = 0; //inicializacion de las variables en 0
    double totalProteinas = 0;
    double totalGrasas = 0;
    double totalCarbohidratos = 0;

    for (auto comidaDiaria : diario) { //itera en diario para calcular de ComidasDiarias
        totalCalorias += comidaDiaria->calcularCaloriasTotales(); //llama metodo de comidadiaria que calcula calorias 
        auto macros = comidaDiaria->calcularMacrosTotales(); //llama metodo de comida diaria que calcula macronutrientes totales
        totalProteinas += macros["Proteinas"]; 
        totalGrasas += macros["Grasas"];
        totalCarbohidratos += macros["Carbohidratos"];
    }   

    //imprime en pantalla el total de las calorias y macronutrientes
    std::cout << "Calorías Totales: " << totalCalorias << "\n";  
    std::cout << "Proteínas Totales: " << totalProteinas << "g\n";
    std::cout << "Grasas Totales: " << totalGrasas << "g\n";
    std::cout << "Carbohidratos Totales: " << totalCarbohidratos << "g\n";
}

std::string Usuario::getNombre() { return nombre; } //definicion de getter

void Usuario::mostrarInformacion() { //Definicion de metodo que imprime solo la informacion del usuario
    std::cout << "\n\nInformacion del usuario:\n";
    std::cout << "Nombre: " << getNombre() << "\n";
}


void Usuario::mostrarInformacion(bool mostrarEdad, bool mostrarPeso, bool mostrarAltura) { // Sobrecarga del metodoinformacion que segun la informacion que desea la imprime
   std::cout << "\n\nInformacion del usuario:\n";
    std::cout << "Nombre: " << nombre << "\n"; 
    if(mostrarEdad == true) {
    std::cout << "Edad: " << edad << "años\n"; } //muestra edad si se desea
    if (mostrarPeso == true) {
    std::cout << "Peso: " << peso << "kg\n"; }//muestra peso si se desea
    if (mostrarAltura == true) {
    std::cout << "Altura: " << altura << "cm\n"; }//muestra altura si se desea
}


ComidaDiaria::ComidaDiaria(std::string fecha) : fecha(fecha) {} //constructor con parametros

ComidaDiaria::~ComidaDiaria() { //destructor
    for (auto comida : listaComidas) {
        delete comida;
    }
}

void ComidaDiaria::agregarComida(Comida* comida) { //metodo que agrega comida a lista de comidas con metodo push_back
    listaComidas.push_back(comida);
}

double ComidaDiaria::calcularCaloriasTotales() { // metodo itera en ListaComidas con el ciclo for y suma la calorias de los objetos
    double totalCalorias = 0;
    for (auto comida : listaComidas) {
        totalCalorias += comida->getCalorias(); //se accede a comida para ocupar el getter de calorias
    }
    return totalCalorias; //regresa el total de calorias
}

std::map<std::string, double> ComidaDiaria::calcularMacrosTotales() {  //metodo que almacena los valores de las proteinas, grasas y carbohidratos en macros (map)
    std::map<std::string, double> macros; //uso de std::map para mejor organizacion y claridad
    double totalProteinas = 0; //inicializamos las variables que almacenan los macronutrientes
    double totalGrasas = 0;
    double totalCarbohidratos = 0;
    for (auto comida : listaComidas) { //el opereador -> se ocupa para acceder a comida y ocupar los getters de esta clase
        totalProteinas += comida->getProteinas();
        totalGrasas += comida->getGrasas();
        totalCarbohidratos += comida->getCarbohidratos();
    }
    macros["Proteinas"] = totalProteinas;
    macros["Grasas"] = totalGrasas;
    macros["Carbohidratos"] = totalCarbohidratos;
    return macros; //regresamos el vector con los valores de proteinas, grasas y carbohidratos
}

void ComidaDiaria::mostrarInformacion() { //metodo que recorre la lista de comidas y muestra su informacion
    std::cout << "Fecha: " << fecha << "\n";
    for (auto comida : listaComidas) {
        comida->mostrarInformacion(); //se accede a comida y ocupa el metodo de mostrarInformacion
    }
}
