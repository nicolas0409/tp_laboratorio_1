#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
#define TAMDNI 14
#define TAMEDAD 5
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int dni);
/**
 * Agrega una persona a la lista de personas
 * @param lista el array se pasa como parametro.
 * @param Tamaño dell array.
 * @return 0 si el dni ingresado ya existe y   1 si se pudo agregar correctamente la persona
 */
int agregapersona(EPersona lista[],char nombre[],int dni,int edad,int indice);
/**
 * Borra  una persona de la lista de personas
 * @param lista el array se pasa como parametro.
 * @param dni a buscar en la lista
 * @return retorna 1 si elimino la persona correctamente 0 si no la pudo eliminar
 */

 int borrar_persona (EPersona lista[],int dni);
 /**
 * grafica una  estadistica de las edades ingresadas
 * @param lista el array se pasa como parametro.
* @return VOID
 */

 void graficar(EPersona lista[]);

 /**
 * ordena la lista alfabeticamente pasada por parametro por su campo nombre
 * @param lista el array se pasa como parametro.
 * @param  tamaño de el array
 * @return  void
 */

 void ordenar(EPersona lista[],int tamanio);
  /**
 *  valida una cadena de caracteres,si todos los valores ingresados son numericos
 * @param  cadena de caracteres a analizar
 * @param  tamaño de el array
 * @return  retorna -1 si hay algun caracter no numerico o retorna el caracter ingresado en forma de char* a  entero
 */





#endif // FUNCIONES_H_INCLUDED
