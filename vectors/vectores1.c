/*1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/
#include <stdio.h>
#include <time.h>
#define TAM 20
void CargaAleatoria (int[], int, int);
int Maximo (int[], int);
void MostrarMaximo (int[], int, int);
int Minimo (int[], int);
void MostrarMinimo (int[], int, int);
int main()
{
    int num, vec[TAM],max, min;
    srand(time(NULL));
    CargaAleatoria(vec,TAM,1000);
    max=Maximo(vec,TAM);
    MostrarMaximo(vec,max,TAM);
    min=Minimo(vec,TAM);
    MostrarMinimo(vec,min,TAM);
    return 0;
}
void CargaAleatoria (int v[], int ce, int max)
{
    int i;
    for(i=0 ; i<ce;i++)
    {
        v[i]=rand()%max;
    }
}
int Maximo (int v[], int ce)
{
    int max=v[0], i;
    for(i=1;i<ce;i++)
    {
        if(v[i]>max)
            max=v[i];
    }
    return max;
}
void MostrarMaximo (int v[], int max, int ce)
{
    int cont=0, i;
    printf("\nEl valor maximo es: %d y se en cuentra en las siguientes posiciones del vector:\n", max);
    for(i=0;i<ce;i++)
    {
        if(v[i]==max)
        {
            printf("%d\n",i+1);
            cont++;
        }
    }
    printf("El valor maximo se repite %d veces\n", cont);
}
int Minimo (int v[], int ce)
{
    int min=v[0], i;
    for(i=1;i<ce;i++)
    {
        if(v[i]<min)
        {
            min=v[i];
        }
    }
    return min;
}
void MostrarMinimo (int v[], int min, int ce)
{
    int cont=0, i;
    printf("\nEl valor minimo es: %d y se encuentra en las siguientes posiciones del vector:\n", min);
    for(i=0;i<ce;i++)
    {
        if(v[i]==min)
        {
            printf("%d\n", i+1);
            cont++;
        }
    }
    printf("El valor minimo se repite %d veces\n", cont);
}





















