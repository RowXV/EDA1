#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"polinomio.h"

POLINOMIO* poli1,*poli2,*aux,*resultado;


int main(){
    
    PedirDatos();
    ImprimirPolinomio(poli1);
    ImprimirPolinomio(poli2);
    SumarPolinomios(poli1,poli2,resultado);
    ImprimirPolinomio(resultado);

    return 0;
}

POLINOMIO* CrearPolinomio(){
    POLINOMIO* polinomio = (POLINOMIO*) malloc(sizeof(POLINOMIO));
    polinomio->head = polinomio->tail = NULL;
    polinomio->numTerminos = 0;
    return polinomio;
}

TERMINO* CrearTermino(int coeficiente,int exponente){
    TERMINO* termino = (TERMINO*)malloc(sizeof(TERMINO));
    termino->coeficiente = coeficiente;
    // termino->base = base;
    termino->exponente = exponente;
    termino->siguiente=NULL;
    return termino;
}

void PedirDatos(){
    int coeficiente, exponente;
    poli1 = CrearPolinomio();
    poli2 = CrearPolinomio();
    int i = 0,j,num;
    printf("Ingresa el numero de terminos que tendra el polinomio: ");
    scanf("%d",&num);
    aux = poli1;
    while(i <= 1){
        for(j = 0; j < num;j++){
            printf("Ingresa el coeficiente del polinomio %d en el termino %d: ",i+1,j+1);
            scanf("%d",&coeficiente);
            printf("Ingresa el exponenete del polinonomio %d en el termino %d: ",i+1,j+1);
            scanf("%d",&exponente);
            Insertar(aux,coeficiente,exponente);
        }    
        aux = poli2;  
        i++;  
    }        
    
}

void Insertar(POLINOMIO* polinomio,int coeficiente,int exponente){
    TERMINO* termino = CrearTermino(coeficiente,exponente);
    if(EsVacio(polinomio)){
        polinomio->head = termino;
        polinomio->tail = termino;
        polinomio->numTerminos++;
    }else{
        polinomio->tail->siguiente = termino;
        polinomio->tail = termino;
        polinomio->numTerminos++;
    }
}

bool EsVacio(POLINOMIO* polinomio){
    if(polinomio->head == NULL && polinomio->tail == NULL) return true;
    return false;
}

void ImprimirPolinomio(POLINOMIO* polinomio){
    TERMINO* aux = polinomio->head;
    for(aux = polinomio->head; aux != NULL; aux = aux->siguiente){
        printf("%dx^%d + ",aux->coeficiente,aux->exponente);
    }
    printf("0\n");
    system("PAUSE");
}

void SumarPolinomios(POLINOMIO* poli1,POLINOMIO* poli2,POLINOMIO* resultado){
    TERMINO* aux1,*aux2,*aux3;
    for(aux1 = poli1->head; aux1 != NULL; aux1 = aux1->siguiente){
        for(aux2 = poli2->head; aux2 != NULL; aux2->siguiente){
            if(aux1->exponente == aux2->exponente){
                aux3->coeficiente = aux1->coeficiente + aux2->coeficiente;
                aux3->exponente = aux1->exponente;
                Insertar(resultado,aux3->coeficiente,aux3->exponente);
            } 
        }
        
    }
}

void RestarPolinomios(POLINOMIO* poli1,POLINOMIO* poli2,POLINOMIO* resultado){
    TERMINO* aux1,*aux2,*aux3;
    for(aux1 = poli1->head; aux1 != NULL; aux1 = aux1->siguiente){
        for(aux2 = poli2->head; aux2 != NULL; aux2->siguiente){
            if(aux1->exponente == aux2->exponente){
                aux3->coeficiente = aux1->coeficiente - aux2->coeficiente;
                aux3->exponente = aux1->exponente;
                Insertar(resultado,aux3->coeficiente,aux3->exponente);
            } 
        }
        
    }
}
