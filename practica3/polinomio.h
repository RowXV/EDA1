#ifndef POLINOMIO_H
#define POLINOMIO_H
#include<stdio.h>

typedef struct Termino TERMINO;

struct Termino{
    int coeficiente;
    int exponente;
    // char base; 
    TERMINO* siguiente;
}; 

typedef struct Polinomio POLINOMIO;

struct Polinomio{
    TERMINO* head;
    TERMINO* tail;
    int numTerminos;
};

POLINOMIO* CrearPolinomio();
TERMINO* CrearTermino(int coeficiente,int exponente); // BASE
void PedirDatos();
void Insertar(POLINOMIO* polinomio,int coeficiente,int exponente);
bool EsVacio(POLINOMIO* polinomio);
void ImprimirPolinomio(POLINOMIO* polinomio);
void SumarPolinomios(POLINOMIO* poli1,POLINOMIO* poli2,POLINOMIO* resultado);
void RestarPolinomios(POLINOMIO* poli1,POLINOMIO* poli2,POLINOMIO* resultado);

#endif
