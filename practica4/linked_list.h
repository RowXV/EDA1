#ifndef LINKED_LIST_H
#define LINKED_LIST_H   

#include <stdbool.h>

typedef struct _nodo nodo;
typedef int INFO;

struct _nodo
{
    INFO info;
    nodo *sig;
}; 

typedef struct _lista lista;

struct _lista
{
    nodo *head;
    nodo *tail;
    int num;
};

nodo* crear_nodo(INFO info);
void eliminar_nodo(nodo *n);

lista *crear_lista();
bool insertar_inicio(lista *l, INFO info);
bool insertar_fin(lista *l, INFO info);

//lista circular pa el martes hacer 

bool insertar(lista* l, INFO info, int pos);
bool es_vacia(lista *l);
bool vaciar(lista *l);
void imprimir_lista(lista *l);
void eliminar_inicio(lista *l);
void eliminar_fin(lista *l);
void eliminar(lista *l, int pos);
INFO* buscar(lista *l, int pos);
int localizar(lista *l, INFO info);
bool comparar(INFO info1, INFO info2);


#endif /* LINKED_LIST_H */