#include<stdio.h>
#include"ejercicio3.h"

/* 
Ejercicio 3. En la funcion insertar se pasan los parametros (cola, elemento a ingresar, prioridad)
Donde solo hay 3 prioridades, donde el 3 es la mas importante y el 1 el menos importante
Dependiendo de la importancia de la informacion, el elemento se ingresara ya sea antes o despues
de cierto nodo. 
En ese caso, el o los elementos mas importantes se haran primero, por lo tanto se eliminaran
primero de la cola,
*/
int main(){
    COLA* cola;
    cola = CrearCola();
    Insertar(cola,3,3); //  NULL <-- 3 <==> NULL
    ImprimirCola(cola);
    Insertar(cola,1,1); // 3,1
    ImprimirCola(cola);
    Insertar(cola,10,1); // 3, 1, 10
    ImprimirCola(cola);
    Insertar(cola,2,2); // 3, 2, 1,10
    ImprimirCola(cola);
    Insertar(cola,50,2); // 3, 50 ,2, 1, 10
    ImprimirCola(cola); 
    Pop(cola);      // se va el 3
    ImprimirCola(cola);
    Pop(cola);      // se va el 50
    ImprimirCola(cola);
    Pop(cola);      // se va el 2
    ImprimirCola(cola);
    VaciarCola(cola);
    ImprimirCola(cola);
    EliminarCola(cola); 
    return 0;
}

COLA* CrearCola(){
    COLA* l = (COLA*) malloc(sizeof(COLA));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

NODO* CrearNodo(INFO info,int prioridad){
    NODO* t = (NODO*) malloc(sizeof(NODO));
    t->siguiente = NULL;
    t->anterior = NULL;
    t->info = info;
    t->prioridad = prioridad;
    return t;
}

bool InsertarInicio(COLA* cola,INFO info,int prioridad){
    NODO* nodo = CrearNodo(info,prioridad);
    if(EsVacia(cola)){
        cola->head = cola->tail = nodo;
        cola->num++;
        return true; 
    }
    nodo->siguiente = cola->head;
    cola->head->anterior = nodo;
    cola->head = nodo;
    cola->num++;
    return true;
}

bool InsertarFinal(COLA* cola, INFO info,int prioridad){
    NODO* nodo = CrearNodo(info,prioridad);
    if(EsVacia(cola)) return InsertarInicio(cola,info,prioridad);
    cola->tail->siguiente = nodo;
    nodo->anterior = cola->tail;
    cola->tail = nodo;
    cola->num++;
    return true;
}

// mas importante -- insertar inicio: prioridad 3 
// menos importante -- insertar final: prioridad 1
bool Insertar(COLA* cola,INFO info,int prioridad){
    if(prioridad == 1) return InsertarFinal(cola,info,prioridad);
    if(prioridad == 3 || EsVacia(cola)) return InsertarInicio(cola,info,prioridad);
    if(prioridad == 2){
        if(cola->head->prioridad != 3) return InsertarInicio(cola, info,prioridad);
        else{
            NODO* temporal = cola->head;
            NODO* nodo = CrearNodo(info,prioridad);
            for(temporal = cola->head; temporal->prioridad == 3;temporal=temporal->siguiente);
            nodo->siguiente = temporal;
            nodo->anterior = temporal->anterior;
            nodo->anterior->siguiente = nodo;
            nodo->siguiente->anterior = nodo;
            cola->num++;
            return true;
        }
    }
    return false;
}

bool EsVacia(COLA *cola){
    if(cola->head == NULL && cola->tail == NULL) return true;
    return false;
}

void ImprimirCola(COLA* cola){
    if(EsVacia(cola)){
        printf("Esta Vacia.\n");
        return;
    }
    NODO* temporal;
    printf("\nNULL <-- ");
    for(temporal = cola->head; temporal != NULL; temporal = temporal->siguiente){
        printf("%d - Prioridad: %d <==> ",temporal->info,temporal->prioridad);
    }
    printf("NULL\n\n");
}

void Pop(COLA* cola){ // Eliminar al inicio
    if(EsVacia(cola)) return;
    cola->head = cola->head->siguiente;
    cola->head->anterior->siguiente = NULL;
    free(cola->head->anterior);
    cola->head->anterior = NULL;
    cola->num--;
}

bool comparar(INFO info1, INFO info2){
    if(info1 == info2) return true;
    return false;
}

void EliminarCola(COLA* cola){
    if(EsVacia(cola)){
        free(cola);
    }else{
        printf("\nNo se ha podido eliminar la cola.\n");
    }
}

void VaciarCola(COLA* cola){
    if(EsVacia(cola)) return;
    while(cola->head != cola->tail){
        cola->head = cola->head->siguiente;
        cola->head->anterior->siguiente = NULL;
        free(cola->head->anterior);
        cola->head->anterior = NULL;
    }
    free(cola->head);
    cola->head = cola->tail = NULL;    
}
