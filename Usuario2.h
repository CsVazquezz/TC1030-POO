#ifndef USUARIO2_H
#define USUARIO2_H

#include "TiposComidas2.h"
#include <vector>
#include <string>
#include <map>

class ComidaDiaria;

class Usuario {
    private:
    std::string nombre; //atributos
    int edad;
    double peso;
    double altura;
    std::vector<ComidaDiaria*> diario; //vector donde se almacenara la comidaDiaria

    public: //definicion de los metodos de clase Usuario
    Usuario(std::string nombre, int edad, double peso, double altura); //constructor con parametros
    ~Usuario(); // Destructor para liberar la memoria
    void agregarComida(ComidaDiaria* comidaDiaria);
    void mostrarResumenDiario();
    void MostrarCaloriasMacros();
    std::string getNombre(); //getters
    void mostrarInformacion();
    void mostrarInformacion(bool mostrarEdad, bool mostrarPeso, bool MostrarAltura);
};

class ComidaDiaria {
    private:
    std::string fecha; //atributos
    std::vector<Comida*> listaComidas;  //vector que almacena objetos de la clase Comida por lo que igual podemos almacenar de sus subclases

    public:
    ComidaDiaria(std::string fecha);
    ~ComidaDiaria(); // Destructor para liberar la memoria
    void agregarComida(Comida* comida); //aqui es un puntero a comida y lo añade al vector
    double calcularCaloriasTotales();
    std::map<std::string, double> calcularMacrosTotales(); //map para poder devolver todos los macronutrientes a la funcion
    void mostrarInformacion();
};

#endif // USUARIO2_H
