/*Como resultado de un proceso eleccionario, se cuenta con los resultados finales de cada una de las mesas que participaron en las elecciones. Al finalizar el recuento de la cantidad de votos de cada mesa, se nos entrega una planilla con los siguientes datos:

              -        Numero de Provincia (de 1 a 23)

              -        Numero de Lista (de 1 a 15)

              -        Cantidad de Votos (int)

Dichos datos, se ingresarán por teclado en forma desordenada, almacenándose en una matriz, hasta la lectura de un número de provincia 0 (cero).  Los números de provincia y de lista, se deben validar en forma separada a través de una única función con parámetros.     Confeccionar la codificación en lenguaje “C” para:

a) Informar el/los Número/s de Provincia y Número/s de Lista que finalizaron con menor cantidad de votos, distinto de cero. Mostrar la menor cantidad de votos en una oportunidad y todas las combinaciones (prov/lista) que finalizaron con cantidades de votos iguales al mínimo.

b) Informar las cantidades totales de votos por provincia.

c) Informar el número de lista ganadora (el mayor es único)

d) Mostrar la cantidad de votos de la lista número 12 ordenados de mayor a menor. Se debe visualizar el número de provincia y la cantidad de votos. Para el ordenamiento utilizar una función con parámetros. Por ej. mostraría:

                                      Lista Numero 12

                              Provincia    Cantidad de votos

                                      5               98531

                                    21               67574

                                      8               43891

                                     ..                      ….

                                    20                 7523*/
#include <stdio.h>
#define LISTA 15
#define PROVINCIA 23
int LeerYValidar (int, int, int);
void Ordenar (int [], int [], int);
int main()
{
    int mVotos[PROVINCIA][LISTA]={{0}}, prov, list, cantv, i, j, min=-1, vCantVotosProvincia[PROVINCIA]={0}, vCantVotosLista[LISTA]={0}, listaganadora, max=0, vNProvincia[PROVINCIA]={0}, vCantVotosL12[PROVINCIA]={0};
    printf(">>INGRESO DE RESULTADOS FINALES DE LAS ELECCIONES<<\n");
    printf("\nIngrese numero provincia (0 para terminar):  ");
    prov=LeerYValidar(1,23,0);
    while(prov!=0){
        printf("Ingrese numero de lista:  ");
        list=LeerYValidar(1,15,-1);
        printf("Ingrese cantidad de votos:  ");
        do{
            scanf("%d", &cantv);
            if(cantv<0)
                printf("Dato ingresado no valido. Ingrese uno nuevamente:  ");
        }while(cantv<0);
        mVotos[prov-1][list-1]+=cantv;
        vCantVotosProvincia[prov-1]+=cantv;
        vCantVotosLista[list-1]+=cantv;
        printf("\nIngrese numero provincia (0 para terminar):  ");
        prov=LeerYValidar(1,23,0);
    }

    //a.Informar el/los Número/s de Provincia y Número/s de Lista que finalizaron con menor cantidad de votos, distinto de cero.
    //Mostrar la menor cantidad de votos en una oportunidad y todas las combinaciones (prov/lista) que finalizaron con cantidades de votos iguales al mínimo.
    for(i=0;i<PROVINCIA;i++){
        for(j=0;j<LISTA;j++){
            if(mVotos[i][j]>0){
                if(min==-1||mVotos<min){
                    min=mVotos[i][j];
                }
            }
        }
    }
    if(min>0){
    printf("\n\nMenor cantidad de votos:  %d", min);
    printf("\nProvincia/s y Lista/s con esta cantidad de votos");
    for(i=0;i<PROVINCIA;i++){
        for(j=0;j<LISTA;j++){
            if(mVotos[i][j]==min){
                printf("\nPROVINCIA: %d LISTA: %d", i+1, j+1);
            }
        }
    }
    }
    else
        printf("\nNo se registraron votos.");
    //b.Informar las cantidades totales de votos por provincia
    printf("\n\n<<CANTIDAD TOTAL DE VOTOS POR PROVINCIA>>");
    for(i=0;i<PROVINCIA;i++){
        printf("\nPROVINCIA %d:  %d", i+1, vCantVotosProvincia[i]);
    }
    //c. Informar el número de lista ganadora (el mayor es único)
    for(i=0;i<LISTA;i++){
        if(vCantVotosLista[i]>max){
            max=vCantVotosLista[i];
            listaganadora=i;
        }
    }
    if(max>0){
    printf("\n\nLISTA GANADORA:  %d\nCANTIDAD DE VOTOS:  %d", listaganadora+1, max);
    }
    //d.Mostrar la cantidad de votos de la lista número 12 ordenados de mayor a menor. Se debe visualizar el número de provincia y la cantidad de votos
    //Para el ordenamiento utilizar una función con parámetros.
    printf("\n\n<<CANTIDAD DE VOTOS DE LA LISTA NUMERO 12 ORDENADOS DE MAYOR A MENOR>>\n");
    for(i=0;i<PROVINCIA;i++){
        vNProvincia[i]=i+1;
        vCantVotosL12[i]=mVotos[i][11];
    }
    Ordenar(vCantVotosL12,vNProvincia,PROVINCIA);
    printf("\n\nLISTA NUMERO 12");
    printf("\n%9s %5s","PROVINCIA","VOTOS");
    for(i=0;i<PROVINCIA;i++){
        printf("\n%9d %5d", vNProvincia[i], vCantVotosL12[i]);
    }
    return 0;
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
void Ordenar (int v1[], int v2[], int ce)
{
    int i, j, aux1, aux2;
    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(v1[j]<v1[j+1]){
                aux1=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=aux1;

                aux2=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=aux2;
            }
        }
    }
}




