#include<stdio.h>
#include<stdlib.h> // Para usar malloc

void crearEspacio();
void mostrarDirecciones();
void asignarValores();
void liberarMemoria();

    // Inciso a
    int r, *rr;
    float a,*aa;
    double q, *qq;
    long u,*uu;
    char e,*ee;
    short l,*ll;

int main(){

    // Inciso b
    crearEspacio();
    // Inciso c
    mostrarDirecciones();
    // Incisos d y e
    asignarValores();
    // Inciso f
    liberarMemoria();

    return 0;
}

void crearEspacio(){

    rr = (int*)malloc(1*sizeof(int));
    aa = (float*)malloc(1*sizeof(float));
    qq = (double*)malloc(1*sizeof(double));
    uu = (long*)malloc(1*sizeof(long));
    ee = (char*)malloc(1*sizeof(char));
    ll = (short*)malloc(1*sizeof(short));

}

void mostrarDirecciones(){

    printf("La direccion del arreglo de tipo int es: %p\n",rr);
    printf("La direccion del arreglo de tipo float es: %p\n",aa);
    printf("La direccion del arreglo de tipo double es: %p\n",qq);
    printf("La direccion del arreglo de tipo long es: %p\n",uu);
    printf("La direccion del arreglo de tipo char es: %p\n",ee);
    printf("La direccion del arreglo de tipo short es: %p\n",ll);

}
void asignarValores(){   

    r = 1;
    a = 12;
    q = 34127;
    u = 7519481;
    e = 'a';
    l = 1;
    
    rr = &r;
    aa = &a;
    qq = &q;
    uu = &u;
    ee = &e;
    ll = &l;

    printf("\nIMPRIMIENDO PRIMERA ASIGNACION DE DATOS...\n\n");  // INCISO D (LISTO)
    printf("El valor del tipo int es: %d\n",*rr);
    printf("El valor del tipo float es: %f\n",*aa);
    printf("El valor del tipo double es: %lf\n",*qq);
    printf("El valor del tipo long es: %ld\n",*uu);
    printf("El valor del tipo char es: %c\n",*ee);
    printf("El valor del tipo short es: %hi\n",*ll);

    r = 10;
    a = 19.8;
    q = 29;
    u = 100039;
    e = 'b';
    l = 12;

    printf("\nIMPRIMIENDO SEGUNDA ASIGNACION DE DATOS...\n\n");  // INCISO E (LISTO)
    printf("El valor del tipo int es: %d\n",*rr);
    printf("El valor del tipo float es: %f\n",*aa);
    printf("El valor del tipo double es: %lf\n",*qq);
    printf("El valor del tipo long es: %ld\n",*uu);
    printf("El valor del tipo char es: %c\n",*ee);
    printf("El valor del tipo short es: %hi\n",*ll);
}

void liberarMemoria(){
    free(rr);
    free(aa);
    free(qq);
    free(uu);
    free(ee);
    free(ll);
}