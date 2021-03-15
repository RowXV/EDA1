#include <stdio.h>
//Realizado el 11/03/2021
//Realizado por la brigada 1

int main()
{//Se declaren variables y su apuntador de tipo: int, char, double, long, float y short.
    int i, *ip = NULL;
    char c, *cp = NULL;
    double d, *dp = NULL;
    long l, *lp = NULL;
    float f, *fp = NULL;
    short s, *sp = NULL;
//Se asigne la dirección de memoria a cada apuntador de la variable correspondiente.
    ip = &i;
    printf("\n\nValor apuntado por el apuntador: %p\n", ip);
    printf("Valor en memoria de la variable: %p\n\n", &i);
    cp = &c;
    printf("Valor apuntado por el apuntador: %p\n", cp);
    printf("Valor en memoria de la variable: %p\n\n", &c);
    dp = &d;
    printf("Valor apuntado por el apuntador: %p\n", dp);
    printf("Valor en memoria de la variable: %p\n\n", &d);
    lp = &l;
    printf("Valor apuntado por el apuntador: %p\n", lp);
    printf("Valor en memoria de la variable: %p\n\n", &l);
    fp = &f;
    printf("Valor apuntado por el apuntador: %p\n", fp);
    printf("Valor en memoria de la variable: %p\n\n", &f);
    sp = &s;
    printf("Valor apuntado por el apuntador: %p\n", sp);
    printf("Valor en memoria de la variable: %p\n\n", &s);

//Asignar un valor a las variables.
    i = 3;
    printf("INT\n");
    printf("Apuntador: %i\n", *ip);
    printf("Variable: %i\n\n", i);
    c = 'C';
    printf("CHAR\n");
    printf("Apuntador: %c\n", *cp);
    printf("Variable: %c\n\n", c);
    d = 3.3;
    printf("DOUBLE\n");
    printf("Apuntador: %lf\n", *dp);
    printf("Variable: %lf\n\n", d);
    l = 168978;
    printf("LONG\n");
    printf("Apuntador: %ld\n", *lp);
    printf("Variable: %ld\n\n", l);
    f = 0.0001;
    printf("FLOAT\n");
    printf("Apuntador: %f\n", *fp);
    printf("Variable: %f\n\n", f);
    s = 1;
    printf("SHORT\n");
    printf("Apuntador: %hi\n", *sp);
    printf("Variable: %hi\n\n", s);
//
    printf("///////MODIFICANDO...\n\n");
//Modificar los valores de las variables mediante el operador (*) y los apuntadores
    *ip = 5;
    printf("INT\n");
    printf("Apuntador: %i\n", *ip);
    printf("Variable: %i\n\n", i);
    *cp = 'A';
    printf("CHAR\n");
    printf("Apuntador: %c\n", *cp);
    printf("Variable: %c\n\n", c);
    *dp = 1.2;
    printf("DOUBLE\n");
    printf("Apuntador: %lf\n", *dp);
    printf("Variable: %lf\n\n", d);
    *lp = 2345697;
    printf("LONG\n");
    printf("Apuntador: %ld\n", *lp);
    printf("Variable: %ld\n\n", l);
    *fp = 0.0002;
    printf("FLOAT\n");
    printf("Apuntador: %f\n", *fp);
    printf("Variable: %f\n\n", f);
    *sp = 2;
    printf("SHORT\n");
    printf("Apuntador: %hi\n", *sp);
    printf("Variable: %hi\n\n", s);

    return 0;
}