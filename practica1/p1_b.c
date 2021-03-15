#include<stdio.h>

// Creado el 10 de Marzo del 2021
// Creado por Brigada 1

int main(){

    int i,j,matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int *pmatriz[3][3];

     pmatriz[0][0] = matriz;
        printf("En respuesa al inciso c: La direccion de memoria del matriz es %p.\n\n",pmatriz[0][0]);

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){


            pmatriz[i][j] = &matriz[i][j];

        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){

            printf("Direccion para matriz[%d][%d]: %p\n",i,j,pmatriz[i][j]);

        }
    }

    return 0;
}
