#include <stdio.h>

int main()
{
    
    int *a1, a;
    char *b1, b;
    double *c1, c;
    long  *d1, d;
    float *e1, e;
    short *f1, f;

    a1 = &a;
    b1 = &b;
    c1 = &c;
    d1 = &d;
    e1 = &e;
    f1 = &f;

    printf("\nValor apuntado por el apuntador: %p\n", a1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &a);

    printf("\nValor apuntado por el apuntador: %p\n", b1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &b);

    printf("\nValor apuntado por el apuntador: %p\n", c1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &c);

    printf("\nValor apuntado por el apuntador: %p\n", d1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &d);

    printf("\nValor apuntado por el apuntador: %p\n", e1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &e);

    printf("\nValor apuntado por el apuntador: %p\n", f1);
    printf("Direccion de memoria de la variable a la que se apunta: %p\n\n", &f);

    a = 1;
    b = 'b';
    c = 3.1;
    d = 4;
    e = 3.1416;
    f = 6;

    printf("Valores de las variables usando apuntadores");
    printf("%i\n", *a1); // int
    printf("%c\n", *b1); // char
    printf("%lf\n", *c1); // double
    printf("%ld\n", *d1); // long
    printf("%f\n", *e1);  // float
    printf("%hi\n", *f1);  // short

    *a1 = 2;
    
    *b1 = 'v';
    
    *c1 = 3.2;
    
    *d1 = 5;
    
    *e1 = 4.1416;
    
    *f1 = 7;
    

    printf("\nValores modificados por apuntadores dados a las variables");
    printf("\n%i\n", a); // int
    printf("%c\n", b); // char
    printf("%lf\n", c); // double
    printf("%ld\n", d); // long
    printf("%f\n", e);  // float
    printf("%hi\n", f);  // short
    printf("\n");

}