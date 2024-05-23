#include "Usuario2.h"
#include "TiposComidas2.h"
#include <iostream>
#include <limits>
//incluimos los otros archivos 

void Menu() { //funcion que despliega el menu

    std::cout << "TC1030 A01711730\n\n";
    std::cout << "1. Agregar Comida \n";
    std::cout << "2. Mostrar Resumen Diario \n";
    std::cout << "3. Salir\n";
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
            std::cout << "Seleccione el tipo de comida:\n";
            std::cout << "1. Vegetal y Fruta\n";
            std::cout << "2. Cereales\n";
            std::cout << "3. Legumbre y Origen Animal\n";
            std::cout << "Seleccione una opción: ";
            int tipo;
            std::cin >> tipo;

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

            Comida* nuevaComida = nullptr; //indica que nueva comida es un puntero a un objeto de comida
            if (tipo == 1) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Vegetal/Fruta): "; //si es vegetal y fruta agrega el tipo
                std::cin >> tipo;
                nuevaComida = new VegetalYFruta(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            } else if (tipo == 2) {
                double fibra;
                std::cout << "Ingrese la cantidad de fibra: "; //si es cereal agrega la cantidad de fibra
                std::cin >> fibra;
                nuevaComida = new Cereales(nombre, calorias, proteinas, grasas, carbohidratos, fibra);
            } else if (tipo == 3) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Legumbre/Origen Animal): ";//si es legumbre o de origen animal agrega el tipo
                std::cin >> tipo;
                nuevaComida = new LegumbreYOrigenAnimal(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            }

            if (nuevaComida) {
                std::string fecha;
                std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
                std::cin >> fecha;
                ComidaDiaria comidaDiaria(fecha);
                comidaDiaria.agregarComida(nuevaComida);
                usuario.agregarComida(comidaDiaria);
                std::cout << "Comida agregada exitosamente.\n";
            } else {
                std::cout << "Opción no válida.\n";
            }
            break;
        }
        case 2:
            usuario.mostrarResumenDiario();
            break;
        case 3:
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
