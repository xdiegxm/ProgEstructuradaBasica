/*4.3 Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 2
typedef struct
{
    int ndni;
    char ayn[81];
    int notas[2];
    float promedio;
}SAlumno;
int LeerYValidar (int, int, int);
int Buscar (SAlumno [], int, int);
int IngresarNotas (SAlumno [], int);
int main()
 {
    SAlumno vAlumnos[TAM];
    int cantCargados, i, cantreprobados=0, cantaprobados=0;
    cantCargados=IngresarNotas(vAlumnos,TAM);
    //ALUMNOS APROBADOS Y REPROBADOS
    for(i=0;i<cantCargados;i++){
        if(vAlumnos[i].promedio<4)
            cantreprobados++;
        else
            cantaprobados++;
    }
    printf("\n\nALUMNOS REPROBADOS: %d", cantreprobados);
    printf("\nALUMNOS APROBADOS: %d", cantaprobados);
    //INFORME DE ALUMNOS PROMOCIONADOS
    printf("\n\n<<ALUMNOS PROMOCIONADOS>>");
    for(i=0;i<cantCargados;i++){
        if(vAlumnos[i].promedio>=7)
            printf("\n%d-%s-%.2f", vAlumnos[i].ndni,vAlumnos[i].ayn,vAlumnos[i].promedio);
    }
    return 0;
 }
int IngresarNotas (SAlumno va[], int ce)
{
    int i=0, dni, nota, j, pos;
    char nombyape[81];
    float prom, sumanotas=0;
    printf("\n--CARGA PARCIAL DE NOTAS--\n");
    printf("\nIngrese DNI del alumno (0 para terminar):  ");
    do{
        dni=LeerYValidar(1000000,99999999,0);
        pos=Buscar(va,dni,i);
        if(pos!=-1)
            printf("Alumno ya ingresado. Ingrese otro:  ");
    }while(pos!=-1);
    while(dni!=0&&i<ce){
        va[i].ndni=dni;
        printf("Ingrese nombre y apellido del alumno:  ");
        getchar();
        fgets(nombyape,81,stdin);
        nombyape[strlen(nombyape)-1]='\0';
        strcpy(va[i].ayn,nombyape);
        printf("Notas del alumno\n");
        for(j=0;j<2;j++){
            printf("Ingrese la nota %d:  ", j+1);
            do{
                scanf("%d", &nota);
                if(nota<1||nota>10)
                    printf("Error. Ingrese una nota valida:  ");
            }while(nota<1||nota>10);
            va[i].notas[j]=nota;
            sumanotas+=nota;
        }
        prom=sumanotas/2;
        va[i].promedio=prom;
        printf("Promedio: %.2f", va[i].promedio);
        sumanotas=0;
        i++;
        if(i<ce){
            printf("\n\nIngrese DNI del alumno (0 para terminar):  ");
            do{
                dni=LeerYValidar(1000000,99999999,0);
                pos=Buscar(va,dni,i);
                if(pos!=-1&&dni!=0)
                    printf("Alumno ya ingresado. Ingrese otro:  ");
            }while(pos!=-1&&dni!=0);
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
            printf("\nDato incorrecto. Ingrese uno nuevamente:  ");
    }while((aux<min||aux>max)&&aux!=ex);
    return aux;
}
int Buscar (SAlumno va[], int dato, int ce)
{
    int i=0, pos=-1;
    while(i<ce&&pos==-1){
        if(va[i].ndni==dato)
            pos=i;
        else
            i++;
    }
    return pos;
}

