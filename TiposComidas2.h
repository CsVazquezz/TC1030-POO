#ifndef TIPOSCOMIDAS2_H
#define TIPOSCOMIDAS2_H

#include <string>
#include <iostream>


/*Esta clase define objeto de Tipo Comida y de esta clase heredan
VegetalyFruta, Cereales y LegumbreyOrigenAnimal */
class Comida {

protected:
    std::string nombre; //definicion de atributos
    double calorias;
    double proteinas;
    double grasas;
    double carbohidratos;

public:
    Comida(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos);
    virtual ~Comida() = default; //destructor para liberar memoria

    virtual void mostrarInformacion() = 0; //declaracion de la variable que muestra la informacion de la comida 

    //Declaracion de los getters
    double getCalorias(); 
    double getProteinas();
    double getGrasas();
    double getCarbohidratos();
};

//Clase que hereda de Comida
class VegetalYFruta : public Comida {

    private:
        
        //declaracion de atributos de VegetalyFruta
        std::string tipo;
        
        //metodos del objeto
    public:
        VegetalYFruta(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, std::string tipo); //inicializamos el objeto con un constrcutor

        void mostrarInformacion() override; //definicion
    };

class Cereales : public Comida {

    private:

        //declaracion de atributos de Cerales
        double fibra;

        //metodos del objeto
    public:
        Cereales(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, double fibra); //inicializamos el objeto con un constructor

        void mostrarInformacion() override; //definicion
    };

class LegumbreYOrigenAnimal : public Comida {

    private:

        //declaracion de atributos de LegumbreYOrigenAnimal
        int vitaminas;

        //metodos del objeto
    public:
        LegumbreYOrigenAnimal(std::string nombre, double calorias, double proteinas, double grasas, double carbohidratos, int vitaminas); //inicializamos el objeto con un constructor

        void mostrarInformacion() override; //definicion
    };

#endif // TIPOSCOMIDAS2_H
