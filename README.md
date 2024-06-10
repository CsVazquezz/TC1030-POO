# TC1030-POO
Proyecto TC1030 de Programación Orientada a Objetos.

El objetivo de este programa es poder contar las calorías y macronutrientes que son consumidos diariamente.
El programa funciona permitiendo a los usuarios registrar su consumo diario de alimentos para obtener un resumen de este. Primero los usuarios pueden crear una instancia de la clase 'Usuario' al proporcionar su nombre, edad, peso y altura. A continuación, pueden agregar las comidas consumidas utilizando los métodos de la clase 'Diario'. Cada una de las comidas se registra en una instancia de la clase 'ComidaDiaria'. Las diferentes categorías de alimentos son vegetales,frutas,cereales,legumbres y alimentos de origen animal cada uno de estos representados en sublcases de la clase 'Comida'. Los métodos de cada clase permiten calcular las calorías totales y sus macronutrientes. Finalmente el programa puede proporcionar un resúmen mensual de los alimentos con detalles nutricionales para ayudar a los usuarios mantener su dieta.

# Consideraciones

El programa solo corre en la consola y esta ocupa opciones de c++14 por lo que es importante compilarlo de esta manera:

Windows: g++ -std=c++14 TC1030.cpp TiposComidas2.cpp Usuario2.cpp -o program

MacOS: g++ -std=c++14 TC1030.cpp TiposComidas2.cpp Usuario2.cpp -o program

De esta manera se generara un programa ejecutable.

# Casos en el que dejaria de funcionar

1. Memoria insuficiente: si el sistema se queda sin memoria mientras que se ejecuta el programa debido a la creación de demasiados objetos dinámicos el programa puede fallar.

2. Acceso invalido a memoria: Si hay errores con la gestión de la memoria dinámica, como intentar acceder a punteros nulos o liberar memoria que ya se libero podria causar errores de segmentación.

3. Conflictos de versión: Si el proyecto no se ejecuta en una version de c++11 o posteriores el programa puede fallar al generar el ejecutable.

4. Error en entrada de datos: Si el usuario ingresa datos incorrectos o en un formato incorrecto durante el programa, este puede producir resultados inesperados o errores.
