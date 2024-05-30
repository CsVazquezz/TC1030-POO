# TC1030-POO
Proyecto TC1030 de Programación Orientada a Objetos.

El objetivo de este programa es poder contar las calorías y macronutrientes que son consumidos diariamente.
El programa funciona permitiendo a los usuarios registrar su consumo diario de alimentos para obtener un resumen de este. Primero los usuarios pueden crear una instancia de la clase 'Usuario' al proporcionar su nombre, edad, peso y altura. A continuación, pueden agregar las comidas consumidas utilizando los métodos de la clase 'Diario'. Cada una de las comidas se registra en una instancia de la clase 'ComidaDiaria'. Las diferentes categorías de alimentos son vegetales,frutas,cereales,legumbres y alimentos de origen animal cada uno de estos representados en sublcases de la clase 'Comida'. Los métodos de cada clase permiten calcular las calorías totales y sus macronutrientes. Finalmente el programa puede proporcionar un resúmen mensual de los alimentos con detalles nutricionales para ayudar a los usuarios mantener su dieta.

# Consideraciones

El programa solo corre en la consola y esta hecho con c++11 por lo que es importante compilarlo de esta manera:

Windows: g++ -std=c++11 TC1030.cpp TiposComidas2.cpp Usuario2.cpp -o program

MacOS: g++ -std=c++11 TC1030.cpp TiposComidas2.cpp Usuario2.cpp -o program

De esta manera se generara un programa ejecutable.
