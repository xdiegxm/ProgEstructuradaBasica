/*3.5 Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número de
patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el procesamiento de
los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación, se ingresan los
siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
a. El porcentaje de autos alquilados durante el día.
b. Realizar el informe con el formato siguiente:
ALQUILER DE AUTOS DEL DÍA: DD-MM-AAAA
COTIZACION DEL DÓLAR: $ XX,XX
NRO. DE AUTO DIAS DE ALQUILER PRECIO DEL ALQUILER
EN PESOS
FECHA DE DEVOLUCION
DEL AUTO
XXXXX XX XXXX,XX XX/XX/XXXX
XXXXX XX XXXX,XX XX/XX/XXXX
TOTAL RECAUDADO X ALQUILER (EN PESOS)
$ XXXXX,
TOTAL RECAUDADO X ALQUILER (EN DÓLARES)
$ XXXXX,XX*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NPatentes 2
void CargarPatentes (char [][7], int);
int Buscar (char [][7], char [], int);
int LeerYValidar (int, int);
int main()
{
    char mPatentes[NPatentes][7], vPatente[7]={0};
    int dia, mes, anio, i, pos, cantdias;
    float precioendolares;
    CargarPatentes(mPatentes,NPatentes);
    printf("\nPATENTES CARGADAS\n");
    for(i=0;i<NPatentes;i++){
        printf("%s", mPatentes[i]);
    }
    printf("\nCOMENZANDO PROCESAMIENTO DIARIO DE ALQUILERES...\n");
    printf("\nIngrese dia: ");
    dia=LeerYValidar(1,30);
    printf("\nIngrese mes: ");
    mes=LeerYValidar(1,12);
    printf("\nIngrese anio: ");
    anio=LeerYValidar(2024,2024);
    printf("\nIngrese patente (FINDIA para terminar):  ");
    do{
        getchar();
        fgets(vPatente,7,stdin);
        if(strcmpi(mPatentes,vPatente)!=0&&strcmpi(vPatente,"FINDIA")!=0){
            printf("\nPatente inexistente. Ingrese otra:  ");
        }
    }while(strcmpi(mPatentes,vPatente)!=0&&strcmpi(vPatente,"FINDIA")!=0);
    while(strcmpi(vPatente,"FINDIA")!=0){
        pos=Buscar(mPatentes,vPatente,NPatentes);
        printf("\nIngrese cantidad de dias de alquiler:  ");
        scanf("%d", &cantdias);
        printf("\nIngrese precio diario del alquier en dolares:  ");
        scanf("%f", &precioendolares);
    }
    return 0;
}
void CargarPatentes (char m[][7], int ce){
    int i=0, pos;
    char patentes[7];
    while(i<ce){
        printf("\nIngrese patente %d: ", i+1);
        do{
            getchar();
            fgets(patentes,7,stdin);
            pos=Buscar(m,patentes,i);
            if(strlen(patentes)!=6||pos!=-1){
                printf("\nPatente incorrecta. Ingrese una nuevamente: ");
            }
        }while(strlen(patentes)!=6||pos!=-1);
        strcpy(m[i],patentes);
        i++;
    }
}
int Buscar (char m[][7], char v[], int ce){
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(strcmpi(m[i],v)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}
int LeerYValidar (int min, int max){
    int aux;
    do{
        scanf("%d", &aux);
        if(aux<min||aux>max)
        {
            printf("\nIncorrecto. Ingrese un dato valido:  ");
        }
    }while(aux<min||aux>max);
    return aux;
}



