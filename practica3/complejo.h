#ifndef COMPLEJO_H
#define COMPLEJO_H

#include<stdio.h>

struct Complejo{
    float real;
    float imaginario;
};

typedef struct Complejo COMPLEJO;

void PedirDatos(COMPLEJO* complejo1, COMPLEJO* complejo2);
void SumarComplejos(COMPLEJO* complejo1, COMPLEJO* complejo2,COMPLEJO* resultado);
void ImprimirComplejo(COMPLEJO* complejo);
void MultiplicarComplejos(COMPLEJO* complejo1, COMPLEJO* complejo2,COMPLEJO* resultado);

#endif
