#ifndef E1_H
#define E1_H   

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

bool insertar_elemento(lista* l, int d);
bool insertar(lista* l, INFO info, int pos);
bool es_vacia(lista *l);
bool vaciar(lista *l);
void imprimir_lista(lista *l);
void eliminar_inicio(lista *l);
void eliminar_fin(lista *l);
void eliminar(lista *l, int pos);
INFO* buscar(lista *l, int pos);
int localizar(lista *l, INFO info);
int cardinal(lista * l);
bool comparar(INFO info1, INFO info2);
bool anhadir(lista* l, int d);
bool pertenencia(lista* l, INFO info);

bool entrada(lista *l);


#endif /* E1_H */