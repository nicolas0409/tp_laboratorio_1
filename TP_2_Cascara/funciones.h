#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 10
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
 * @return
 */

 int borrar_persona (EPersona lista[],int dni);

 void graficar(EPersona lista[]);

 void ordenar(EPersona lista[],int tamanio);

 int validar_numero (char numero[],int tamanio);



#endif // FUNCIONES_H_INCLUDED
