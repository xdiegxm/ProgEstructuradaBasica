#include <stdio.h>
void mainloop(char [][9], int []);
void mostrar(char [][9], int []);
void cant_reservas_filas_vacias(char [][9]);
void filas_max_reservas(char [][9]);
int buscarPos(int [], int, int);
int validar(int, int, int);
void bubblesort(int [], int[], int);

int main(){
    char asientos[12][9];
    int butacas[9] = {8, 6, 4, 2, 1, 3, 5, 7, 9}, i, j, vSumButacas[9] = {0}, pos;
    for(i = 0; i < 12; i++){
        for(j = 0; j < 9; j++){
            asientos[i][j] = 'd';
        }
    }
    mainloop(asientos, butacas);
    mostrar(asientos, butacas);
    cant_reservas_filas_vacias(asientos);
    filas_max_reservas(asientos);
    for(i = 0; i < 9; i++){
        pos = buscarPos(butacas, i+1, 9);
        for(j = 0; j < 12; j++){
            if(asientos[j][pos] != 'd'){
                vSumButacas[pos]++;
            }
        }
    }
    bubblesort(butacas, vSumButacas, 9);
    printf("\n\n%-6s %-6s", "Fila.B", "VENTAS");
    for(i = 0; i < 9; i++){
        printf("\n%-6d %-6d", butacas[i], vSumButacas[i]);
    }
}
void bubblesort(int butacas[], int sum[], int tam){
    int i, aux, limite = tam -1, desordenado;
    do{
        desordenado = 0;
        for(i = 0; i < limite; i++){
            if(sum[i] < sum[i+1]){
                aux = sum[i];
                sum[i] = sum[i+1];
                sum[i+1] = aux;
                aux = butacas[i];
                butacas[i] = butacas[i+1];
                butacas[i+1] = aux;
                desordenado = i;
            }
        }
        limite = desordenado;
    }while(desordenado);
}
int validar(int min, int max, int ex){
    int aux;
    do{
        scanf("%i", &aux);
        if((aux < min || aux > max) && aux != ex){
            printf("\nIngrese dato valido:  ");
        }
    }while((aux < min || aux > max) && aux != ex);
    return aux;
}
int buscarPos(int vec[], int x, int tam){
    int i = 0, pos = -1;
    while(i < tam && pos == -1){
        if(vec[i] == x){
            pos = i;
        }
        i++;
    }
    return pos;
}
void filas_max_reservas(char asientos[][9]){
    int i, j, counter, max = -1, k, filamax[9] ={0};
    for(i = 0; i < 12; i++){
        counter = 0;
        for(j = 0; j < 9; j++){
            if(asientos[i][j] == 'r'){
                counter++;
            }
        }
        if(counter > max){
            max = counter;
            filamax[0] = i + 1;
            k = 1;
        }
        if(counter == max){
            filamax[k] = i + 1;
            k++;
        }
    }
    printf("\nMAXIMA CANTIDAD DE RESERVADOS POR FILA:  %d", max);
    printf("\nFILAS MAS VENDEDORAS");
    for(i = 0; i < k; i++){
        printf("\n%-3d ", filamax[i]);
    }
}
void cant_reservas_filas_vacias(char asientos[][9]){
    int i, j, flag, cantR = 0, cantD = 0;
    printf("\nFILAS VACIAS");
    for(i = 0; i < 12; i++){
        flag = -1;
        for(j = 0; j < 9; j++){
            if(asientos[i][j] =='r'){
                flag = 1;
                cantR++;
            }
            else{
                cantD++;
            }
        }
        if(flag != 1)
            printf("\n%-12d", i +1);
    }
    printf("\n\nASIENTOS RESERVADOS:   %i", cantR);
    printf("\nASIENTOS DISPONIBLES:    %i", cantD);
}
void mostrar(char asientos[][9], int butacas[]){
    int i, j;
    printf("\n\n   ");
    for(i = 0; i < 9; i++){
        printf("%-2d ", butacas[i]);
    }
    for(i = 0; i < 12; i++){
        printf("\n%-2d ", i+1);
        for(j = 0; j < 9; j++){
            printf("%-2c ", asientos[i][j]);
        }
    }
}
void mainloop(char asientos[][9], int butacas[]){
    int f, c, posc;
    mostrar(asientos, butacas);
    printf("\nIngresar fila(-1 para finalizar): ");
    f = validar(1, 12, -1);
    while(f != -1){
        printf("\nIngresar columna: ");
        c = validar(1, 9, 8);
        posc = buscarPos(butacas, c, 9);
        if(asientos[f-1][posc] == 'r'){
            printf("\nAsiento ocupado...");
        }
        else{
            asientos[f-1][posc] = 'r';
            printf("\nSe ha reservado el asiento!\n");
        }
        mostrar(asientos, butacas);
        printf("\nIngresar fila(-1 para finalizar):  ");
        f = validar(1, 12, -1);
    }
    printf("\n\nVENTA DE ENTRADAS FINALIZADA>>>>>>\n\n");
}
