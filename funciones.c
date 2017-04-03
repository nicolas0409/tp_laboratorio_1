#include "funciones.h"



int suma(int numero1,int numero2)
{
   return numero1+numero2;



}
int resta(int numero1,int numero2)
{

    return numero1-numero2;
}
float division(int numero1,int numero2)
{

    if(numero2!=0)
                    {

                        return((float)numero1/(float)numero2);

                    }
                    else
                    {
                        printf("la division por 0 es indefinida ingrese otro dividendo");
                        system("pause");
                    }
}
int multiplicacion(int numero1,int numero2)
{

    return numero1*numero2;

}




int factorial(int numero1)
{
if(numero1<0)
{
    return 0;
}

if(numero1==0)
{return 1;
}

  return  (numero1*factorial(numero1-1));




}

