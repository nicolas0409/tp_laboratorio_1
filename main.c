#include "funciones.h"


int main()
{
   char seguir='s';
    int opcion=0;
    int numero1;
    int  numero2;
    int vectorflag[]={0,0};

    while(seguir=='s')
    {
        system("cls");
        vectorflag[0]!=1?printf("1- Ingresar 1er operando (A=\"x\")\n"):printf("1- Ingresar 1er operando (A=%d)\n",numero1);
        vectorflag[1]!=1?printf("2- Ingresar 2er operando (A=\"y\")\n"):printf("2- Ingresar 2er operando (B=%d)\n",numero2);
        vectorflag[0]!=1&&vectorflag[1]!=1 ?printf("3- Calcular la suma (A+B)\n"):vectorflag[0]==1&&vectorflag[1]==1?printf("3- Calcular la suma (%d+%d)\n",numero1,numero2):vectorflag[0]==1?printf("3- Calcular la suma (%d+B)\n",numero1):printf("3- Calcular la suma (A+%d)\n",numero2);
        vectorflag[0]!=1&&vectorflag[1]!=1 ?printf("4- Calcular la resta (A-B)\n"):vectorflag[0]==1&&vectorflag[1]==1?printf("4- Calcular la resta (%d-%d)\n",numero1,numero2):vectorflag[0]==1?printf("4- Calcular la resta (%d-B)\n",numero1):printf("4- Calcular la resta (A-%d)\n",numero2);
        vectorflag[0]!=1&&vectorflag[1]!=1 ?printf("5- Calcular la division (A/B)\n"):vectorflag[0]==1&&vectorflag[1]==1?printf("5- Calcular la division (%d/%d)\n",numero1,numero2):vectorflag[0]==1?printf("5- Calcular la division (%d/B)\n",numero1):printf("5- Calcular la division (A/%d)\n",numero2);
        vectorflag[0]!=1&&vectorflag[1]!=1 ?printf("6- Calcular la multiplicacion (A*B)\n"):vectorflag[0]==1&&vectorflag[1]==1?printf("6- Calcular la multiplicacion (%d*%d)\n",numero1,numero2):vectorflag[0]==1?printf("6- Calcular la multiplicacion (%d*B)\n",numero1):printf("6- Calcular la multiplicacion (A*%d)\n",numero2);
        printf(vectorflag[0]==0?"7- Calcular el factorial (A!)\n":"7- Calcular el factorial (%d)\n",numero1);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
            fflush(stdin);
          scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("ingrese un numero");
                fflush(stdin);
                if(scanf("%d",&numero1)!=0)
                {
                   vectorflag[0]=1;
                }
                else
                {
                system("cls");
                printf("debe escojer un numero\n") ;
                system("pause");
                }
                break;
            case 2:
                printf("ingrese un numero");
                fflush(stdin);
                if(scanf("%d",&numero2)!=0)
                {
                   vectorflag[1]=1;
                }
                else
                {
                system("cls");
                printf("debe escojer un numero\n") ;
                system("pause");
                }
                break;
            case 3:
                if(vectorflag[0]==1&&vectorflag[1]==1)
                {
                  system("cls");
                  printf("la suma es %d\n",suma(numero1,numero2));
                  system("pause");
                }
                else
                {
                  printf("falta ingresar  algun  operando\n");
                  system("pause");
                }
                break;
            case 4:
                if(vectorflag[0]==1&&vectorflag[1]==1)
                {
                  system("cls");
                 printf("el resultado es %d \n",resta(numero1,numero2));
                 system("pause");
                }
                else
                {
                  printf("falta ingresar  algun  operando\n");
                  system("pause");
                }

                break;
            case 5:
                if(vectorflag[0]==1&&vectorflag[1]==1)
                {
                    system("cls");
                    printf("el resultado de la division es%f\n",(division(numero1,numero2)));
                    system("pause");
                }
                else
                {
                  printf("falta ingresar  algun  operando\n");
                  system("pause");
                }
                break;
            case 6:
                if(vectorflag[0]==1&&vectorflag[1]==1)
                {
                    system("cls");
                    printf("el resultado de la multiplicacion es %d\n",multiplicacion(numero1,numero2));
                    system("pause");
                }
                else
                    printf("falta ingresar un operador\n");
                    break;
            case 7:
                if(vectorflag[0]==1)
                {
                    if(numero1>0)
                    {
                     printf("el factorial de %d es %d\n",numero1,factorial(numero1));
                    system("pause");
                    }
                    else
                    {   system("cls");
                        printf("solo se  pueden hayar factoriales con base positiva\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("falta ingresar \"a\"\n");
                    system("pause");
                }


                break;
            case 8:
                    if(vectorflag[0]==1&&vectorflag[1]==1)
                {
                   system("cls");
                    printf("El resultado de la suma es %d\n",suma(numero1,numero2));
                    printf("El resultado de la resta es %d\n",resta(numero1,numero2));
                    printf("El resultado de la division es %f\n",division(numero1,numero2));
                    numero1>=1?printf("El resultado de la multiplicacion es %d\n",multiplicacion(numero1,numero2)):printf("solo se  pueden hayar factoriales con base positiva\n");
                    printf("El resultado de el factorial es %d\n",factorial(numero1));
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("faltan operandos por ingresar\n");
                     system("pause");
                }
                break;
            case 9:

                seguir = 'n';
                break;
        }



    }
 return 0;
}
