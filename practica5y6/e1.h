#ifndef E1_H
#define E1_H
#define TAM 20

#include <stdio.h>
#include <string.h>

//Realizado el 24/06/2021
//Realizado por la brigada 1

typedef struct _array array;

struct _array 
{

	int t;

	char a[TAM];
};

static int m[6][7]={ //se creo una variable estatica para ir comparando cada uno de los elementos de la cadena con la prioridad de los operadores

        {1, 1, 0, 0, 0, 0, 1},

        {1, 1, 0, 0, 0, 0, 1},

        {1, 1, 1, 1, 0, 0, 1},

        {1, 1, 1, 1, 0, 0, 1},

        {1, 1, 1, 1, 1, 0, 1},

        {0, 0, 0, 0, 0, 0, 0}
};

void inpos(char *in, char *pos); // conversion de infija a posfija
int op(char c); // pa separar operadores de operandos
int prioridad(char op1, char op2); // se asigna prioridad a los operadores
char tope(array l); // pa la informacion de la cadena y su posicion
void inicio(array *l); // inicia el array 
int es_vacia(array *l); // verifica si la pila esta vacia
void push(array *l, char s); // insertar en la pila
void pop(array *l, char *s); // sacar de la pila
void imprimir(char *in, char *pos); // imprime la infija y postfija



#endif 