/*1.5 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15
int Buscar (int [], int, int);
void IngresaCodigos (int [], int);
void Ordenar (int [], int);
void OrdenarVectores (int [], int [], int);
int main()
{
    int vProductos[TAM], i, vVendedor[5], vendedor=1001, codv, pos, coda, vCantidad[TAM]={0}, cant, vVentas[5]={0}, min=10000;
    IngresaCodigos(vProductos,TAM);
    printf("\nCODIGOS DE PRODUCTOS GENERADOS\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d\n", vProductos[i]);
    }
    printf("\nPRODUCTOS ORDENADOS DE FORMA ASCENDENTE\n\n");
    Ordenar(vProductos,TAM);
    for(i=0;i<TAM;i++)
    {
        printf("%d\n", vProductos[i]);
    }
    for(i=0;i<5;i++)
    {
        vVendedor[i]=vendedor;
        vendedor++;
    }

    printf("\nIngrese codigo de vendedor ( entre 1001 y 1005 o 0 para terminar ):\n");
    do
    {
        scanf("%d",&codv);
        if((codv<1001||codv>1005)&&codv!=0)
        {
            printf("\nCodigo de vendedor incorrecto, ingrese uno nuevamente:\n");
        }
    }while((codv<1001||codv>1005)&&codv!=0);

    while(codv!=0)
    {
        pos=Buscar(vVendedor,codv,5);
        vVentas[pos]++;
        if(pos!=-1)
        {
            printf("\nIngrese codigo de articulo:\n");
            do
            {
                scanf("%d",&coda);
                pos=Buscar(vProductos,coda,TAM);
                if(pos==-1)
                {
                    printf("\nCodigo de articulo inexistente, ingrese uno nuevamente:\n");
                }
            }while(pos==-1);

            printf("\nIngrese cantidad:\n");
            scanf("%d",&cant);
            vCantidad[pos]+=cant;
        }

        printf("\nIngrese codigo de vendedor ( entre 1001 y 1005 o 0 para terminar ):\n");
        do
        {
            scanf("%d",&codv);
            if((codv<1001||codv>1005)&&codv!=0)
            {
                printf("\nCodigo de vendedor incorrecto, ingrese uno nuevamente:\n");
            }
        }while((codv<1001||codv>1005)&&codv!=0);

    }
    OrdenarVectores(vCantidad,vProductos,TAM);
    printf("\nCANT UNIDADES\t\tCODIGO\n\n");
    for(i=0;i<TAM;i++)
    {
        printf("%d\t\t\t%d\n", vCantidad[i], vProductos[i]);
    }

    printf("\n\nVENDEDOR\t\tVENTAS\n\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t\t\t%d\n", vVendedor[i], vVentas[i]);
    }

    for(i=0;i<5;i++)
    {
        if(i==0||vVentas[i]<min)
        {
            min=vVentas[i];
        }
    }
    printf("\nLa menor venta realizada fue %d y la/s realizaron los vendedor/es\n\n", min);
    for(i=0;i<5;i++)
    {
        if(vVentas[i]==min)
        {
            printf("%d\n", vVendedor[i]);
        }
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
void IngresaCodigos (int v[], int ce)
{
    int i, pos, rango, cod;
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
void Ordenar (int v[], int ce)
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
            }
        }
    }
}
void OrdenarVectores (int v[], int v2[], int ce)
{
    int i, j, aux;
    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(v[j]<=v[j+1])
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
