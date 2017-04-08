#include "funciones.h"



int suma(int numero1,int numero2)
{
   return numero1+numero2;



}
int resta(int numero1,int numero2)
{

    return numero1-numero2;
}
float division(int numero1,int numero2,float *resultado)
{
int  retorno=0;
    if(numero2)//aseguro que el divisor no sea 0
                    {
                        *resultado=((float)numero1/(float)numero2);
                        retorno=1;
                    }
    return retorno;
}
int multiplicacion(int numero1,int numero2)
{

    return numero1*numero2;

}




double factorial(int numero1)
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
