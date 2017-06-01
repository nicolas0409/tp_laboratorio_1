#include "header.h"



int main()
{

    char seguir='s';
    int opcion=0;
    EMovie *pMovie;
    int posiciongregar=0;//maximo indice del tamaño  de la lista de peliculas
    char pathArchPelicula[]={"peliculas.dat"};



    do
    {       printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- modificar\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\n");
            opcion=getValidInt("ingrese la operacion \n","el valor de la operacion debe ser un numero\n",1,5,3);
            switch(opcion)
            {
                case 1:
                pMovie=(void*)malloc(sizeof(EMovie));
                pMovie->estado=0;
                agregarPelicula(pMovie,&posiciongregar);//mas adelante abris desde aca el archivo y cerrarlo atras
                printf("pelicula agregada exitosamente");

                break;
                case 2:
                pMovie=(void*)malloc(sizeof(EMovie));
                if(borrarPelicula(pMovie,&posiciongregar))
                {
                    printf("pelicula borrada exitosamente");
                }

                    break;
                case 3:
                pMovie=(void*)malloc(sizeof(EMovie));
                         if(modificarpelicula(pMovie))
                         {
                            printf("pelicula modificada exitosamente");
                         }
                   break;
              case 4:
                    generarPagina(pMovie,"index.html");
                break;

            case 5:
                    seguir = 'n';
                    break;
            }



    }while(seguir=='s');


 return 0;
}
