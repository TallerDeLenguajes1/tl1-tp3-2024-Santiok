#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIO 5
#define MES 12

//Funcion para mostrar la matriz.

void mostrarMatriz(int matriz[ANIO][MES]);

int main(void){

    int matriz[ANIO][MES];

    //srand(time(NULL));

    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            matriz[i][j] = 10000 + rand() % (50000 - 10000 + 1);  
            // limite inferior + rand() % (lim-sup - lim-inf + 1)
        }  
    }

    mostrarMatriz(matriz);
    
}

void mostrarMatriz(int matriz[ANIO][MES]){

    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            printf(" %d ", matriz[i][j]);
        }  
        printf("\n");
    }
    
}