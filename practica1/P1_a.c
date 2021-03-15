// Ejercicio a

#include<stdio.h>

// Creado el 5 de marzo
// Creado por la Brigada 1

void mostrarArreglo(char *arreglo);

int main(){

    char arreglo[10] = {1,2,3,4,5,6,7,8,9,10}, *parreglo;
    int i;

    parreglo = arreglo;

    mostrarArreglo(arreglo);

    for(i = 0; i < 10; i++){

        printf("La direccion de arreglo[%d] es: %p\n\n",i,parreglo++);
    }

    return 0;
}

void mostrarArreglo(char *arreglo){
    int i;

    printf("IMPRIMIENDO ARREGLO...\n\n");

    for(i = 0; i < 10; i++){

        printf("%d ",arreglo[i]);

    }
    printf("\n\n");
}
