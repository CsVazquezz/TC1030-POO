#include "Usuario2.h"
#include "TiposComidas2.h"
#include <iostream>

void Menu() { //funcion que despliega el menu

    std::cout << "\nTC1030 A01711730 VF\n\n";
    std::cout << "1. Agregar Comida \n";
    std::cout << "2. Mostrar Lista Comidas \n";
    std::cout << "3. Mostrar Calorias y Macros totales\n";
    std::cout << "4. Mostrar informacion del usuario\n";
    std::cout << "5. Salir\n\n";
    std::cout << "Seleccione una opción: ";
}

void MenuMostrarInfoUsuario() {

    std::cout << "1. Mostrar solo nombre \n";
    std::cout << "2. Mostrar mas informacion \n";

}

int main() {
    Usuario usuario("DongJu Mun", 30, 120.0, 150.0); //creacion de un objeto de Usuario

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
            getline(std::cin, nombre);
            std::cout << "Ingrese las calorias: ";
            std::cin >> calorias;
            std::cout << "Ingrese las proteinas: ";
            std::cin >> proteinas;
            std::cout << "Ingrese las grasas: ";
            std::cin >> grasas;
            std::cout << "Ingrese los carbohidratos: ";
            std::cin >> carbohidratos;

            Comida* nuevaComida = nullptr; //indica que nueva comida es un puntero a un objeto de comida
            if (tipo1 == 1) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Vegetal/Fruta): "; //si es vegetal y fruta agrega el tipo
                std::cin >> tipo;
                nuevaComida = new VegetalYFruta(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            } else if (tipo1 == 2) {
                double fibra;
                std::cout << "Ingrese la cantidad de fibra: "; //si es cereal agrega la cantidad de fibra
                std::cin >> fibra;
                nuevaComida = new Cereales(nombre, calorias, proteinas, grasas, carbohidratos, fibra);
            } else if (tipo1 == 3) {
                std::string tipo;
                std::cout << "Ingrese el tipo (Legumbre/OrigenA): ";//si es legumbre o de origen animal agrega el tipo
                std::cin.ignore();
                getline(std::cin, tipo);
                nuevaComida = new LegumbreYOrigenAnimal(nombre, calorias, proteinas, grasas, carbohidratos, tipo);
            }

            if (nuevaComida) {
                std::string fecha;
                std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
                std::cin >> fecha;
                ComidaDiaria* comidaDiaria = new ComidaDiaria(fecha);
                comidaDiaria->agregarComida(nuevaComida);
                usuario.agregarComida(comidaDiaria);
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
            std::cout << "Consumo diario de: " << usuario.getNombre() << "\n";
            std::cout << "\n";
            usuario.MostrarCaloriasMacros(); //muestra la suma de las calorias y macros de las comidas
            break;
        case 4:
            int inf;
            MenuMostrarInfoUsuario();
            std::cout << "Seleccione una opcion: ";
            std::cin >> inf;
            if (inf == 1) {
                usuario.mostrarInformacion();
            } 
            else {

                std::string mostrarEdadInput, mostrarPesoInput, mostrarAlturaInput;
                bool mostrarEdad, mostrarPeso, mostrarAltura;

                std::cout << "Mostrar edad? (true/false): ";
                std::cin >> mostrarEdadInput;
                mostrarEdad = (mostrarEdadInput == "true");

                std::cout << "Mostrar peso? (true/false): ";
                std::cin >> mostrarPesoInput;
                mostrarPeso = (mostrarPesoInput == "true");

                std::cout << "Mostrar Altura? (true/false): ";
                std::cin >> mostrarAlturaInput;
                mostrarAltura = (mostrarAlturaInput == "true");

                usuario.mostrarInformacion(mostrarEdad, mostrarPeso, mostrarAltura);
            }

         
            break;
        case 5:
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
