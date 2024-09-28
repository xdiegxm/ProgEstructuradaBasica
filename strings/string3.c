/*3.3 Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int IngresarAlumnos (int [], char [][100], int);
int Buscar (char [][100], char [100], int);
void Ordenar (char [][100], int [], int);
int main()
{
    int vDNI[50], cantAlumnos, pos, i;
    char mAlumnos[50][100], vNOMBRES[100];
    cantAlumnos=IngresarAlumnos(vDNI,mAlumnos,50);
    printf("\n\nBUSCAR ALUMNOS...\n\n");
    printf("\nIngrese nombre del alumno a buscar (NOBUSCARMAS para terminar):  ");
    fgets(vNOMBRES,100,stdin);
    vNOMBRES[strlen(vNOMBRES)-1]='\0';
    while(strcmpi(vNOMBRES,"NOBUSCARMAS")!=0){
        pos=Buscar(mAlumnos,vNOMBRES,cantAlumnos);
        if(pos==-1)
            printf("\nNO SE ENCONTRO AL ALUMNO...\n");
        else
            printf("\nAlumno: %s DNI: %d", vNOMBRES,vDNI[pos]);
        printf("\n");
        printf("\nIngrese nombre del alumno a buscar (NOBUSCARMAS para terminar):  ");
        getchar();
        fgets(vNOMBRES,100,stdin);
        vNOMBRES[strlen(vNOMBRES)-1]='\0';
    }
    printf("\nLISTADO DE ALUMNOS DE MENOR A MAYOR\n");
    Ordenar(mAlumnos,vDNI,cantAlumnos);
    for(i=0;i<cantAlumnos;i++){
        printf("Alumno: %s  DNI: %d\n", mAlumnos[i], vDNI[i]);
    }
    return 0;
}
int IngresarAlumnos (int vdni[50], char alumno[50][100], int ce){
    int i=0, dni;
    char nombre[100];
    printf("\nIngrese nombre del alumno (FIN para terminar): ");
    fgets(nombre,100,stdin);
    nombre[strlen(nombre)-1]='\0';
    while(i<ce&&strcmpi(nombre,"FIN")!=0){
        strcpy(alumno[i],nombre);
        printf("\nIngrese DNI del alumno:  ");
        scanf("%d", &dni);
        vdni[i]=dni;
        printf("\nIngrese nombre del alumno (FIN para terminar): ");
        getchar();
        fgets(nombre,100,stdin);
        nombre[strlen(nombre)-1]='\0';
        i++;
    }
    return i;
}
int Buscar (char m[50][100], char v[100], int ce){
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(strcmpi(m[i],v)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}
void Ordenar (char m[][100], int v[], int ce){
    int i, j, auxv;
    char auxm[100];
    for(i=0;i<ce-1;i++){
        for(j=0;j<ce-1-i;j++){
            if(strcmpi(m[j],m[j+1])>0){
                strcpy(auxm,m[j]);
                strcpy(m[j],m[j+1]);
                strcpy(m[j+1],auxm);

                auxv=v[j];
                v[j]=v[j+1];
                v[j+1]=auxv;
            }
        }
    }
}
