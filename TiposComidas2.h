#ifndef TIPOSCOMIDAS2_H
#define TIPOSCOMIDAS2_H

#include <string>
#include <iostream>

class Comida {

protected:
    std::string nombre; //definicion de atributos
    double calorias;
    double proteinas;
    double grasas;
    double carbohidratos;

public:
    Comida(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos);
    virtual ~Comida() = default; //destructor

    virtual void mostrarInformacion(); //es virtual ya que asi cada subclase puede implementar de manera diferente este metodo 

    double getCalorias(); //getters
    double getProteinas();
    double getGrasas();
    double getCarbohidratos();
};

class VegetalYFruta : public Comida {

private:
    std::string tipo;

public:
    VegetalYFruta(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo); //inicializamos el objeto con un constrcutor

    void mostrarInformacion(); //definicion
};

class Cereales : public Comida {

private:
    double fibra;

public:
    Cereales(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, double fibra); //inicializamos el objeto con un constructor

    void mostrarInformacion(); //definicion
};

class LegumbreYOrigenAnimal : public Comida {

private:
    std::string tipo;

public:
    LegumbreYOrigenAnimal(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo); //inicializamos el objeto con un constructor

    void mostrarInformacion(); //definicionm
};

#endif // TIPOSCOMIDAS2_H
