/*2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por códigos numéricos de 3 cifras. Como primera información se ingresa el
precio unitario de cada uno de los productos y su código. Luego por cada venta se ingresa:
• Código de producto
Guía Práctica – V2.0 3 / 4
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.*/
#include <stdio.h>
int LeerYValidarConEx (int, int, int);
int LeerYValidar (int, int);
int main()
{
    int mat[20][12]={{0}}, cproduc, dia, mes, producmaxrec=0, cantunidades, j, i;
    int vRecaudacion[20]={0}, precio, maxrec=0;
    printf("\nIngrese codigo de producto:\n");
    cproduc=LeerYValidarConEx(100,999,0);
    while(cproduc!=0)
    {
        printf("\nIngrese el precio unitario del producto %d:\n", cproduc);
        scanf("%d", &precio);
        printf("\nIngrese dia de venta: \n");
        dia=LeerYValidar(1,31);
        printf("\nIngrese mes de venta: \n");
        mes=LeerYValidar(1,12);
        printf("\nIngrese cantidad de unidades vendidas: \n");
        scanf("%d",&cantunidades);
        mat[cproduc-1][mes-1]+=cantunidades;
        vRecaudacion[cproduc-1]+=precio*cantunidades;
        if(vRecaudacion[cproduc-1]>maxrec)
        {
            maxrec=vRecaudacion[cproduc-1];
            producmaxrec=cproduc;
        }
        printf("\nIngrese codigo de producto:\n");
        cproduc=LeerYValidarConEx(100,999,0);
    }
return 0;
}
int LeerYValidarConEx (int min, int max, int ex)
{
    int aux;
    do
    {
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
        {
            printf("\nIncorrecto. Ingrese un dato valido:\n");
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
            printf("\nIncorrecto. Ingrese un dato valido:\n");
        }
    }while(aux<min||aux>max);
    return aux;
}


