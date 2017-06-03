#include "header.h"


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
 FILE* abrirarchivo(FILE *archivo,char nombrearchivo[],char modo[])
{

    archivo=fopen(nombrearchivo,modo);



    return archivo;
}





int agregarPelicula(EMovie* pmovie, int* posicionagregar)
{


    FILE* archivo;
    int estado;
    FILE*archivo2;
    int cantidad;
    int contador=0;
    int i;



        archivo2=abrirarchivo(archivo2,"peliculas.dat","rb");
        if(archivo2==NULL)
        {
          archivo2=abrirarchivo(archivo2,"peliculas.dat","wb");
          if(archivo2==NULL)
          {
              printf("no se  pudo abrir el achivo\n");
              free(pmovie);

              exit(0);

          }
        }
        if(archivo2!=NULL)
        {
            while(fread((void*)(pmovie+contador),sizeof(EMovie),1,archivo2))
            {
                    contador++;

                    cantidad=contador+1;
                    pmovie=(EMovie*)realloc(pmovie,sizeof(EMovie)*cantidad);
                   if( pmovie==NULL)
                   {   printf("no se pudo asignar mas memoria\n");
                        fclose(archivo2);
                        free(pmovie);

                       exit(0);

                   }
                   else
                   {

                       (pmovie+(contador))->estado=0;

                   }


                }
            fclose(archivo2);
          }


archivo=abrirarchivo(archivo,"peliculas.dat","wb");
    if(archivo==NULL)
    {
        printf("error al abrir el archivo");
        free(pmovie);

        exit(0);
    }
    getString("ingrese  titulo\n ",(pmovie+(contador))->titulo,TAMNOMBRES);
    while(comprueba_pelicula("peliculas.dat",(pmovie+(contador))->titulo,pmovie,contador)==1)
    {
      printf("pelicula ya existente ingrese otra\n");
      getString("ingrese  titulo\n ",(pmovie+(contador))->titulo,TAMNOMBRES);
      //system("pause");
      //system("cls")
    }
    getString("ingrese   genero\n",(pmovie+(contador))->genero,TAMNOMBRES);
    (pmovie+(contador))->duracion=getValidInt("ingrese duracion en minutos\n","error debe ser un numero\n",0,500,5);
    getString("ingrese   describcion\n",(pmovie+(contador))->descripcion,TAMDESCRIB);
    (pmovie+(contador))->puntaje=getValidInt("ingrese puntaje de 1 a 10\n","debe ser un numero\n",1,10,4);
    getString("ingrese   la url\n",(pmovie+(contador))->linkImagen,TAMDESCRIB);
    (pmovie+contador)->estado=1;

    contador++;

    for(i=0;i<(contador);i++)
    {
    estado=fwrite(pmovie+i,sizeof(EMovie),1,archivo);
    if(estado<1)
    {
        printf("error al escribir los datos");
        free(pmovie);
        fclose(archivo);
        exit(0);

    }
    }


    free(pmovie);
    fclose(archivo);
return 1;
}
int borrarPelicula(EMovie* pmovie, int* posicionagregar)
{
    int flag=0;

    int retorno=0;


    FILE* archivo;
    int estado=1;
    FILE* archivo2;
    int cantidad;
    int contador=0;
    int i;
    char nombreaeliminar[TAMNOMBRES];



        archivo2=abrirarchivo(archivo2,"peliculas.dat","rb");
        if(archivo2==NULL)
        {
          archivo2=abrirarchivo(archivo2,"peliculas.dat","wb");
          if(archivo2==NULL)
          {
              printf("no se  pudo abrir el achivo\n");
              exit(0);
          }
        }
        if(archivo2!=NULL)
        {
            while(fread((void*)(pmovie+contador),sizeof(EMovie),1,archivo2))
            {
                    contador++;
                    (*posicionagregar)++;
                    cantidad=contador+1;
                    pmovie=(EMovie*)realloc(pmovie,sizeof(EMovie)*cantidad);
                   if( pmovie==NULL)
                   {   printf("no se pudo asignar mas memoria\n");
                        fclose(archivo2);
                       exit(0);

                   }
                   else
                   {

                       (pmovie+(contador))->estado=0;

                   }


            }
           fclose(archivo2);
          }
        if(contador!=0)
        {



            for(i=0;i<contador;i++)
            {
                printf("%d %s\n",i+1,(pmovie+i)->titulo);
            }
            getString("escriba el nombre de la pelicula que desea eliminar\n",nombreaeliminar,TAMNOMBRES);

            for(i=0;i<contador;i++)
            {
                if(strcmp(nombreaeliminar,(pmovie+i)->titulo)==0)
                {
                    (pmovie+i)->estado=0;
                    flag=1;
                }

            }
            if(flag==1)//compruebo si encontro la pelicula
                {
                    archivo=abrirarchivo(archivo,"peliculas.dat","wb");
                        if(archivo==NULL)
                        {
                            printf("error al abrir el archivo");
                            free(pmovie);

                            exit(0);
                        }
                        for(i=0;i<(contador);i++)
                        {
                            if((pmovie+i)->estado==1)
                           {
                        estado=fwrite(pmovie+i,sizeof(EMovie),1,archivo);
                            }
                        if(estado<1)
                        {
                            printf("error al escribir los datos");
                            free(pmovie);
                            fclose(archivo);
                            exit(0);

                        }
                        retorno=1;
                        }
                        fclose(archivo);

                }
            else
            {
                printf("no  se encontro la pelicula ingresada\n");
                    retorno=0;
            }

        }
        else
        {
           printf("no ahi peliculas cargadas para poder eliminar\n");
           retorno=0;

        }

        return retorno;
}
int comprueba_pelicula(char nombrearch[],char pelicula_buscar[],EMovie* pmovie,int cantpelis)
{
    FILE *archivo;
    int flag=0;
    int i;

    archivo=abrirarchivo(archivo,nombrearch,"rb");
    if(archivo==NULL)
    {
        printf("error al abrir el archivo %s\n",nombrearch);
        exit(0);
    }
    else
    {
      for(i=0;i<cantpelis;i++)
    {
        if(strcmp(pelicula_buscar,(pmovie+i)->titulo)==0)
        {
           flag=1;
           break;
        }

    }

        fclose(archivo);
    }
return flag;

}
int modificarpelicula(EMovie* pmovie)
{
    int flag=0;

    int retorno=0;

    int opcion;
    FILE* archivo;
    int estado=1;
    FILE*archivo2;
    int cantidad;
    int contador=0;
    int i;
    char nombremodificar[TAMNOMBRES];



        archivo2=abrirarchivo(archivo2,"peliculas.dat","rb");
        if(archivo2==NULL)
        {
          archivo2=abrirarchivo(archivo2,"peliculas.dat","wb");
          if(archivo2==NULL)
          {
              printf("no se  pudo abrir el achivo\n");
              exit(0);
          }
        }
        if(archivo2!=NULL)
        {
            while(fread((void*)(pmovie+contador),sizeof(EMovie),1,archivo2))
            {
                    contador++;

                    cantidad=contador+1;
                    pmovie=(EMovie*)realloc(pmovie,sizeof(EMovie)*cantidad);
                   if( pmovie==NULL)
                   {   printf("no se pudo asignar mas memoria\n");
                        fclose(archivo2);
                       exit(0);

                   }
                   else
                   {

                       (pmovie+(contador))->estado=0;

                   }


            }
           fclose(archivo2);
          }
        if(contador!=0)
        {



            for(i=0;i<contador;i++)
            {
                printf("%d %s\n",i+1,(pmovie+i)->titulo);
            }
            getString("escriba el nombre de la pelicula que desea modificar\n",nombremodificar,TAMNOMBRES);

            for(i=0;i<contador;i++)
            {
                if(strcmp(nombremodificar,(pmovie+i)->titulo)==0)
                {

                    flag=1;

                    printf("1:titulo%s\n2:genero%s\n3:duracion%d\n4:describcion%s\n",(pmovie+i)->titulo,(pmovie+(i))->genero,(pmovie+(i))->duracion,(pmovie+(i))->descripcion);
                    printf("5:puntaje%d\n6:linkimagen%s\n",(pmovie+(i))->puntaje,(pmovie+(i))->linkImagen);
                    opcion=getValidInt("que opcion desea modificar\n","error la opcion debe ser numerica\n",1,6,4);
                    switch(opcion)
                    {
                    case 1:
                        getString("ingrese  titulo\n ",(pmovie+i)->titulo,TAMNOMBRES);
                        break;
                    case 2:
                        getString("ingrese   genero\n",(pmovie+(i))->genero,TAMNOMBRES);
                        break;
                    case 3:
                        (pmovie+(i))->duracion=getValidInt("ingrese duracion en minutos\n","error debe ser un numero\n",0,500,5);
                        break;
                        getString("ingrese   describcion\n",(pmovie+(i))->descripcion,TAMDESCRIB);
                     case 4:
                        (pmovie+(i))->puntaje=getValidInt("ingrese puntaje de 1 a 10\n","debe ser un numero\n",1,10,4);
                        break;
                      case 5:
                        getString("ingrese   la url\n",(pmovie+(i))->linkImagen,TAMDESCRIB);
                       break;


                    default:
                        break;

                    }
                    break;
                }

            }
            if(flag==1)//compruebo si encontro la pelicula
                {
                    archivo=abrirarchivo(archivo,"peliculas.dat","wb");
                        if(archivo==NULL)
                        {
                            printf("error al abrir el archivo");
                            free(pmovie);

                            exit(0);
                        }
                        for(i=0;i<(contador);i++)
                        {
                            if((pmovie+i)->estado==1)
                           {
                        estado=fwrite(pmovie+i,sizeof(EMovie),1,archivo);
                            }
                        if(estado<1)
                        {
                            printf("error al escribir los datos");
                            free(pmovie);
                            fclose(archivo);
                            exit(0);

                        }
                        retorno=1;
                        }
                        fclose(archivo);
                        free(pmovie);

                }
            else
            {
                printf("no  se encontro la pelicula ingresada\n");
                    retorno=0;
            }

        }
        else
        {
           printf("no ahi peliculas cargadas para podermodificar\n");
           retorno=0;

        }

        return retorno;

}
void generarPagina(EMovie *pmovie, char nombre[])
{


char head[]={"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script></head><body><div class='container'><div class='row'>"};

char footer[]={"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>"};

char link[]={"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='"};

char titulo[]={"' alt=''></a><h3><a href='#'>"};

char genero[]={"</a></h3><ul><li>Genero:"};

char puntaje[]={"</li><li>Puntaje:"};

char duracion[]={"</li><li>Duracion:"};

char descripcion[]={"</li></ul><p>"};

char final[]={"</p></article>"};



FILE* archivo;

FILE*archivo2;
int cantidad;
int contador=0;
int i;



    archivo2=abrirarchivo(archivo2,"peliculas.dat","rb");
    if(archivo2==NULL)
    {
      archivo2=abrirarchivo(archivo2,"peliculas.dat","wb");
      if(archivo2==NULL)
      {
          printf("no se  pudo abrir el achivo\n");
          free(pmovie);

          exit(0);

      }
    }
    if(archivo2!=NULL)
    {
        while(fread((void*)(pmovie+contador),sizeof(EMovie),1,archivo2))
        {
                contador++;

                cantidad=contador+1;
                pmovie=(EMovie*)realloc(pmovie,sizeof(EMovie)*cantidad);
               if( pmovie==NULL)
               {   printf("no se pudo asignar mas memoria\n");
                    fclose(archivo2);
                    free(pmovie);

                   exit(0);

               }
               else
               {

                   (pmovie+(contador))->estado=0;

               }


            }
        fclose(archivo2);
      }


    archivo=abrirarchivo(archivo,"index.html","w");
        if(archivo==NULL)
        {
            printf("error al abrir el archivo");
            free(pmovie);

            exit(0);
        }

    fwrite(head,strlen(head),1,archivo);
    for(i=0;i<(contador);i++)
    {
    fwrite(link,strlen(link),1,archivo);
    fwrite((pmovie+i)->linkImagen,strlen((pmovie+i)->linkImagen),1,archivo);
    fwrite(titulo,strlen(titulo),1,archivo);
    fwrite((pmovie+i)->titulo,strlen((pmovie+i)->titulo),1,archivo);
    fwrite(genero,strlen(genero),1,archivo);
    fwrite((pmovie+i)->genero,strlen((pmovie+i)->genero),1,archivo);
    fwrite(puntaje,strlen(puntaje),1,archivo);
    fprintf(archivo,"%d",((pmovie+i)->puntaje));
    //fwrite(c),4,1,archivo);
    fwrite(duracion,strlen(duracion),1,archivo);
     fprintf(archivo,"%d",((pmovie+i)->duracion));
    fwrite(descripcion,strlen(descripcion),1,archivo);
    fwrite(((pmovie+i)->descripcion),strlen((pmovie+i)->descripcion),1,archivo);
    fwrite(final,strlen(final),1,archivo);


    }
    fwrite(footer,strlen(footer),1,archivo);
    free(pmovie);


    fclose(archivo);

}

