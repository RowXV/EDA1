#ifndef E2_H
#define E2_H

//Realizado el 23/06/2021
//Realizado por la brigada 1


#include <stdbool.h>
#include <stdlib.h>

typedef struct _nodo nodo;
typedef int INFO;

struct _nodo
{
    INFO info;
    nodo *sig;
    nodo *ant;
}; 

typedef struct _cola cola;

struct _cola
{
    nodo *head;
    nodo *tail;
    int num;
};

nodo* crear_nodo(INFO info);
cola *crear_cola();

void eliminar_nodo(nodo *n);

bool enqueue(cola *l, INFO info);
bool enqueuel(cola *l, INFO info);

void dequeue(cola *l);
void dequeuel(cola *l);

bool es_vacia(cola *l);
bool vaciar(cola *l);
void eliminar_cola(cola *l);

void imprimir_cola(cola *l);
INFO* top(cola *l);


#endif /* E2_H */