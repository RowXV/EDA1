#include <stdio.h>
#include "e2.h"

//Realizado el 24/06/2021
//Realizado por la brigada 1

int main()
{
    cola* d;
    d = crear_cola();
    enqueue(d, 1);
    printf("\nAdiciones a la cola\n");
    imprimir_cola(d);
    enqueuel(d, 2);
    imprimir_cola(d);
    enqueue(d, 3);
    imprimir_cola(d);
    enqueue(d, 4);
    imprimir_cola(d);
    enqueuel(d, 5);
    imprimir_cola(d);
    printf("\n\nBloque de eliminaciones:\n\n");
    dequeue(d);
    imprimir_cola(d);
    dequeuel(d);
    imprimir_cola(d);
    printf("\n");
    vaciar(d);
    eliminar_cola(d);
    return 0;
}

nodo* crear_nodo(INFO info)
{
    nodo *t = (nodo*)malloc(sizeof(nodo));
    
    t->sig = NULL;
    t->info = info;
    return t;
}

INFO* top(cola *l)
{
    if(es_vacia(l)) return NULL;
    return &l->head->info;
}


bool enqueue(cola *l, INFO info)
{
    nodo* nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo; 
        l->num++;
        return true;
    }
    else
    {
        nuevo->sig = l->head;
        l->head->ant = nuevo;
        l->head =   nuevo;
        l->num++;
    return true;
    }
    return false;
}

bool enqueuel(cola *l, INFO info)
{
    nodo* nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo; 
        l->num++;
        return true;
    }
    else
    {
        nuevo->ant = l->tail;
        l->tail->sig = nuevo;
        l->tail = nuevo;
        l->num++;
        return true;
    }
    return false;
}

cola *crear_cola()
{
    cola* l = (cola*)malloc(sizeof(cola));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

void imprimir_cola(cola *l)
{
    for(nodo* t = l->head; t != NULL; t =  t->sig)
    {
        printf("%d -> ", t->info);
    }
    printf("\n");
}

void eliminar_nodo(nodo *n)
{
    if(n->sig == NULL)
    {
        free(n);
        n = NULL;
    }
}

void dequeue(cola *l)
{
    if(es_vacia(l)) return;
    l->head = l->head->sig;
    l->head->ant->sig = NULL;
    eliminar_nodo(l->head->ant);
    l->head->ant = NULL;
    l->num--;
}

void dequeuel(cola *l)
{
    l->tail = l->tail->ant;
    l->tail->sig->ant = NULL;
    eliminar_nodo(l->tail->sig);
    l->tail->sig = NULL;
    l->num--;
}

bool es_vacia(cola *l)
{
    if(l->head == NULL && l->head == l->tail) return true;
    return false;
}

bool vaciar(cola *l)
{
    if(es_vacia(l)) return false;
    nodo* temporal = l->head;
    while(temporal != NULL)
    {
        l->head = temporal->sig;
        free(temporal);
        temporal = l->head;
    }
    l->head = l->tail = NULL;
    l->num = 0;
    return true;
}

void eliminar_cola(cola *l)
{
    if(l == NULL) return;
    if(!es_vacia(l)) vaciar(l);
    free(l);
    l = NULL;
}