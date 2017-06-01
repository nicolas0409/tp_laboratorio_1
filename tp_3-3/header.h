#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAMNOMBRES 20
#define TAMDESCRIB  100

typedef struct{
    char titulo[TAMNOMBRES];
    char genero[TAMNOMBRES];
    int duracion;
    char descripcion[TAMDESCRIB];
    int puntaje;
    char linkImagen[TAMDESCRIB];
    int estado;
}EMovie;


/** \brief  verifica si un valor es numerico
 *
 * \param str char* string a analizar
 * \return int retorna 1 si si lo es 0 si no
 *
 */
int esNumerico(char *str);


/** \brief solicita un texto al usuario
 *
 * \param cadena[] char array donde guarda el texto
 * \return void
 *
 */
void limpiarfgets(char cadena[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[],int tamanio);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[],int tamanio);


/** \brief funcion que valida si la cadena ingresada es un numero y  esta dentro del rango  especificado por los parametros
 *
 * \param requestMessage[] char mensaje para  informar al  usuario que debe ingresar
 * \param errorMessage[] char  mensaje que muesta si ocurre un erro
 * \param lowLimit int      limites maximos  y minimos del valor entero
 * \param hiLimit int
 * \param tamanioimput int      tamaño maximo del string donde se cargara el numero
 * \return int         reotrna el entero  escrito por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int tamanioimput);




/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* pmovie,int* posicionagregar);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* pmovie, int* posicionagregar);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* pmovie, char nombre[]);

/** \brief
 *  Abre un fichero cuyo nombre es la cadena apuntada por nombre, y adjudica un stream a ello
 * \param archivo FILE* stream  que abrira
 * \param nombrearchivo[] char   nombrede archivo que buscara o creara
 * \param modo[] char    modo en el cual abrira el erchivo
 * \return int
 *
 */
int cargarEstructura(FILE* archivo,EMovie* pmovie,int* posicionAgregar );




FILE*  abrirarchivo(FILE *archivo,char nombrearchivo[],char modo[]);

int cargararchivo(EMovie* Pmovie,int* cantidadPeliculas );

/** \brief
 *  compruba  la existencia de una pelicula desde una estructura emmovie a un archivo binario
 * \param nombrearchivo[] char   nombrede archivo que buscara o creara
 * \param EMovie* puntero a  una lista de estructuras emovie
 * \return int retorna 1 si la pelicula existe 0 si no
 *
 */

int comprueba_pelicula(char nombrearch[],char pelicula_buscar[],EMovie* vpmovie,int cantpelis);


int modificarpelicula(EMovie* pmovie);
#endif // FUNCIONES_H_INCLUDED
