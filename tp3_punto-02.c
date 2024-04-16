#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIO 5
#define MES 12

//Funcion para mostrar la matriz.

void mostrarMatriz(int matriz[ANIO][MES]);

//Funcion para el promedio.

void sacarPromedio(int matriz[ANIO][MES]);

//Funcion para los valores minimo y maximo.

void valoresMinMax(int matriz[ANIO][MES]);

int main(void){

    int matriz[ANIO][MES];

    srand(time(NULL));

    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            matriz[i][j] = 10000 + rand() % (50000 - 10000 + 1);  
            // limite inferior + rand() % (lim-sup - lim-inf + 1)
        }  
    }

    mostrarMatriz(matriz);

    sacarPromedio(matriz);

    valoresMinMax(matriz);
    
}

//FUNCION PARA MOSTRAR LA MATRIZ.

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

//FUNCION PARA SACAR EL PROMEDIO.

void sacarPromedio(int matriz[ANIO][MES]){

    int promedio = 0, k = 1;

    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            promedio = promedio + matriz[i][j];
        }  

        promedio = promedio/12;

        printf("\n Promedio del año %d : %d",k, promedio);

        promedio = 0;
        k++;
    }
}

//FUNCION PARA VALORES MINIMO Y MAXIMO.

void valoresMinMax(int matriz[ANIO][MES]){

    int max = 0, min = 0, cont = 0, mesM, anioM, mesMax, anioMax;

    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            if (cont == 0)
            {
                max = matriz[i][j];
                min = matriz[i][j];

                mesM = j + 1;
                anioM = i + 1;
                mesMax = j + 1;
                anioMax = i + 1;

                cont++;
            } else
            {
                if (max < matriz[i][j])
                {
                    max = matriz[i][j];

                    mesMax = j + 1;
                    anioMax = i + 1;

                } else
                {
                    if (min > matriz[i][j])
                    {
                        min = matriz[i][j];

                        mesM = j + 1;
                        anioM = i + 1;
                    }
                    
                }
                
                
            }
            
            
        }  
    }
    printf("\n El valor mas grande es: %d \n Mes: %d \n Año: %d \n\n El valor mas chico es: %d \n Mes: %d \n Año: %d", max, mesMax, anioMax, min, mesM, anioM);
}