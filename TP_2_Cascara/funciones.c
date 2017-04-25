#include "funciones.h"
int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    int indice=-1;
    for(i=0;i<TAM;i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
return indice;
}
int buscarPorDni(EPersona lista[],int dni2)
{
    int existe_dni=-1;
    int i;
    for(i=0;i<TAM;i++)
    {
        if(lista[i].estado==1)
        {


            if(lista[i].dni==dni2)
            {
                existe_dni=i;
                break;

            }
        }

    }

return existe_dni;




}
int agregapersona(EPersona lista[],char nombre[],int dni,int edad,int indice)
{
   int resultado;
   if(buscarPorDni(lista,dni)<0)
   {
        if(edad>0&&edad<120)
        {
        strcpy(lista[indice].nombre,nombre);
        lista[indice].dni=dni;
        lista[indice].edad=edad;
        lista[indice].estado=1;
        resultado=1;
        }
        else
        {
            resultado=-1;
        }

   }
   else
    {

        resultado=0;

    }



return resultado;


}

int borrar_persona(EPersona lista[],int dni)
{
int indice_eliminar;
int estadoeliminar=0;
    indice_eliminar=buscarPorDni(lista,dni);
    if(indice_eliminar>=0)
    {
        lista[indice_eliminar].estado=0;
        estadoeliminar=1;
    }
    return estadoeliminar;

}

 void graficar(EPersona lista[])
 {
    int i,j,k;
    char grafica [TAM][3];
    char grafica2 [TAM][3];
memset((void*)grafica,'\0',30);
memset((void*)grafica2,'\0',30);

   for(i=0;i<TAM;i++)
                {
                    if(lista[i].estado==1)
                    {
                    lista[i].edad<18?(grafica[i][0]='*'):(grafica[i][0]=' ');
                   (((lista[i].edad)>=18)&&(lista[i].edad)<36)?(grafica[i][1]='*'):(grafica[i][1]=' ');
                    lista[i].edad>=36?(grafica[i][2]='*'):(grafica[i][2]=' ');
                    }
                }
                for(j=0;j<3;j++)
                {
                    k=0;
                    for(i=0;i<TAM;i++)
                    {
                        if(grafica[i][j]=='*')
                        {
                          grafica2[k][j]= grafica[i][j];
                          k++;
                        }
                        else
                        {
                         grafica2[i][j]=' ';
                        }

                    }
                }
                for(j=(TAM-1);j>=0;j--)
                {
                    for(i=0;i<3;i++)
                        {
                            printf("%c       \t",grafica2[j][i]);
                        }
                        printf("\n");
                }
                printf("menor de 18\t entre18 y 36\t mayor36\n");
                system("pause");
                system("cls");
 }

 void ordenar(EPersona lista[],int tamanio)
 {
     EPersona aux;
     int i;
     int j;

for(j=0;j<tamanio;j++)
{

strlwr(lista[j].nombre);
        strlwr(lista[j-1].nombre);
    for(i=1+j;i<tamanio-1;i++)
    {

       if(strcmp((lista[j].nombre),lista[i].nombre)>0)
          {
              aux=lista[i];
              lista[i]=lista[j];
              lista[j]=aux;
          }

    }
}



 }
