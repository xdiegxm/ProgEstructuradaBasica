/*2.3 Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor
almacenado en la matriz indicando cuantas veces se repite y en que posiciones.
*/
#include <stdio.h>
#include <time.h>
int ValorMinimo (int [][8], int, int);
int main()
{
    int mat[5][8]={(0)}, i, j, min, cont=0;
    srand((NULL));

    for(i=0;i<5;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("Ingrese un valor para fila %d columna %d: \n", i+1,j+1);
            mat[i][j]=rand()%90+10;
            printf("%d\n", mat[i][j]);
        }
    }
    min=ValorMinimo(mat,5,8);

    printf("\nEl valor minimo es %d y se encuentra en las siguientes posiciones: \n", min);
    for(i=0;i<5;i++)
    {
        for(j=0;j<8;j++)
        {
            if(mat[i][j]==min)
            {
                printf("Fila %d Columna %d\n", i+1, j+1);
                cont++;
            }
        }
    }
    printf("\nEl valor minimo se repite %d veces.\n\n", cont);
    return 0;
}
int ValorMinimo (int mat[][8], int cf, int cc)
{
    int i, j, min=mat[0][0];
    for(i=0;i<cf;i++)
    {
        for(j=0;j<cc;j++)
        {
            if(mat[i][j]<min)
                min=mat[i][j];
        }
    }
    return min;
}