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
    int id;
    int estado;
}EMovie;


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[],int tamanio);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */


 void getValidString(char requestMessage[],char errorMessage[], char input[],int tamanio);

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
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

/** \brief
 *  Abre un fichero cuyo nombre es la cadena apuntada por nombre, y adjudica un stream a ello
 * \param archivo FILE* stream  que abrira
 * \param nombrearchivo[] char   nombrede archivo que buscara o creara
 * \param modo[] char    modo en el cual abrira el erchivo
 * \return int
 *
 */
int abrirarchivo(FILE *archivo,char nombrearchivo[],char modo[]);


int main()
{
    char seguir='s';
    int opcion=0;
    FILE *archivo;
    char buffer[255];

    archivo=fopen("archivo.dat","ab");




    if(archivo!=NULL)
    {

        do
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Generar pagina web\n");
            printf("4- Salir\n");

            opcion=getValidInt("ingrese la operacion \n","el valor de la operacion debe ser un numero\n",1,4,3);

            switch(opcion)
            {
                case 1:
                agregarPelicula(movie);

                    break;
                case 2:
                    break;
                case 3:
                   break;
                case 4:
                    seguir = 'n';
                    break;
            }
        }while(seguir=='s');
        fclose(archivo);

    }
    else
    {
        perror("error al abrir el archivo");

    }

 return 0;
}



int esNumerico(char *str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

void limpiarfgets(char cadena[])
{
if(cadena[strlen(cadena)-1]=='\n')
{
cadena[strlen(cadena)-1]='\0';
}
}


void getString(char mensaje[],char input[],int tamanio)
{
    printf("%s",mensaje);
    fgets(input,tamanio,stdin);
     limpiarfgets(input);
}


int getStringNumeros(char mensaje[],char input[],int tamanio)
{
    char aux[256];
    getString(mensaje,aux,tamanio);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int tamanio)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr,tamanio))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}
int abrirarchivo(FILE *archivo,char nombrearchivo[],char modo[])
{
   int retorno=1;
    archivo=fopen(nombrearchivo,modo);
    if(archivo==NULL)
    {
        perror("no se pudo abrir el archivo");
        retorno=0;
    }

    return retorno;
}
void getValidString(char requestMessage[],char errorMessage[], char input[],int tamaniimput)
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input,tamaniimput))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        break;
    }
}
    int getStringLetras(char mensaje[],char input[],int tamanio)
    {
        char aux[tamanio];
        getString(mensaje,aux,tamanio);
        if(esSoloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        return 0;
    }

int agregarPelicula(EMovie movie)
{
char nombre[TAMNOMBRES];
char genero[TAMNOMBRES];
char describcion[TAMDESCRIB];
char url[TAMDESCRIB];
int duracion,puntaje;

getString("escriba el nombre de la pelicula\n",nombre,TAMNOMBRES);
getString("ingrese el genero\n",genero,TAMNOMBRES);
getString("ingrese describcione\n",describcion,TAMDESCRIB);
getstring("ingrese  la url",url,TAMDESCRIB);
getValidInt("ingrese  la duracion en minutos\n");
getValidInt("ingrese le puntaje\n");








}
