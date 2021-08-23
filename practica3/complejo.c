#include "Complejo.h"
#include<stdio.h>

// Hecho por la BRIGADA 1

int main(){
    COMPLEJO complejo1, complejo2,resultado;
    PedirDatos(&complejo1,&complejo2);
    printf("\nEl primero complejo introducido es: ");
    ImprimirComplejo(&complejo1);
    printf("\nEl segundo complejo introducido es: ");
    ImprimirComplejo(&complejo2);
    SumarComplejos(&complejo1,&complejo2,&resultado);
    printf("\nLa suma de los numero complejos es: ");
    ImprimirComplejo(&resultado);
    MultiplicarComplejos(&complejo1,&complejo2,&resultado);
    printf("\nEl producto de los numeros complejos es: ");
    ImprimirComplejo(&resultado);
    return 0;
}

void PedirDatos(COMPLEJO* complejo1,COMPLEJO* complejo2){
    printf("Ingresa la parte real del primer complejo: ");
    scanf("%f",&complejo1->real);
    printf("\nIngresa la parte imaginaria del primer complejo: ");
    scanf("%f",&complejo1->imaginario);
    printf("\nIngresa la parte real del segundo complejo: ");
    scanf("%f",&complejo2->real);
    printf("\nIngresa la parte real del segundo complejo: ");
    scanf("%f",&complejo2->imaginario);
}

void SumarComplejos(COMPLEJO* complejo1, COMPLEJO* complejo2,COMPLEJO* resultado){
    resultado->real = 0;
    resultado->imaginario = 0;
    resultado->real = complejo1->real + complejo2->real;
    resultado->imaginario = complejo1->imaginario + complejo2->imaginario;
}

void ImprimirComplejo(COMPLEJO* complejo){
    if(complejo->imaginario == 0){
        printf(" %.2f .\n",complejo->real);
    }else if(complejo->imaginario < 0){
        printf(" %.2f  %.2fi .\n",complejo->real,complejo->imaginario);
    }else{
        printf(" %.2f + %.2fi .\n",complejo->real, complejo->imaginario);
    }
}

void MultiplicarComplejos(COMPLEJO* complejo1, COMPLEJO* complejo2,COMPLEJO* resultado){
    resultado->real = complejo1->real * complejo2->real - complejo1->imaginario * complejo2->imaginario;
    resultado->imaginario = complejo1->imaginario * complejo2->real + complejo1->real * complejo2->imaginario;
}
