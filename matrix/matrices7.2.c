/*2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por códigos numéricos de 3 cifras. Como primera información se ingresa el
precio unitario de cada uno de los productos y su código. Luego por cada venta se ingresa:
• Código de producto
Guía Práctica – V2.0 3 / 4
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año*/
#include <stdio.h>
int LeerYValidar (int, int);
int LeerYValidarConEx (int, int, int);
int Buscar (int [], int, int);
void IngrCod (int [], float[]);
int main()
{
    int mat[20][12]={{0}}, codigo[20]={0}, i, j, codprod, pos, dia, mes, cuv;
    float precio[20]={0}, rec[20][12]={0}, max=-1,suma;
    IngrCod();
    printf("\nCODIGO\t\tPRECIO\n\n");
    for(i=0;i<20;i++)
    {
        printf("%d\t\t$%.2f\n",codigo[i], precio[i]);
    }
    printf("\n\tREGISTRO DE VENTAS\n\n");
    printf("\nIngrese codigo de producto ( 3 cifras o 0 para terminar ): \n");
    codprod=LeerYValidarConEx(100,999,0);
    while(codprod!=0)
    {
        pos=Buscar(codigo,codprod,20);
        if(pos!=-1)
        {
            printf("\nIngrese dia de venta ( 1 a 31 ):  ");
            dia=LeerYValidar(1,31);
            printf("\nIngrese mes de venta ( 1 a 12 ):  ");
            mes=LeerYValidar(1,12);
            printf("\nIngrese cantidad de unidades vendidas:  ");
            scanf("%d", &cuv);
            mat[pos][mes-1]+=cuv;
            rec[pos][mes-1]+=precio[pos]*cuv;
        }
        else
        {
            printf("\nCodigo no encontrado.");
        }
        printf("\nIngrese codigo de producto ( 3 cifras o 0 para terminar ): \n");
        codprod=LeerYValidarConEx(100,999,0);
    }

    /*a.El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.*/
    printf("\n\t\t\tUNIDADES VENDIDAS DE CADA PRODUCTO POR CADA MES\n\n");
    printf("CODIGO\t");
    for(i=0;i<12;i++)
    {
        printf("MES %d\t", i+1);
    }
    printf("\n");
    for(i=0;i<20;i++)
    {
        printf("%d\t", codigo[i]);
        for(j=0;j<12;j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    /*b.El producto con el cual se obtuvo la mayor recaudación.*/
    for(i=0;i<20;i++)
    {
        suma=0;
        for(j=0;j<12;j++)
        {
            suma+=rec[i][j];
        }
        if(suma>max)
        {
            max=suma;
            pos=i;
        }
    }
    printf("\nEl producto con mayor recaudacio fue el codigo %d\n", codigo[pos]);
    printf("Recaudacion:  $%2.f", max);

    /*El c me da paja hacerlo pero es como
    void lessearning(float Mrecaudacion[][12]){
    int i, j, trimestre,  minTrimestre, start =0;
    float min, suma;
    for(trimestre = 0; trimestre < 4; trimestre++){
        suma = 0;
        for(i = 0; i < 20; i++){
            for(j = start; j < start +3; j++){
                suma += Mrecaudacion[i][j];
            }
        }
        if(suma < min || trimestre == 0){
            min = suma;
            minTrimestre = trimestre;
        }
        start += 3;
    }
    printf("\nTrimestre con menor recaudacion:  %d", minTrimestre+1);
    printf("\nRecaudacion: %.2f", min);*/


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
int LeerYValidarConEx (int min, int max, int ex)
{
     int aux;
    do
    {
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
        {
            printf("\nIncorrecto. Ingrese un dato valido:\n");
        }
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}

int Buscar (int v[], int dato, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1)
    {
        if(v[i]==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}
void IngrCod (int cod[], float p[])
{
    int i, pos, codigo;
    float precio;
    for(i=0;i<20;i++)
    {
        printf("\nIngrese codigo de producto:  ");
        do
        {
            codigo=LeerYValidar(100,999);
            pos=Buscar(cod,codigo,i);
            if(pos!=-1)
            {
                printf("Dato repetido, ingrese uno nuevamente:\n");
            }
        }while(pos!=-1);
        cod[i]=codigo;
        printf("\nIngrese precio:  ");
        scanf("%f", &precio);
        p[i]=precio;
    }
}

