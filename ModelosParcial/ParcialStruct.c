/*
Se desea realizar un programa en lenguaje C que permita actualizar el precio y/o modificar la descripción de un producto en forma individual.

 La empresa trabaja con 200 productos con la siguiente estructura:

Código (entero)
Precio (float)
Descripción (de hasta 50 caracte0
000res)
Se solicita Ingresar dichos datos en un vector de estructuras.

Luego se ingresarán por teclado códigos de productos, de los cuales se quiere modificar algún dato o ambos hasta ingresar un código cero.
En caso de existir el código en el vector.

Adicionalmente se solicita informar el porcentaje de códigos rechazados. Se lo considera rechazado cuando el código a buscar no existe en el vector.

 Para la búsqueda del código en el vector de estructuras, utilizar una función.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 200
typedef struct {
    int codp;
    float preciop;
    char descripcion[51];
}SProductos;
int Buscar (SProductos [], int, int);
int IngresarProductos (SProductos [], int);
int LeerYValidar (int, int, int);
int main()
{
    SProductos vProductos[TAM];
    int CantIngresados=0, CantRechazados=0, codigo, pos, i, modificar, cant1=0;
    char descrip[51];
    float prec, porcCodigos;
    CantIngresados=IngresarProductos(vProductos,TAM);
    if(CantIngresados>0){
        printf("\n\n>>PRODUCTOS INGRESADOS<<");
        for(i=0;i<CantIngresados;i++){
            printf("\nCODIGO: %d DESCRIPCION: %s PRECIO: %.2f", vProductos[i].codp,vProductos[i].descripcion,vProductos[i].preciop);
        }
        printf("\n\n>>INGRESO DE VENTAS<<");
        printf("\nIngrese codigo de producto (0 para terminar):  ");
        do{
            codigo=LeerYValidar(100,1000,0);
            pos=Buscar(vProductos,codigo,CantIngresados);
            if(pos==-1&&codigo!=0){
                printf("Codigo inexistente. Ingrese uno nuevamente:  ");
                CantRechazados++;
                cant1++;
            }
        }while(pos==-1&&codigo!=0);
        while(codigo!=0){
                cant1++;
                printf("\nPara modificar precio, presione '1'\nPara modificar descripcion, presione '2'\nPara finalizar, presione '3'\nSeleccione una opcion:  ");
                modificar=LeerYValidar(1,2,3);
                while(modificar!=3){
                    if(modificar==1){
                        printf("Igrese nuevo precio:  ");
                        do{
                            scanf("%f", &prec);
                            if(prec<0){
                                printf("Dato ingresado no valido. Ingrese uno nuevamente:  ");
                            }
                        }while(prec<0);
                        vProductos[pos].preciop=prec;
                    }
                    else if(modificar==2){
                        printf("Ingrese nueva descripcion:  ");
                        fflush(stdin);
                        fgets(descrip,51,stdin);
                        descrip[strlen(descrip)-1]='\0';
                        strcpy(vProductos[pos].descripcion,descrip);
                    }
                    printf("\nPara modificar precio, presione '1'\nPara modificar descripcion, presione '2'\nPara finalizar, presione '3'\nSeleccione una opcion:  ");
                    modificar=LeerYValidar(1,2,3);
                }
                printf("\nIngrese codigo de producto (0 para terminar):  ");
                do{
                    codigo=LeerYValidar(100,1000,0);
                    pos=Buscar(vProductos,codigo,CantIngresados);
                    if(pos==-1&&codigo!=0){
                        printf("Codigo inexistente. Ingrese uno nuevamente:  ");
                        CantRechazados++;
                        cant1++;
                    }
                }while(pos==-1&&codigo!=0);
        }
        //CODIGOS MODIFICADOS
        printf("\n\n<<INFORMACION DE PRODUCTOS MODIFICADOS>>");
        for(i=0;i<CantIngresados;i++){
            printf("\nCODIGO: %d DESCRIPCION: %s PRECIO: %.2f", vProductos[i].codp,vProductos[i].descripcion,vProductos[i].preciop);
        }
        //PORCENTAJE DE CODIGOS RECHAZADOS
        porcCodigos=(float)CantRechazados/cant1*100;
        printf("\n\nPorcentaje de codigos rechazados:  %.2f%%\n\n", porcCodigos);
    }
    return 0;
}
int Buscar (SProductos vp[], int dato, int ce){
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(vp[i].codp==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}
int LeerYValidar (int min, int max, int ex){
    int aux;
    do{
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
            printf("Dato ingresado no valido. Ingrese uno nuevamente:  ");
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}

int IngresarProductos (SProductos vp[], int ce)
{
    int i=0, codigo, pos;
    float prec;
    char descrip[51];
    printf("\n\n>>CARGA PARCIAL DE PRODUCTOS<<\n");
    printf("\nIngrese codigo de producto (0 para finalizar):  ");
    do{
        codigo=LeerYValidar(100,1000,0);
        pos=Buscar(vp,codigo,i);
        if(pos!=-1&&codigo!=0)
            printf("Codigo Repetido. Ingrese uno nuevamente:  ");
    }while(pos!=-1&&codigo!=0);
    while(codigo!=0&&i<ce){
        vp[i].codp=codigo;
        printf("Ingrese precio del producto:  ");
        do{
            scanf("%f", &prec);
            if(prec<1)
                printf("Precio ingresado no valido. Ingrese uno nuevamente:  ");
        }while(prec<1);
        vp[i].preciop=prec;
        printf("Ingrese descripcion del producto:  ");
        fflush(stdin);
        fgets(descrip,51,stdin);
        descrip[strlen(descrip)-1]='\0';
        strcpy(vp[i].descripcion,descrip);
        i++;
        if(i<ce){
            printf("\nIngrese codigo de producto (0 para finalizar):  ");
            do{
                codigo=LeerYValidar(100,1000,0);
                pos=Buscar(vp,codigo,i);
                if(pos!=-1&&codigo!=0)
                    printf("Codigo Repetido. Ingrese uno nuevamente:  ");
            }while(pos!=-1&&codigo!=0);
        }
    }

 return i;
}
