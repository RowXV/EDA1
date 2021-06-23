#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//Realizado el 11/03/2021
//Realizado por la brigada 1


nodo* crear_nodo(INFO info)
{
    nodo *t = (nodo*)malloc(sizeof(nodo));
    // nodo *t = (nodo*)calloc(info, sizeof(nodo));

    // array = (int*) calloc(num,sizeof(int)); 


    t->sig = NULL;
    t->info = info;
    return t;
}

bool insertar_inicio(lista *l, INFO info)
{
    nodo* nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo; // esto quiere decir que head y tail apuntan a nuevo o sea a la informacion nueva
        l->num++;
        return true;
    }
    else
    {
        nuevo->sig = l->head;
        l->head = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_fin(lista *l, INFO info)
{
    nodo* nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo; // esto quiere decir que head y tail apuntan a nuevo o sea a la informacion nueva
        return true;
    }
    else 
    {
        l->tail->sig = nuevo;
        l->tail = nuevo; // o l->tail = l->tail->sig;
        return true;
    }

    return false;
}

bool insertar(lista* l, INFO info, int pos)
{
    if(pos == 0) return insertar_inicio(l, info);
    
    else if(pos == l->num) return insertar_fin(l, info);

    else if(pos > 0 && pos < l->num)
    {
        nodo* nuevo = crear_nodo(info);
        nodo* temporal = l->head;
        for(int tpos = 0; tpos < pos-1; tpos++)
            temporal = temporal->sig;
        nuevo->sig = temporal->sig;
        temporal->sig = nuevo;
        l->num++;
        return true;
    }
    return false;
}

lista *crear_lista()
{
    lista* l = (lista*)malloc(sizeof(lista));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

bool es_vacia(lista *l)
{
    if(l->head == NULL && l->head == l->tail) return true;
    return false;
}

bool vaciar(lista *l)
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

void imprimir_lista(lista *l)
{
    printf("\n");
    for(nodo* t = l->head; t != NULL; t =  t->sig)
    {
        printf("Nodo: %d Direccion: %p -> ", t->info, t);
    }
    printf("\n\n");
}

void eliminar_nodo(nodo *n)
{
    if(n->sig == NULL)
    {
        free(n);
        n = NULL;
    }
}

void eliminar_inicio(lista *l)
{
    if(es_vacia(l)) return;
    nodo *temporal = l->head;
    l->head = l->head->sig;
    temporal->sig = NULL;
    eliminar_nodo(temporal);
    l->num--;
}

void eliminar_fin(lista *l)
{
    if(es_vacia(l)) return;
    nodo *temporal;
    for(temporal = l->head; temporal->sig != l->tail; temporal = temporal->sig);
    temporal->sig = NULL;
    eliminar_nodo(l->tail);
    l->tail = temporal;
    l->num--;
}

void eliminar(lista *l, int pos)
{
    if(pos == 0) eliminar_inicio(l);
    else if(pos == l->num-1) eliminar_fin(l);
    else if (pos > 0 && pos < l->num-1)
    {
        nodo *temporal = l->head, *temporal2;
        for(int i = 0; i < pos-1; i++)
            temporal = temporal->sig;
        temporal2 = temporal->sig;
        temporal->sig = temporal->sig->sig; // tempora-> = temporal2->sig;
        temporal2->sig = NULL;
        eliminar_nodo(temporal2);
        l->num--;
    }
}

INFO* buscar(lista *l, int pos)
{
    if(es_vacia(l)) return NULL;
    if(pos == 0) return &l->head->info;
    if(pos == l->num-1) return &l->tail->info;
    if (pos > 0 && pos < l->num-1)
    {
        nodo *temporal = l->head;
        for(int i = 0; i < pos; i++)
            temporal = temporal->sig;
        return &temporal->info;
    }
}

int localizar(lista *l, INFO info)
{
    if(es_vacia(l)) return -1;
    nodo *temporal = l->head;
    int pos = 0;
    while(temporal != NULL)
    {
        if(comparar(temporal->info, info)) return pos;
        pos++;
        temporal = temporal->sig;
    }
    return -1;
}

bool comparar(INFO info1, INFO info2)
{
    if(info1 == info2) return true;
    return false;
}