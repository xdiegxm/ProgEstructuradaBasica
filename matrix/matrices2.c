/*2.2 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector.*/
#include <stdio.h>
void SumaPorFilas (int [][4], int [], int, int);
void SumaPorColumnas (int [][4], int [], int, int);
int main()
{
    int mat[5][4]={(0)}, i, j, vf[5], vc[4];
    printf("\nIngrese una matriz 5x4: \n");

    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Fila %d Columna %d:\n", i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }
    SumaPorFilas(mat,vf,5,4);
    SumaPorColumnas(mat,vc,5,4);

    printf("\nSuma total por filas:\n\n");
    for(i=0;i<5;i++)
    {
        printf("Fila %d: %d\n", i+1, vf[i]);
    }

    printf("\nSuma total por columnas:\n\n");
    for(i=0;i<5;i++)
    {
        printf("Columna %d: %d\n", i+1, vc[i]);
    }
    return 0;
}
void SumaPorFilas (int m[][4], int v[],int cf, int cc)
{
    int i, j, suma;
    for(i=0;i<cf;i++)
    {
        suma=0;
        for(j=0;j<cc;j++)
        {
            suma+=m[i][j];
        }
        v[i]=suma;
    }
}
void SumaPorColumnas (int m[][4], int v[], int cf, int cc)
{
    int i, j, suma;
    for(j=0;j<cc;j++)
    {
       v[j]=0;
        for(i=0;i<cf;i++)
        {
            v[j]+=m[i][j];
        }

    }

}

