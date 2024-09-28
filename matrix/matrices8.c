/*2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO DPTO 1 DPTO2 … DPTO 15
PISO 1 X
PISO 2 X X
PISO 3 X
PISO 4 X X
PISO 5 X X*/
#include <stdio.h>
int LeerYValidar (int, int, int);
int LeerYValidar2 (int, int);
int main()
{
    char mat[5][15];
    int valexp=1000, piso, ndep, i, j, suma=0;
    for (i=0;i<5;i++)
    {
        for (j=0;j<15;j++)
        {
            mat[i][j]=' ';
        }
    }
    printf("\nCONTROL DE EXPENSAS INICIANDO...\n");
    printf("\nIngrese el numero de piso ( 1 a 5 o 99 para terminar ):  ");
    piso=LeerYValidar(1,5,99);
    while(piso!=99)
    {
        printf("\nIngrese numero de departamento ( 1 a 15 ):  ");
        ndep=LeerYValidar2(1,15);
        if(mat[piso-1][ndep-1]==' ')
        {
            mat[piso-1][ndep-1]='X';
            suma+=valexp;
            printf("\nINGRESO EXITOSO...\n");
        }
        else
        {
            printf("\nPAGADO. El departamento ya ha sido registrado como pagado previamente\n");
        }
        printf("\nIngrese el numero de piso ( 1 a 5 o 99 para terminar ):  ");
        piso=LeerYValidar(1,5,99);
    }

    /*a.Total recaudado.*/
    printf("\n\t\t\t\t\t\tTOTAL RECAUDADO:  $%d", suma);

    /*b.Tabla de departamentos deudores*/
    printf("\n\t\t\t\t\t\tDEPARTAMENTOS DEUDORES\n");
    printf("PISO\t");
    for(i=0;i<15;i++)
    {
        printf("DPTO %d\t", i+1);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("PISO %d\t", i+1);
        for(j=0;j<15;j++)
        {
            printf("%c\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int LeerYValidar (int min, int max, int ex)
{
    int aux;
        do
        {
            scanf("%d", &aux);
            if((aux<min||aux>max)&&aux!=ex)
            {
                printf("\nIncorrecto. Ingrese un dato valido:  ");
            }
        }while((aux<min||aux>max)&&aux!=ex);
        return aux;
}
int LeerYValidar2 (int min, int max)
{
    int aux;
        do
        {
            scanf("%d", &aux);
            if(aux<min||aux>max)
            {
                printf("\nIncorrecto. Ingrese un dato valido:  ");
            }
        }while(aux<min||aux>max);
        return aux;
}
