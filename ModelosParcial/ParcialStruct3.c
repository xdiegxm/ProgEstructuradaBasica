/*Cargar: Codigo (texto de 5 caracteres), descripcion (texto de 30) y precio
de los productos de una empresa (maximo 30 productos, fin de la carga con codigo FIN).
Luego cargar ventas indicando codigo de producto, cantidad vendida y codigo de
vendedor (1001 a 1009). Finalizando la carga de ventas con un codigo de vendedor
igua a 0. Al finalizar mostrar:
a. Un listado ordenado de mayor a menor por cantidad de ventas de cada producto, mostrando
codigo, descripcion, cantidad vendida e importe total de ventas de dicho producto
b. Adicionalmente mostrar un listado de la cantidad de ventas realizadas por cada vendedor*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 30
typedef struct
{
    char codigop[6];
    char descripcion[31];
    float precio;
}SProductos;
int CargarProductos (SProductos [], int);
int Buscar (SProductos [], char [], int);
int LeerYValidar (int, int, int);
void Ordenar (int [], SProductos [], float [], int ce);
int main()
{
    SProductos vProductos[TAM];
    int CantCargados, i, cantv, codvendedor, vCantVentasPP[TAM]={0}, vVendedores[9]={0}, pos;
    float vImpPP[TAM]={0};
    char cod[6];
    CantCargados=CargarProductos(vProductos,TAM);
    if(CantCargados>0){
        printf("\n\n>>PRODUCTOS CARGADOS<<\n");
        printf("%6s %13s %8s","CODIGO","  DESCRIPCION","  PRECIO");
        for(i=0;i<CantCargados;i++){
            printf("\n%6s %13s %8.2f", vProductos[i].codigop, vProductos[i].descripcion, vProductos[i].precio);
        }
        printf("\n\n>>CARGA DE VENTAS<<");
        printf("\nIngrese numero de vendedor (1001 a 1009 o 0 para terminar):  ");
        codvendedor=LeerYValidar(1001,1009,0);
        while(codvendedor!=0){
            printf("Ingrese codigo de producto:  ");
            do{
                fflush(stdin);
                fgets(cod,6,stdin);
                cod[strlen(cod)-1]='\0';
                pos=Buscar(vProductos,cod,CantCargados);
                if(pos==-1)
                    printf("Dato no encontrado. Ingrese uno nuevamente:  ");
            }while(pos==-1);
            printf("Ingrese cantidad vendida:  ");
            do{
                scanf("%d", &cantv);
                if(cantv<0)
                    printf("Dato no valido. Ingrese uno nuevamente:  ");
            }while(cantv<0);
            vCantVentasPP[pos]+=cantv;
            vImpPP[pos]+=cantv*vProductos[pos].precio;
            vVendedores[codvendedor-1001]++;
            printf("\nIngrese numero de vendedor (1001 a 1009 o 0 para terminar):  ");
            codvendedor=LeerYValidar(1001,1009,0);
        }
        //b.listado de la cantidad de ventas realizadas por cada vendedor
        printf("\n\n>>CANTIDAD DE VENTAS REALIZADAS POR VENDEDOR<<");
        for(i=0;i<9;i++){
            printf("\nVENDEDOR %d:  %d", i+1001, vVendedores[i]);
        }
        //a.Un listado ordenado de mayor a menor por cantidad de ventas de cada producto, mostrando
        //codigo, descripcion, cantidad vendida e importe total de ventas de dicho producto
        Ordenar(vCantVentasPP,vProductos,vImpPP,CantCargados);
        printf("\n\n>>LISTADO DE MAYOR A MENOR POR CANTIDAD DE VENTAS<<\n");
        printf("%6s %13s %18s %15s","CODIGO","  DESCRIPCION","  CANTIDAD VENDIDA","  IMPORTE TOTAL");
        for(i=0;i<CantCargados;i++){
            printf("\n%6s %13s %18d %15.2f",vProductos[i].codigop,vProductos[i].descripcion,vCantVentasPP[i],vImpPP[i]);
        }
    }
    return 0;
}
int CargarProductos (SProductos vp[], int ce)
{
    int i=0;
    char cod[6], desc[31];
    float prec;
    printf("\t\t>>CARGA PARCIAL DE PRODUCTOS<<\n");
    printf("\nIngrese codigo de producto ( 5 digitos o FIN para terminar):  ");
    fgets(cod,6,stdin);
    cod[strlen(cod)-1]='\0';
    while(strcmpi(cod,"FIN")!=0&&i<ce){
        strcpy(vp[i].codigop,cod);
        printf("Ingrese descripcion:  ");
        fflush(stdin);
        fgets(desc,31,stdin);
        desc[strlen(desc)-1]='\0';
        strcpy(vp[i].descripcion,desc);
        printf("Ingrese precio:  ");
        do{
            scanf("%f", &prec);
            if(prec<0)
                printf("Dato no valido. Ingrese uno nuevamente:  ");
        }while(prec<0);
        vp[i].precio=prec;
        i++;
        if(i<ce){
            printf("\nIngrese codigo de producto ( 5 digitos o FIN para terminar):  ");
            fflush(stdin);
            fgets(cod,6,stdin);
            cod[strlen(cod)-1]='\0';
        }
    }
    return i;
}
int Buscar (SProductos vp[], char dato [], int ce)
{
    int pos=-1, i=0;
    while(i<ce&&pos==-1){
        if(strcmp(vp[i].codigop,dato)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}
int LeerYValidar (int min, int max, int ex)
{
    int aux;
    do{
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
            printf("Dato no valido. Ingrese uno nuevamente:  ");
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}
void Ordenar (int cv[], SProductos vp[], float vi[], int ce){
    int i, j, aux1;
    SProductos aux2;
    float aux3;
    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(cv[j]<cv[j+1]){
                aux1=cv[j];
                cv[j]=cv[j+1];
                cv[j+1]=aux1;

                aux2=vp[j];
                vp[j]=vp[j+1];
                vp[j+1]=aux2;

                aux3=vi[j];
                vi[j]=vi[j+1];
                vi[j+1]=aux3;
            }
        }
    }
}





