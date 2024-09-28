/*4.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES
VENDIDAS
IMPORTE TOTAL
VENDIDO
XXXXXXX XXXX $XXXXX,XX*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1
typedef struct
{
    int cod;
    float precio;
    char descr[31];
    int cantunidad;
    float importeTotal;
}Productos;
int IngresarProductos (Productos [], int);
int LeerYValidar (int, int);
int Buscar (Productos [], int, int);
void Mostrar (Productos [], int);
int main()
{
        Productos vProductos[TAM];
        int cantCargados, cantPed, codigo, pos;
        cantCargados=IngresarProductos(vProductos,TAM);
        printf("\n\n\n\t --VENTAS DEL MES ANTERIOR--\n");
        Mostrar(vProductos,cantCargados);
        printf("\n\n\n\t--INGRESO DE VENTAS DEL MES--\n");
        printf("\nIngrese cantidad de unidades pedidas (0 para terminar):  ");
        cantPed=LeerYValidar(0,10000000);
        while(cantPed!=0){
            printf("\nIngrese codigo de producto:  ");
            do{
                codigo=LeerYValidar(10000,99999);
                pos=Buscar(vProductos,codigo,cantCargados);
                if(pos==-1){
                    printf("\nCodigo de producto inexistente. Ingrese uno nuevamente:  ");
                }
            }while(pos==-1);
            vProductos[pos].cantunidad=cantPed;
            vProductos[pos].importeTotal=(float)vProductos[pos].precio*cantPed;
            printf("\nIngrese cantidad de unidades pedidas (0 para terminar):  ");
            cantPed=LeerYValidar(0,10000000);
        }
         printf("\n\n\n\t--VENTAS DEL MES ACTUALIZADAS--\n");
        Mostrar(vProductos,cantCargados);
    return 0;
}
int IngresarProductos (Productos vp[], int ce){
    int i=0, cantun, code, pos;
    float importeT, prec;
    char desc[31];
    printf("\n\t--CARGA PARCIAL DE PRODUCTOS--\n");
    printf("\nIngrese descripcion del producto %d (FIN para terminar): ", i+1);
    fgets(desc,31,stdin);
    desc[strlen(desc)-1]='\0';
    while(strcmpi(desc,"FIN")!=0&&i<ce){
        strcpy(vp[i].descr,desc);
        printf("\nIngrese codigo de producto:  ");
        do{
            code=LeerYValidar(10000,99999);
            pos=Buscar(vp,code,i);
            if(pos!=-1){
                printf("\nCodigo repetido. Ingrese uno nuevamente:  ");
            }
        }while(pos!=-1);
        vp[i].cod=code;
        printf("\nIngrese precio del producto:  ");
        scanf("%f", &prec);
        vp[i].precio=prec;
        printf("\nIngrese cantidad de unidades (mes anterior):  ");
        scanf("%d", &cantun);
        vp[i].cantunidad=cantun;
        vp[i].importeTotal=cantun*prec;
        printf("\nImporte total del producto (mes anterior):  %.2f", vp[i].importeTotal);
        i++;
        if(i<ce){
        printf("\n\nIngrese descripcion del producto %d (FIN para terminar): ", i+1);
        fflush(stdin);
        fgets(desc,31,stdin);
        desc[strlen(desc)-1]='\0';
        }
    }
    return i;
}
int LeerYValidar (int min, int max){
    int aux;
    do{
        scanf("%d", &aux);
        if(aux<min||aux>max){
            printf("\nDato ingresado no valido. Ingese uno nuevamente:  ");
        }
    }while(aux<min||aux>max);
}
int Buscar(Productos prod[], int dato, int ce){
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(prod[i].cod==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}
void Mostrar (Productos vp[], int ce){
    int i;
    printf("\n%15s %15s %9s", "    DESCRIPCION", "  CANT UNIDADES", "  IMPORTE");
    for(i=0;i<ce;i++){
        printf("\n%15s %15d %9.2f", vp[i].descr, vp[i].cantunidad, vp[i].importeTotal);
    }
}
