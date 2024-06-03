#include "Usuario2.h"
#include"TiposComidas2.h"
#include <iostream>
#include <memory>
//incluimos los otros archivos 

void Menu() { //funcion que despliega el menu

    std::cout << "\nTC1030 A01711730 VF\n\n";
    std::cout << "1. Agregar Comida \n";
    std::cout << "2. Mostrar Lista Comidas \n";
    std::cout << "3. Mostrar Calorias y Macros totales\n";
    std::cout << "4. Salir\n\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    Usuario usuario("Juan", 30, 75.5, 175.0); //creacion de un objeto de Usuario

    bool continuar = true;
    while (continuar) {
        Menu();
        int opcion;
        std::cin >> opcion; //despliega el menu y recibe opcion

        switch (opcion) {
        case 1: { //agregar comida
            std::cout << "\nSeleccione el tipo de comida:\n\n";
            std::cout << "1. Vegetal y Fruta\n";
            std::cout << "2. Cereal\n";
            std::cout << "3. Legumbre y OrigenA \n\n";
            std::cout << "Seleccione una opción: ";
            int tipo1;
            std::cin >> tipo1;

            std::string nombre;
            double calorias, proteinas, grasas, carbohidratos;
            std::cout << "Ingrese el nombre de la comida: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese las calorias: ";
            std::cin >> calorias;
            std::cout << "Ingrese las proteinas: ";
            std::cin >> proteinas;
            std::cout << "Ingrese las grasas: ";
            std::cin >> grasas;
            std::cout << "Ingrese los carbohidratos: ";
            std::cin >> carbohidratos;

            std::unique_ptr<Comida> nuevaComida = nullptr; //indica que nueva comida es un puntero a un objeto de comida
            if (tipo1 == 1) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Vegetal/Fruta): "; //si es vegetal y fruta agrega el tipo
                std::cin >> tipo;
                nuevaComida = std::make_unique <VegetalYFruta>(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            } else if (tipo1 == 2) {
                double fibra;
                std::cout << "Ingrese la cantidad de fibra: "; //si es cereal agrega la cantidad de fibra
                std::cin >> fibra;
                nuevaComida = std::make_unique <Cereales>(nombre, calorias, proteinas, grasas, carbohidratos, fibra);
            } else if (tipo1 == 3) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Legumbre/Origen Animal): ";//si es legumbre o de origen animal agrega el tipo
                std::cin >> tipo;
                nuevaComida = std::make_unique <LegumbreYOrigenAnimal>(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            }

            if ( nuevaComida) {
                std::string fecha;
                std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
                std::cin >> fecha;
                 auto comidaDiaria = std::make_unique<ComidaDiaria>(fecha);
                comidaDiaria->agregarComida(std::move(nuevaComida));
                usuario.agregarComida(std::move(comidaDiaria));
                std::cout << "Comida agregada exitosamente.\n";
            } else {
                std::cout << "Opción no válida.\n";
            }
            break;
        }
        case 2:
            std::cout << "\n";
            usuario.mostrarResumenDiario(); //muestra la lista de comidas agregadas
            break;
        case 3:
            std::cout << "\n";
            usuario.MostrarCaloriasMacros(); //muestra la suma de las calorias y macros de las comidas
            break;
        case 4:
            continuar = false;
            break; 
        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }

        std::cout << "\n";
    }

    return 0;
}
