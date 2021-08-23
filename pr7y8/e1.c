#include "e1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    lista *l = crear_lista();
   
    char i; 
    int d = 0;

   
    
    do
    {
        printf("Introduzca el valor entero del dato:\n");
        scanf("%d", &d);
        anhadir(l, d);

        printf("Quiere añadir otro elemento <s/n>?:\n");
        scanf("%s", &i);
    }while (i != 'n');
    
    imprimir_lista(l);
    


    vaciar(l);

    free(l);

    return (EXIT_SUCCESS);
}



void imprimir_lista(lista *l)
{
    printf("\n");
    for(nodo* t = l->head; t != NULL; t =  t->sig)
    {
        printf("%d ->", t->info);
    }
    printf("\n\n");
}


nodo* crear_nodo(INFO info)
{
    nodo* t = (nodo*) malloc(sizeof(nodo));
    t->sig = NULL;
    t->info = info;
    return t;
}

bool insertar_inicio(lista *l, INFO info)
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
        l->head = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_fin(lista* l, INFO info)
{
    nodo* nuevo = crear_nodo(info);
    if(l->head==NULL && l->tail==NULL){
        
        l->head = l->tail = nuevo;
        l->num++;
        return true;
    }else{
        l->tail->sig = nuevo;
        l->tail = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_elemento(lista* l, int d)
{   
    if (d < l->head->info)
    {
        insertar_inicio(l, d);
        return true;
    } 
    else if (d > l->tail->info)
    {
        insertar_fin(l, d);
        return true;
    }
    else 
    {
        nodo* temporal = l->head;

        while (temporal -> sig != NULL)
        {   
            if (d < temporal->sig->info)
            {
                nodo* nuevo_nodo = crear_nodo(d);
                nuevo_nodo->sig = temporal->sig;
                temporal->sig = nuevo_nodo;
                return true;
            }

            temporal = temporal -> sig;
        }
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

int cardinal(lista * l)
{
    if(es_vacia(l))
        return 0;
    return l->num;
}

bool anhadir(lista* l, int d)
{   
    if (es_vacia(l))
    {
        insertar_inicio(l, d);
        return true;
    } 
    else if (!(pertenencia(l, d)))
    {
        insertar_elemento(l, d);
        return true;
    }
    else
    {   
        printf("Ese elemento ya esta en la lista\n");
        return false;
    }
}

bool pertenencia(lista* l, INFO info)
{  
    if (es_vacia(l)) return false;
    
    nodo* temporal = l->head;

    while (temporal != NULL)
    { 
        if (comparar(temporal->info, info)) 
            return true;
        temporal = temporal->sig;
    }

    return false; 
}

