#include <stdio.h>
#include <string.h>
#include "e1.h"

//Realizado el 24/06/2021
//Realizado por la brigada 1

void main()
{

    char pos[20], in[20]; // para entrada y salida de las cadenas
    int i;                // para aplicar la funcion strlen

    printf("Escriba la cadena infija\n"); // entrada de la cadena
    scanf("%s", &in);

    i = strlen(in); // le da el valor a i del total de caracteres de la cadena
    in[i] = '#'; // para diferencias operadores de operandos 
    in[i+1] = 0; // cadena vacia

    inpos(in, pos);
    imprimir(in,pos);
}

void imprimir(char *in, char *pos) // imprime los resultados
{
    printf("La cadena infija es: %s\nLa cadena postfija es: %s  ", in, pos);
}


void inpos(char *in, char *pos)
{

    array l;
    int i, j;
    char aux;
    i = 0;
    j = -1;

    inicio(&l);

    while (in[i] != '#')
    {

        if (op(in[i])) // si es operando y no operador
        {
            pos[++j] = in[i++]; // preincremento en posfija e incremento en infija
        }
        else
        {
            while (!es_vacia(&l) && prioridad(tope(l), in[i])) // mientas no sea vacia se meten y sacan elementos a la pila
            {
                pop(&l, &aux);
                pos[++j] = aux;
            }
            if (in[i] == ')')
            {
                pop(&l, &aux);
            }
            else
            {
                push(&l, in[i]); 
            }
            i++;
        }
    }

    while (!es_vacia(&l)) // si no esta vacia, sacamos lo que haya de la pila
    {
        pop(&l, &aux);
        pos[++j] = aux;
    }
    pos[++j] = 0; 
}

int op(char c) // para filtrar operandos de operadores
{
    return (c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != ')' && c != '(');
}

int prioridad(char op1, char op2) // aqui se ordena dandole valores de 0 a 5 dependiendo la prioridad de cada operando
{

    int i, j;

    switch (op1)
    {
    case '+':
        i = 0;
        break;
    case '-':
        i = 1;
        break;
    case '*':
        i = 2;
        break;
    case '/':
        i = 3;
        break;
    case '^':
        i = 4;
        break;
    case '(':
        i = 5;
        break;
    }

    switch (op2)
    {

    case '+':
        j = 0;
        break;
    case '-':
        j = 1;
        break;
    case '*':
        j = 2;
        break;
    case '/':
        j = 3;
        break;
    case '^':
        j = 4;
        break;
    case '(':
        j = 5;
        break;
    case ')':
        j = 6;
        break;
    }
    return (m[i][j]); // se va a la variable estatica
}

char tope(array l)
{
    return (l.a[l.t-1]); // la informacion del entero y char de array
}

void inicio(array *l) // inicio el array 
{
    l->t = 0;
}

int es_vacia(array *l) // comprobar si esta vacia
{
    return (!l->t);
}

void push(array *l, char s) // insertar push
{

    if (l->t == TAM)
    {
        printf("La pila esta llena\n"); // llego al tope de la pila
    }
    else
    {
        l->t++;
        l->a[l->t-1] = s; // se va reduciendo el espacio en la pila
    }
}

void pop(array *l, char *s) // remover pop
{

    if (es_vacia(l))
    {
        printf("la pila esta vacia\n");

        *s = '#';
    }

    else
    {

        *s = l->a[l->t - 1];

        l->t--;
    }
}