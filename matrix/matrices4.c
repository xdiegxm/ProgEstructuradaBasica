/*2.4 La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo
el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia,
tours y la cantidad de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un
tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
• Código de agencia (de 1 a 15)
• Código de tour (1 a 10)
• Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour en cada agencia.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse)*/
#include <stdio.h>
int LeerYValidar (int, int);
int main()
{
    int mat[15][10]={{0}}, agencia, codtour, cantpasaje, j, max, i, ppa, vAgencia[15]={0};
    printf("\nIngrese numero de agencia ( 1 a 15 o 0 para terminar ):\n");
    agencia=LeerYValidar(0,15);
    while(agencia!=0)
    {
        printf("\nIngrese el codigo de tour:\n");
        codtour=LeerYValidar(1,10);
        printf("\nIngrese cantidad de pasajes:\n");
        cantpasaje=LeerYValidar(0,20);

        mat[agencia-1][codtour-1]+=cantpasaje;
        printf("\nIngrese numero de agencia ( 1 a 15 o 0 para terminar ):\n");
        agencia=LeerYValidar(0,15);
    }
    printf("\nTOTAL DE PASAJES VENDIDOS POR TOUR EN CADA AGENCIA\n\n");
    for(j=0;j<10;j++)
    {
        ppa=0;
        for(i=0;i<15;i++)
        {
            ppa+=mat[i][j];
        }
        printf("Tour: %d\t Cantidad de pasajes: %d\n", j+1,ppa);
    }

    for(i=0;i<15;i++)
    {
        for(j=0;j<10;j++)
        {
            vAgencia[i]+=mat[i][j];
        }
    }
    for(i=0;i<15;i++)
    {
        if(i==0||vAgencia[i]>max)
        {
            max=vAgencia[i];
        }
    }
    printf("\nLas agencias con mayor numero de tours vendidos son:\n\n");
    for(i=0;i<15;i++)
    {
        if(vAgencia[i]==max)
        {
            printf("%d\n", i+1);
        }
    }

    return 0;
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
