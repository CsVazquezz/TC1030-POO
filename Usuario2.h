#ifndef USUARIO2_H
#define USUARIO2_H

#include "TiposComidas2.h"
#include <vector>
#include <string>
#include <map>


class ComidaDiaria; //Declaracion antes ya que se ocupa en Usuario


/* Clase en la cual se almacena la informacion del usuario como nombre, edad, peso, altura
y el cual muestra el resumen del usuario respecto a su comida*/
class Usuario {

    //atributos de Clase Usuario
    private:

    std::string nombre; 
    int edad;
    double peso;
    double altura;

    std::vector<ComidaDiaria*> diario; //vector donde se almacenara la comidaDiaria


    //definicion de constructor con paramateros y de los metodos de clase Usuario
    public:

    Usuario(std::string nombre, int edad, double peso, double altura); //constructor con parametros

    ~Usuario(); // Destructor para liberar la memoria

    void agregarComida(ComidaDiaria* comidaDiaria); 

    void mostrarResumenDiario(); 
    void MostrarCaloriasMacros();

    std::string getNombre(); //getter

    void mostrarInformacion();
    void mostrarInformacion(bool mostrarEdad, bool mostrarPeso, bool MostrarAltura);
};


class ComidaDiaria {

    //atributos de clase ComidaDiaria
    private:

    std::string fecha; 
    std::vector<Comida*> listaComidas;  //vector que almacena objetos de la clase Comida por lo que igual podemos almacenar de sus subclases
    
    //Definicion de constructor con parametros y metodos de clase Comida Diaria
    public:

    ComidaDiaria(std::string fecha); //constructor 

    ~ComidaDiaria(); // Destructor para liberar la memoria
    void agregarComida(Comida* comida); //aqui es un puntero a comida y lo añade al vector
    
    double calcularCaloriasTotales();
    std::map<std::string, double> calcularMacrosTotales(); //map para poder devolver todos los macronutrientes a la funcion
    void mostrarInformacion();
};

#endif // USUARIO2_H
