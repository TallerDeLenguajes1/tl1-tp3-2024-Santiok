#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 5
#define TAMA 100

int main(void){

    char **nombres = malloc(CANT * sizeof(char *));

    //Ingreso los nombres.

    printf("Ingrese cinco nombres: \n");

    for (int i = 0; i < CANT; i++)
    {

        nombres[i] = malloc(TAMA * sizeof(char));
        scanf("%s", nombres[i]);

    }

    //Muestro los nombres.

    printf("\nLos nombres son :\n");

    for (int i = 0; i < CANT; i++)
    {
        
        printf("\n %s", nombres[i]);

    }

    //Libero la memoria.

    for (int i = 0; i < CANT; i++)
    {
        free(nombres[i]);
    }
    free(nombres);
    
}