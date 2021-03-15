// Creado el 15 de Marzo de 2021
// Creado por la Brigada 1

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void sumar(float *a,float *b, float c);
void restar(float *a,float *b, float c);
void multiplicar(float *a,float *b, float c);
void dividir(float *a,float *b, float c);
void mostrarMenu();

int main(){

    mostrarMenu();

    return 0;
}

void sumar(float *a,float *b, float c){
    c = *a + *b;
    printf("\nEl resultado de la suma es %f.\n",c);
    getch();
}
void restar(float *a,float *b, float c){
    c = *a - *b;
    printf("\nEl resultado de la resta es %f.\n",c);
    getch();
}
void multiplicar(float *a,float *b, float c){
    c = *a * *b;
    printf("\nEl resultado de la multiplicacion es %f.\n",c);
    getch();
}
void dividir(float *a,float *b, float c){
    c = *a / *b;
    printf("\nEl resultado de la division es %f.\n",c);
    getch();
}
void mostrarMenu(){
    int opcion;
    float a, b, *aa, *bb,c;
    do{
        system("cls");
        printf("Bienvenidx al menu:\n\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. SALIR\n");
        printf("SELECCIONE LA OPCION QUE DESEE: ");
        scanf("%d",&opcion);

        switch (opcion){
            case 1: system("cls");
            printf("Introduzca las DOS numeros a sumar: ");
            scanf("%f %f",&a,&b);
            sumar(&a,&b,c);
            break;
            case 2: system("cls");
            printf("Introduzca las DOS numeros a restar: ");
            scanf("%f %f",&a,&b);
            restar(&a,&b,c);
            break;
            case 3: system("cls");
            printf("Introduzca las DOS numeros a multiplicar: ");
            scanf("%f %f",&a,&b);
            multiplicar(&a,&b,c);
            break;
            case 4: system("cls");
            printf("Introduzca las DOS numeros a dividir: ");
            scanf("%f %f",&a,&b);
            dividir(&a,&b,c);
            break;
            case 5: break;
            default: printf("\nEste numero no esta dentro de las opciones, POR FAVOR VUELVE A INTENTARLO\n");
        }
    }while(opcion != 5);
}