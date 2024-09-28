/*4.2 Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1
typedef struct
{
    int codm;
    float precio;
    int stock;
}SMedicamentos;
int IngresarMedicamentos (SMedicamentos [], int);
int LeerYValidar(int, int);
int Buscar (SMedicamentos [], int, int);
int main()
{
    SMedicamentos vMedicamentos[50];
    int codmed, pos, i;
    char ingreso;
    IngresarMedicamentos(vMedicamentos,TAM);
    printf("\n\n--CONSULTAR MEDICAMENTO--\n");
    printf("\n>>Bienvenido/a, ingrese 'C' para consultar o 'N' para terminar<<");
    printf("\nIngreso:  ");
    scanf("%s", &ingreso);
    ingreso=toupper(ingreso);
    while(ingreso=='C'&&ingreso!='N'){
        printf("\nIngrese codigo de medicamento a consultar:  ");
        do{
            scanf("%d", &codmed);
            pos=Buscar(vMedicamentos,TAM,codmed);
            if(pos==-1)
                printf("\nCodigo de medicamento inexistente. Ingrese uno nuevamente:  ");
            else
                printf("\nPrecio: $%.2f\n", vMedicamentos[pos].precio);
        }while(pos==-1);
        printf("\n>>Si desea consultar otro medicamento ingrese 'C', de lo contrario, presione 'N'<<");
        printf("\nIngreso:  ");
        getchar();
        scanf("%s", &ingreso);
        ingreso=toupper(ingreso);
    }
    printf("\n\n--MEDICAMENTOS CUYO STOCK ES MENOR A 10 UNIDADES--\n\n");
    printf("%9s %6s","   CODIGO", " STOCK");
    for(i=0;i<TAM;i++){
        if(vMedicamentos[i].stock<10)
            printf("\n%9d %6d", vMedicamentos[i].codm, vMedicamentos[i].stock);
    }
    return 0;
}
int IngresarMedicamentos (SMedicamentos vm[], int ce)
{
    int i, codigo, cantidad, pos;
    float prec;
    printf("\n--CARGAR PARCIAL DE MEDICAMENTOS--\n");
    for(i=0;i<ce;i++)
    {
        printf("\nIngrese codigo del medicamento %d:  ", i+1);
        do{
            codigo=LeerYValidar(100,999);
            pos=Buscar(vm,i,codigo);
            if(pos!=-1){
                printf("\nCodigo repetido. Ingrese uno nuevamente:  ");
            }
        }while(pos!=-1);
        vm[i].codm=codigo;
        printf("\nIngrese precio del medicamento:  ");
        scanf("%f", &prec);
        vm[i].precio=prec;
        printf("\nIngrese stock del medicamento:  ");
        scanf("%d", &cantidad);
        vm[i].stock=cantidad;
    }
}
int LeerYValidar(int min, int max)
{
    int aux;
    do{
        scanf("%d", &aux);
        if(aux<min||aux>max){
            printf("\nDato incorrecto. Ingrese uno nuevamente:  ");
        }
    }while(aux<min||aux>max);
    return aux;
}
int Buscar (SMedicamentos prod[], int ce, int dato)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(prod[i].codm==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}

