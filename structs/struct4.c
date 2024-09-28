/*4.4 Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE NOMBRE Y APELLIDO TOTAL FACTURADO
X XXXXX XXXXXXXX $ XXXXXXXXX,XX*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
typedef struct
{
    int codc;
    char nya[51];
}SCliente;
int IngresarClientes (SCliente [], int);
int LeerYValidar (int, int, int);
int Buscar (SCliente [], int, int);
void Ordenar (SCliente [], float [], int);
int main()
{
    SCliente vClientes[TAM];
    int ClientesCargados, i, codcliente, pos, VentasPCliente[TAM]={0}, vVendedores[10]={0}, vendedor;
    float imp, vImportePCliente[TAM]={0};
    ClientesCargados=IngresarClientes(vClientes,TAM);
    if(ClientesCargados>0){
    printf("\n\t\t>>CLIENTES CARGADOS<<");
    for(i=0;i<ClientesCargados;i++){
        printf("\nCODIGO DE CLIENTE: %d NOMBRE Y APELLIDO: %s", vClientes[i].codc, vClientes[i].nya);
    }
    printf("\n\n\t\t>>INGRESO DE VENTAS<<");
    printf("\nIngrese numero de cliente (999 para terminar):  ");
    do{
        codcliente=LeerYValidar(1000,9999,999);
        pos=Buscar(vClientes,codcliente,ClientesCargados);
        if(pos==-1&&codcliente!=999)
            printf("Codigo ingresado inexistente. Ingrese uno nuevamente:  ");
    }while(pos==-1&&codcliente!=999);
    while(codcliente!=999){
        printf("Ingrese importe a cobrar:  ");
        do{
            scanf("%f", &imp);
            if(imp<=0)
                printf("Ingrese un importe valido:  ");
        }while(imp<=0);
        printf("Ingrese numero de vendedor:  ");
        do{
            scanf("%d", &vendedor);
            if(vendedor<1||vendedor>10)
                printf("Numero de vendedor no valido. Ingrese uno nuevamente:  ");
        }while(vendedor<1||vendedor>10);
        VentasPCliente[pos]++;
        vImportePCliente[pos]+=imp;
        vVendedores[vendedor-1]++;
        printf("\nIngrese numero de cliente (999 para terminar):  ");
        do{
            codcliente=LeerYValidar(1000,9999,999);
            pos=Buscar(vClientes,codcliente,ClientesCargados);
            if(pos==-1&&codcliente!=999)
                printf("Codigo ingresado inexistente. Ingrese uno nuevamente:  ");
        }while(pos==-1&&codcliente!=999);
    }
    //VENTAS REALIZADAS POR CLIENTE:
    printf("\n\n\t>>VENTAS REALIZADAS POR CLIENTE<<");
    for(i=0;i<ClientesCargados;i++){
            printf("\nNOMBRE DEL CLIENTE: %s VENTAS REALIZADAS: %d", vClientes[i].nya,VentasPCliente[i]);
    }
    //VENTAS REALIZADAS POR VENDEDOR
    printf("\n\n\t>>VENTAS REALIZADAS POR VENDEDOR<<");
    for(i=0;i<10;i++){
        printf("\nVENDEDOR: %d VENTAS REALIZADAS: %d", i+1, vVendedores[i]);
    }
    //TOTAL FACTURADO A CADA CLIENTE DE FORMA ORDENADA
    Ordenar(vClientes,vImportePCliente,ClientesCargados);
    printf("\n\n>>TOTAL FACTURADO A CADA CLIENTE EN FORMA ORDENADA<<");
    printf("\n\n%17s %17s %16s", "CODIGO DE CLIENTE", " NOMBRE Y APELLIDO", " TOTAL FACTURADO");
    for(i=0;i<ClientesCargados;i++){
        printf("\n%17d %18s %16.2f", vClientes[i].codc,vClientes[i].nya, vImportePCliente[i]);
    }
    }
    printf("\n\n\n");
    return 0;
}
int IngresarClientes (SCliente vc[], int ce)
{
    int i=0, pos, nroc;
    char nombreyap[51];
    printf("\n>>CARGA PARCIAL DE CLIENTES<<\n");
    printf("\nIngrese codigo de cliente (999 para finalizar):  ");
    do{
        nroc=LeerYValidar(1000,9999,999);
        pos=Buscar(vc,nroc,i);
        if(pos!=-1)
            printf("Dato repetido. Ingrese uno nuevamente:  ");
    }while(pos!=-1);
    while(nroc!=999&i<ce){
        vc[i].codc=nroc;
        printf("Ingrese nombre y apellido del cliente:  ");
        fflush(stdin);
        fgets(nombreyap,51,stdin);
        nombreyap[strlen(nombreyap)-1]='\0';
        strcpy(vc[i].nya,nombreyap);
        i++;
        if(i<ce){
            printf("\nIngrese codigo de cliente (999 para finalizar):  ");
            do{
                nroc=LeerYValidar(1000,9999,999);
                pos=Buscar(vc,nroc,i);
                if(pos!=-1)
                    printf("Dato repetido. Ingrese uno nuevamente:  ");
            }while(pos!=-1);
        }
    }
    return i;
}
int LeerYValidar (int min, int max, int ex)
{
    int aux;
    do{
        scanf("%d", &aux);
        if((aux<min||aux>max)&&aux!=ex)
            printf("Dato incorrecto. Ingrese uno nuevamente:  ");
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}
int Buscar (SCliente vc[], int buscado, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(vc[i].codc==buscado)
            pos=i;
        else
            i++;
    }
    return pos;
}
void Ordenar (SCliente vc[], float vipc[], int ce)
{
    int i, j, aux;
    SCliente aux2;
    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(vipc[j]<vipc[j+1]){
                aux=vipc[j];
                vipc[j]=vipc[j+1];
                vipc[j+1]=aux;

                aux2=vc[j];
                vc[j]=vc[j+1];
                vc[j+1]=aux2;
            }
        }
    }
}








