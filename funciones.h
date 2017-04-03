#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
/**
    @brief funcion que  hece el facorial  recursivamente de la variable pasada por parametro
    @param numero1  variable a la que se le sacara el factorial
    @returns  retorna el valor calculado  del factorial
    */
int factorial(int numero1);


/**
    @brief funcion que  suma dos variables
    @param numero1  primer numero que va a sumar
    @param numero2 segundo numero que va a sumar
    @returns  retorna el resultado de la duma entre numero1 y numero2
    */
int suma(int numero1,int numero2);

/**
    @brief funcion que resta dos variables
    @param numero1  primer numero que va a restar
    @param numero2 segundo numero que va a restar
    @returns devuelve el resultado de la resta entre numero1 y numero2
    */
int resta(int numero1,int numero2);
float division(int numero1,int numero2);
int multiplicacion(int numero1,int numero2);


#endif // FUNCIONES_H_INCLUDED
