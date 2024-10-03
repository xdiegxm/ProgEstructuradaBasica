/*Una empresa de colectivos posee cerca de 400 unidades distribuidas en 3 tipos.

Por cada unidad se ingresa un unico vector:
.Numero de unidad (1 a 999 no correlativo sin repetidos)(ingresado y validado por funcion)
.Tipo de linea a la que pertenece ("Municipal", "Provincial", "Nacional")(Ingresar sin validad)
.Kilometros recorridos (mayor a cero)
.Fecha ultima actualizacion (dia mes año - en unico campo)

La fecha es un dato fijo correspondiente a la fecha actual 16/5/2024

La carga concluye con una unidad numero 0.

Seguidamente se cargan las planillas de control diarias del mes de abril que contienen:
.Dia (1 a 30)(Ingresar y validar rango por funcion)
.Numero de unidad (1 a 999). Ingresar y validar rango por funcion
.Kilometros recorridos (mayor a cero)

Las planillas vienen desordenadas y la carga termina con un dia 0.
Si el numero de unidad no existe se informa y se descarta la planilla sin ingresar Kms.

Se pide:

1)Actualizar los kms recorridos de cada unidad ingresada.

2)Listar por cada unidad de tipo de linea Nacional su numero y los kms recorridos cada dia.

3)Copiar los datos actualizados a otro vector que contenga una estructura de dos campos siendo uno de ellos todos los datos del vector copiado y otro el nombre del operador de maximo 30 caracteres que se ingreaa previamente por teclado (sin validar).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 400
typedef struct
{
    int dia;
    int mes;
    int anio;
}SFecha;
typedef struct
{
    int nunidad;
    char TLinea[31];
    int kms;
    SFecha fecha;
}SColectivos;
typedef struct
{
    SColectivos Tunidad;
    char operador[31];
}SCopia;
int IngresarColectivos (SColectivos [], int);
int Buscar (SColectivos [], int, int);
int LeerYValidar (int, int, int);
int main()
{
    SColectivos vColectivos[TAM];
    SCopia vCopia[TAM];
    int CantIngresados, dia, unidad, kilometros, pos, i;
    char op[31];
    CantIngresados=IngresarColectivos(vColectivos,TAM);
    if(CantIngresados>0){
        printf("\n\n\t\t>>PLANILLAS INGRESADAS<<");
        printf("\n%16s %15s %23s","Numero de unidad", "  Tipo de Linea", "  Kilometros recorridos");
        for(i=0;i<CantIngresados;i++){
            printf("\n%16d %15s %23d", vColectivos[i].nunidad, vColectivos[i].TLinea, vColectivos[i].kms);
        }
        printf("\n\n\t>>CARGA DE PLANILLAS DIARIAS MES DE ABRIL<<");
        printf("\n\nIngrese dia (1 a 30 o 0 para terminar):  ");
        dia=LeerYValidar(1,30,0);
        while(dia!=0){
            printf("Ingrese numero de unidad (1 a 999):  ");
            do{
                unidad=LeerYValidar(1,999,-1);
                pos=Buscar(vColectivos,unidad,CantIngresados);
                if(pos==-1)
                    printf("Dato repetido. Ingrese uno nuevamente:  ");
            }while(pos==-1);
            printf("Ingrese kilometros recorridos:  ");
            do{
                scanf("%d", &kilometros);
                if(kilometros<0)
                    printf("Dato incorrecto. Ingrese uno nuevamente:  ");
            }while(kilometros<0);
            //a.Actualizar los kms recorridos de cada unidad ingresada.
            vColectivos[pos].kms=kilometros;
            //b.Listar por cada unidad de tipo de linea Nacional su numero y los kms recorridos cada dia.
            if(strcmpi(vColectivos[pos].TLinea,"Nacional")==0){
                printf("%13s %18s %15s %5s","Tipo de Linea","  Numero de unidad","  Kilometros","  Dia");
                printf("\n%13s %18d %15d %5d", vColectivos[pos].TLinea, vColectivos[pos].nunidad, vColectivos[pos].kms, dia);
            }
            printf("\n\nIngrese dia (1 a 30 o 0 para terminar):  ");
            dia=LeerYValidar(1,30,0);
        }
        //c.Copiar los datos actualizados a otro vector que contenga una estructura de dos campos siendo uno de ellos todos los datos del vector copiado y otro el nombre del operador de maximo 30 caracteres que se ingreaa previamente por teclado (sin validar).
        printf("\nIngrese nombre del operador:  ");
        fflush(stdin);
        fgets(op,31,stdin);
        op[strlen(op)-1]='\0';
        for(i=0;i<CantIngresados;i++){
            vCopia[i].Tunidad=vColectivos[i];
            strcpy(vCopia[i].operador,op);
        }
    }
    return 0;
}
int IngresarColectivos (SColectivos vc[], int ce)
{
    int unidad, d, m, a, i=0, kilometros, pos;
    char linea[31];
    printf("\t\t>>CARGA PARCIAL DE UNIDADES<<\n");
    printf("\nIngrese numero de unidad (1 a 999 o 0 para terminar):  ");
    do{
        unidad=LeerYValidar(1,999,0);
        pos=Buscar(vc,unidad,i);
        if(pos!=-1&&unidad!=0)
            printf("Dato repetido. Ingrese uno nuevamente:  ");
    }while(pos!=-1&&unidad!=0);
    while(unidad!=0&&i<ce){
        vc[i].nunidad=unidad;
        printf("Ingrese tipo de linea ('Municipal' 'Provincial' 'Nacional'):  ");
        fflush(stdin);
        fgets(linea,31,stdin);
        linea[strlen(linea)-1]='\0';
        strcpy(vc[i].TLinea,linea);
        printf("Ingrese kilometros recorridos:  ");
        do{
            scanf("%d", &kilometros);
            if(kilometros<0)
                printf("Dato ingresado no valido. Ingrese uno nuevamente:  ");
        }while(kilometros<0);
        vc[i].kms=kilometros;
        vc[i].fecha.dia=16;
        vc[i].fecha.mes=5;
        vc[i].fecha.anio=2024;
        i++;
        if(i<ce){
            printf("\nIngrese numero de unidad (1 a 999 o 0 para terminar):  ");
            do{
                unidad=LeerYValidar(1,999,0);
                pos=Buscar(vc,unidad,i);
                if(pos!=-1&&unidad!=0)
                    printf("Dato repetido. Ingrese uno nuevamente:  ");
            }while(pos!=-1&&unidad!=0);
        }
    }
    return i;
}
int Buscar (SColectivos vc[], int dato, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(vc[i].nunidad==dato)
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
            printf("Dato ingresado no valido. Ingrese uno nuevamente:  ");
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}




