/*2.1 Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante.*/
#include <stdio.h>

int main()
{
    int mat[3][3]={(0)}, i, j, num;
    printf("\nIngrese valores de la matriz 3x3: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Fila %d Columna %d: \n",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\nIngrese una constante para multiplicar:\n");
    scanf("%d",&num);

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            mat[i][j]=mat[i][j]*num;
        }
    }

    printf("\n     Matriz Resultante\n\n");
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("%7d\t", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
