/*3.4 Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de
los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada
venta se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int IngresarProductos (char [][4], float [], int);
int Buscar (char [][4], char [], int);
void Ordenar (char [][4], float [], int);
int main()
{
    char mCodigos[49][4], vCodigos[4];
    float vPrecio[49], recTotal=0;
    int cantProductos, cantUnidades, pos, vMenorUnidades[49]={0}, i, menor=0;
    cantProductos=IngresarProductos(mCodigos,vPrecio,49);
    if(cantProductos>0)
    {
    printf("\n\nVENTAS DEL DIA...\n");
    printf("\nIngrese codigo de producto:  ");
    do{
        getchar();
        fgets(vCodigos,4,stdin);
        pos=Buscar(mCodigos,vCodigos,cantProductos);
        if(pos==-1)
            printf("\nCodigo no encontrado. Ingrese uno nuevamente: ");
    }while(pos==-1);
    printf("\nIngrese cantidad de unidades (0 para terminar): ");
    scanf("%d", &cantUnidades);
    while(cantUnidades!=0){
        recTotal+=cantUnidades*vPrecio[pos];
        vMenorUnidades[pos]+=cantUnidades;
        printf("\nIngrese codigo de producto:  ");
        do{
            getchar();
            fgets(vCodigos,4,stdin);
            pos=Buscar(mCodigos,vCodigos,cantProductos);
            if(pos==-1)
                printf("\nCodigo no encontrado. Ingrese uno nuevamente: ");
        }while(pos==-1);
        printf("\nIngrese cantidad de unidades (0 para terminar): ");
        scanf("%d", &cantUnidades);
    }
    printf("\nLISTADO DE PRODUCTOS\n");
    Ordenar(mCodigos,vPrecio,cantProductos);
    for(i=0;i<cantProductos;i++){
        printf("Producto: %s Precio: %.2f\n", mCodigos[i], vPrecio[i]);
    }
    printf("Recaudacion Total: %.2f", recTotal);
    menor=vMenorUnidades[0];
    for(i=1;i<cantProductos;i++){
        if(vMenorUnidades[i]<menor)
            menor=vMenorUnidades[i];
            pos=i;
    }
    printf("\nProducto con menor cantidad de unidades: %s", mCodigos[pos]);
    printf("\nUnidades: %d", menor);
    }
    return 0;
}
int IngresarProductos (char mcod[49][4], float precio[49], int ce){
    int i=0;
    float p;
    char cod[4];
    printf("\nIngrese codigo de producto (FIN para terminar): ");
    fgets(cod,4,stdin);
    while(i<ce&&strcmpi(cod,"FIN")!=0){
        printf("\nIngrese precio del producto: ");
        scanf("%f", &p);
        precio[i]=p;
        strcpy(mcod[i],cod);
        printf("\nIngrese codigo de producto (FIN para terminar): ");
        getchar();
        fgets(cod,4,stdin);
        i++;
    }
    return i;
}
int Buscar (char m[][4], char v[4], int ce){
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(strcmpi(m[i],v)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}
void Ordenar (char m[][4], float p[], int ce){
    int i, j;
    float auxp;
    char auxm[4];
    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(strcmpi(m[j],m[j+1])>=0){
                strcpy(auxm,m[j]);
                strcpy(m[j],m[j+1]);
                strcpy(m[j+1],auxm);

                auxp=p[j];
                p[j]=p[j+1];
                p[j+1]=auxp;
            }
        }
    }
}





