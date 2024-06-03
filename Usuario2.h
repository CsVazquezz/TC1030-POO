#ifndef USUARIO2_H
#define USUARIO2_H

#include "TiposComidas2.h"
#include <vector>
#include <string>
#include <map>
#include <memory>

class ComidaDiaria;

class Usuario {
    private:

    std::string nombre; //atributos
    int edad;
    double peso;
    double altura;
    std::vector<std::unique_ptr<ComidaDiaria>> diario; //vector donde se almacenara la comidaDiaria

    public:
    Usuario(std::string nombre, int edad, double peso, double altura);  //definicion de los metodos de clase Usuario
    void agregarComida(std::unique_ptr<ComidaDiaria> comidaDiaria);
    void mostrarResumenDiario();
    void MostrarCaloriasMacros();
    std::string getNombre(); //getter
};

class ComidaDiaria {
    private:
    std::string fecha; //atributos
    std::vector<std::unique_ptr<Comida>> listaComidas;  //vector que almacena objetos de la clase Comida por lo que igual podemos almacenar de sus subclases

    public:
    ComidaDiaria(std::string fecha);
    void agregarComida(std::unique_ptr<Comida> comida); //aqui es un puntero a comida y lo añade al vector
    double calcularCaloriasTotales();
    std::map<std::string, double> calcularMacrosTotales(); //map para poder devolver todos los macronutrientes a la funcion
    void mostrarInformacion();
};

#endif // USUARIO2_H
