#ifndef EJERCICIO_3
#define EJERCICIO_3

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef int INFO;
typedef struct Nodo NODO;
struct Nodo{
    INFO info;
    NODO *siguiente;
    NODO *anterior;
    int prioridad;
};

typedef struct Cola COLA;

struct Cola{
    NODO *head;
    NODO *tail;
    int num;
};

NODO* CrearNodo(INFO info,int prioridad);
COLA* CrearCola();
bool InsertarInicio(COLA* cola,INFO info,int prioridad);
bool InsertarFinal(COLA* cola, INFO info,int prioridad);
bool Insertar(COLA* cola,INFO info,int prioridad);
bool EsVacia(COLA *cola);
void ImprimirCola(COLA* cola);
void Pop(COLA* cola); // Eliminar Inicio
bool comparar(INFO info1, INFO info2);
void EliminarCola(COLA* cola);
void VaciarCola(COLA* cola);


#endif
