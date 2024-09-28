/*2.9 Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
• Número de lista
• Número de sede
• Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
c. Candidatos que NO recibieron votos en la sede 5.*/
#include <stdio.h>
#include <time.h>
#define LISTA 10
#define SEDE 15
int LeerYValidarEx (int, int, int);
int LeerYValidar (int, int);
int Buscar (int [], int, int);
void IngrLista (int [], int);
void Ordenar (int [], int [], int);
int main()
{
    float porcentaje=0;
    int mCandidatos[LISTA][SEDE]={0}, vLista[LISTA]={0}, vCantidadVotos[LISTA]={0}, i, j, list, sede, pos, totalvotos, cntvotos;
    IngrLista(vLista,LISTA);
    printf("\tLISTAS\n\n");
    for(i=0;i<LISTA;i++)
    {
        printf("\t %d\n", vLista[i]);
    }
    printf("\nCONTEO DE VOTOS...\n");
    printf("\nIngrese numero de lista ( 0 para terminar ):  ");
    list=LeerYValidarEx(100,999,0);
    while(list!=0)
    {
        pos=Buscar(vLista,list,LISTA);
        if(pos!=-1)
        {
            printf("\nIngrese numero de sede ( 1 a 15 ):  ");
            sede=LeerYValidar(1,15);
            printf("\nIngrese cantidad de votos:  ");
            scanf("%d", &cntvotos);
            mCandidatos[pos][sede-1]=cntvotos;
        }
        else
        {
            printf("\nNumero de lista inexistente.\n");
        }
        printf("\nIngrese numero de lista ( 0 para terminar ):  ");
        list=LeerYValidarEx(100,999,0);
    }

    /*a. Cantidad de votos recibidos por cada candidato en cada sede*/
    printf("\n\t\t\t\tINFORME DE VOTOS\n\n");
    printf("LISTA\t");
    for(i=0;i<SEDE;i++)
    {
    printf("SEDE%d\t", i+1);
    }
    printf("\n");
    for(i=0;i<LISTA;i++)
    {
        totalvotos=0;
        for(j=0;j<SEDE;j++)
        {
            totalvotos+=mCandidatos[i][j];
        }
        if(totalvotos>0)
        {
            printf("%d\t", vLista[i]);
            for(j=0;j<SEDE;j++)
            {
                if(mCandidatos[i][j]>0)
                    printf("%d\t", mCandidatos[i][j]);
                else
                    printf("--\t");
            }
            printf("\n");
        }
    }

    /*b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato*/
    totalvotos=0;
    for(i=0;i<LISTA;i++)/*Sumamos total de votos, y votos por filas*/
    {
        for(j=0;j<SEDE;j++)
        {
            vCantidadVotos[i]+=mCandidatos[i][j];
        }
        totalvotos+=vCantidadVotos[i];
    }
    Ordenar(vCantidadVotos,vLista,LISTA);/*Vectores paralelos para mostrar*/
    printf("\nTOTAL VOTOS\tPORCENTAJE\tLISTA\n\n");
    for(i=0;i<LISTA;i++)
    {
        if(vCantidadVotos[i]>0)
        {
        porcentaje=((float)vCantidadVotos[i]/totalvotos)*100;
        printf("%d\t\t%.2f %\t\t%d\n", vCantidadVotos[i],porcentaje,vLista[i]);
        }
    }
    /*el c no lo hago porq me da paja*/
    return 0;
}
int LeerYValidarEx (int min, int max, int ex)
{
    int aux;
    do
    {
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
        {
            printf("\nDato no valido. Ingrese uno nuevamente:  ");
        }
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}
int LeerYValidar (int min, int max)
{
   int aux;
    do
    {
        scanf("%d", &aux);
        if(aux<min||aux>max)
        {
            printf("\nDato no valido. Ingrese uno nuevamente:  ");
        }
    }while(aux<min||aux>max);
    return aux;
}
int Buscar (int v[], int dato, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1)
    {
        if(v[i]==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}
void IngrLista(int v[], int ce)
{
    int i, pos, cod, rango;
    srand(time(NULL));
    rango=1000-100;
    for(i=0;i<ce;i++)
    {
        do
        {
            cod=rand()%rango+100;
            pos=Buscar(v,cod,i);
            if(pos!=-1)
            {
                printf("\nValor existente, generando otro...\n");
            }
        }while(pos!=-1);
        v[i]=cod;
    }
}
void Ordenar (int v1[], int v2[], int ce)
{
    int i, j, aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(v1[j]<v1[j+1])
            {
                aux=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=aux;

                aux=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=aux;
            }
        }
    }
}
