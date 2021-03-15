#include <stdio.h>
 //Se programo el 5 de marzo del 2021
 //Por la Brigada 1

int main()
{
 
    int matriz[3][2][4];
    int i = 0, j = 0,k = 0;
    printf("\n\nLa direccion de memoria de la variable tipo arreglo es: %p\n", &matriz);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                matriz[i][j][k] = i*3 + j*2 + k*4;
            }
        }
     }
    printf("La direccion de memoria del primero elemento del arreglo es: %p\n", &matriz[i][j][k]);
    
    for(int i = 0; i < 3; i++)
    {
        printf("\nMatriz %d:\n", i);
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                printf("Matriz[%d][%d] = %p \t ",j, k, &matriz[i][j][k]);
                
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
