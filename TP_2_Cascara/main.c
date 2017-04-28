
#include "funciones.h"


int main()
{

    char seguir='s';
    int opcion=0,indice;
    int auxiliar,edad_temporal,dni_temporal;
    char nombre_temporal[50];
    char chrdni_temporal[TAMDNI];
    char chredad_temporal[TAMEDAD];
     long long int intdni;
    EPersona lista[TAM];

    int i;


    for(i=0;i<TAM;i++){
      lista[i].estado=0;//inicializo el vector de personas en 0 incluyendo el estado
    }
     ////////////////////////////////7

   int dnih[TAM]={1003445,101344,102456,1034643,1043546,345667,456732,6796543,34568579,247899};
    int edadh[TAM]={15,12,34,23,67,24,45,75,35,3};
     char nombreh[TAM][50]={"nicolas gonzalez","laura rodriguez nacitllo","laura rodriguez","laura rod","daniel","martin","nicolas augusto","juan","sergio","lorena"};
    int estadoh[TAM]={1,1,1,1,1,1,1,1,1,1};



     for(i=0; i<TAM;i++)
    {
        lista[i].dni = dnih[i];
        strcpy(lista[i].nombre, nombreh[i]);
        lista[i].edad =edadh[i];
        lista[i].estado = estadoh[i];

    }







    //////////////////////////////////


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        fflush(stdin);

        if(scanf("%d",&opcion))
    {


            switch(opcion)
            {
                case 1:
                    indice=obtenerEspacioLibre(lista);
                    if(indice>=0)
                    {
                         fflush(stdin);
                         printf("ingrese nombre\n");
                        fgets(nombre_temporal,50,stdin);
                        nombre_temporal[strlen(nombre_temporal)-1]='\0';

                        printf("ingrese la edad");
                        fflush(stdin);
                         fgets(chredad_temporal,TAMEDAD,stdin);
                         chredad_temporal[strlen(chredad_temporal)-1]='\0';
                        printf("ingrese el dni");
                        fflush(stdin);
                        fgets(chrdni_temporal,TAMDNI,stdin);
                         chrdni_temporal[strlen(chrdni_temporal)-1]='\0';
                        intdni=validar_numero(chrdni_temporal,TAMDNI);
                        if(intdni==-1)
                        {
                            printf("el numero debe ser solo numeros sin caracteres alfnumericos\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                         if(intdni<0||intdni>999999999)
                         {
                             printf("el nuemro  de dni debe ser entre 0 y 999999999");
                             system("pause");
                            system("cls");
                             break;

                         }
                        edad_temporal=validar_numero(chredad_temporal,TAMEDAD);
                        if(edad_temporal==-1)
                        {
                            printf("la edad debe ser solo numeros sin caracteres alfnumericos\n");
                            system("pause");
                            system("cls");
                            break;

                        }
                        else if(edad_temporal<0||edad_temporal>140)
                        {
                            printf(" la edad debe ser un numero entre 0 y 140 anios vuelvalo a intentar\n");
                              system("pause");
                            system("cls");
                            break;
                        }
                        auxiliar=agregapersona(lista,nombre_temporal,intdni,edad_temporal,indice);
                        if(auxiliar>0)
                        {
                            printf("persona agregada correctamente\n");
                            system("pause");
                            system("cls");
                        }
                        else if(auxiliar==0)
                        {
                            printf("el dni ya existe,intentelo de nuevo con otro de dni\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            printf("edad incorrecta tiene que  una edad entre 0 y 120 años  maximo\n");
                            system("pause");
                            system("cls");
                        }


                    }
                    else
                    {
                        printf("la lista esta  llena necesita primero eliminar alguna persona\n");
                        system("pause");
                        system("cls");
                    }




                    break;
                case 2:


                    printf("ingrese el dni de la persona que desea borrar sin puntos\n");
                    fflush(stdin);
                    fgets(chrdni_temporal,TAMDNI,stdin);
                    chrdni_temporal[strlen(chrdni_temporal)-1]='\0';
                    dni_temporal=validar_numero(chrdni_temporal,TAMDNI);
                    if(dni_temporal>=0)
                    {

                        if(dni_temporal>0&&dni_temporal<999999999)
                        {
                            if(borrar_persona(lista,dni_temporal))
                            {
                                printf("persona eliminada correctamente\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                            else
                            {

                                printf("dni ingresado no existe en la base de datos\n");
                                system("pause");
                                system("cls");
                            }
                        }
                        else
                        {
                            printf("el numero de dni tiene que ser un numero mayor que 0 y menor que 999999999\n");
                            system("pause");
                            system("cls");
                        }

                    }
                    else
                    {
                        printf("el dni tiene que ser un numero \n");
                        system("pause");
                        system("cls");
                    }

                    break;
                case 3:
                ordenar(lista,TAM);

                    for(i=0;i<TAM;i++)
                    {
                        if(lista[i].estado)
                        {
                          printf("%s\t%d\t%d\n",lista[i].nombre,lista[i].dni,lista[i].edad);

                        }

                    }
                    system("pause");
                    system("cls");
                    break;
                case 4:
                  graficar(lista);
                  system("pause");
                    system("cls");
                    break;
                case 5:
                    seguir = 'n';
                    break;
                 default:
                      printf("introdujo una opcion incorrecta,el numero tiene que ser de 1 a 5\n");
                    system("pause");
                    system("cls");
                    break;
            }
        }
        else
        {
            printf("introdujo una opcion incorrecta,la opcion tiene que ser numerica\n");
            system("pause");
            system("cls");
        }

    }

    return 0;
}
