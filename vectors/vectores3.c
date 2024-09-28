/*1.3 En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones
de un tema dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de
exposición de dichos grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición
distinto para cada uno de los 5 grupos.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
int Buscar (int [], int, int);
int main()
{
    int i, pos, vGrupo[TAM], grupo;
    srand(time(NULL));

    for(i=0;i<TAM;i++)
    {
        do
        {
            grupo=rand()%5+1;
            pos=Buscar(vGrupo,grupo,i);
            if(pos!=-1)
            {
                printf("\nGrupo existente.\n");
            }
        }while(pos!=-1);
        vGrupo[i]=grupo;
    }
    printf("\nGRUPOS SORTEADOS\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d) %d\n", i+1, vGrupo[i]);
    }
    return 0;
}
int Buscar (int v[], int dato, int ce)
{
    int i=0, pos=-1;
    while(pos==-1&&i<ce)
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
