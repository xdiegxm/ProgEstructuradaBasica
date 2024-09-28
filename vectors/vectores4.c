/*1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 60
int Buscar (int [], int, int);
void Ordenar (int [], int [], int);
int main()
{
    int vAlumnos[TAM], vNotas[TAM], dni, pos, i=0, cantidad;

        do
        {
        printf("\nIngrese DNI del alumno ( negativo para terminar ): \n");
        scanf("%d",&dni);
        if(dni<1000000||dni>99999999)
        {
            if(dni>=0)
            {
                printf("\nDNI inexistente.\n");
            }
        }
        }while((dni<1000000||dni>99999999)&&dni>=0);
    while(dni>=0&&i<60)
    {
        pos=Buscar(vAlumnos,dni,i);
        if(pos==-1)
        {
            vAlumnos[i]=dni;
            printf("\nIngrese nota del alumno: \n");
            scanf("%d",&vNotas[i]);
            i++;
        }
        else
        {
            printf("\nDNI ya existente.\n");
        }
       do
        {
            printf("\nIngrese DNI del alumno ( negativo para terminar ): \n");
            scanf("%d",&dni);
            if(dni<1000000||dni>99999999)
            {
                if(dni>=0)
                {
                printf("\nDNI inexistente.\n");
                }
            }
        }while((dni<1000000||dni>99999999)&&dni>=0);
    }
    cantidad=i;
    Ordenar(vAlumnos,vNotas,cantidad);
    printf("\nALUMNO\t\tNOTA\n\n");
    for(i=0;i<cantidad;i++)
    {
        printf("%d\t%d\n", vAlumnos[i], vNotas[i]);
    }
    return 0;
}
int Buscar (int v[], int dato, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1)
    {
        if(v[i]==dato)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}
void Ordenar (int v[], int v2[], int ce)
{
    int i, j, aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(v[j]>=v[j+1])
                {
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;

                    aux=v2[j];
                    v2[j]=v2[j+1];
                    v2[j+1]=aux;
                }
        }
    }
}


