/*1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
int Buscar (int[], int, int);
void IngresaCodigos (int [], int);
int main()
{
    int vcod[TAM], vcant[TAM]={0}, codigo, i, pos, cantidad, max, min;
    IngresaCodigos(vcod,TAM);
    printf("\nCodigos generador aleatoriamente: \n\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d\n", vcod[i]);
    }
    printf("\nIngrese codigo de producto ( 0 para terminar ): \n");
    scanf("%d",&codigo);
    while(codigo!=0)
    {
        pos=Buscar(vcod,codigo,TAM);
        if(pos!=-1)
        {
            printf("\nIngrese cantidad de unidades: \n");
            scanf("%d",&cantidad);
            vcant[pos]+=cantidad;
        }
        else
        {
            printf("\nCodigo no existente, ingrese uno nuevamente.\n");
        }
        printf("\nIngrese codigo de producto ( 0 para terminar ): \n");
        scanf("%d",&codigo);
    }
    printf("\n\nCODIGO \t\tCANTIDAD\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d\t\t%d\n", vcod[i], vcant[i]);
    }
    for(i=0;i<TAM;i++)
    {
        if(i==0||vcant[i]>max)
        {
            max=vcant[i];
        }
    }
    printf("\nEl producto con mayor cantidad posee %d unidades\n", max);
    printf("\nCodigos de productos con mayor cantidad: \n\n");
    for(i=0;i<TAM;i++)
    {
        if(vcant[i]==max)
        {
            printf("%d\n", vcod[i]);
        }
    }

    for(i=0;i<TAM;i++)
    {
        if(i==0||vcant[i]<min)
        {
            min=vcant[i];
        }
    }
    printf("\nEl producto con menor cantidad posee %d unidades\n", min);
    printf("\nCodigo de productos con menor cantidad: \n\n");
    for(i=0;i<TAM;i++)
    {
        if(vcant[i]==min)
        {
            printf("%d\n", vcod[i]);
        }
    }
    return 0;
}
int Buscar (int v[], int dato, int ce)
{
    int i=0, pos=-1;
    while(pos==-1&&i<ce)
    {
        if(v[i]==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}
void IngresaCodigos (int v[], int ce)
{
    int i, cod, pos, rango;
    srand(time(NULL));
    rango=10000-1000;
    for(i=0;i<ce;i++)
    {
        do
        {
            cod=rand()%rango+1000;
            pos=Buscar(v,cod,i);
            if(pos!=-1)
                printf("\nValor existente, ingrese uno nuevamente.\n");
        }while(pos!=-1);
        v[i]=cod;
    }
}
