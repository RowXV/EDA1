#include <stdio.h>

//Se puso a prueba el 15 de marzo del 2021
//Por la Brigada 1 


int main() 
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int *ptr;
    
    arr[1] = 5;
    ptr = &arr[2];

    printf("\nInciso a: %d\n\n", ptr);
    printf("Inciso b: %d\n\n", *ptr);
    printf("Inciso c: %d\n\n", ptr[0]);
    printf("Inciso d: %d\n\n", *ptr+6);
    printf("Inciso e: %d\n\n", *(ptr+6));
    // printf("Inciso f: %d\n\n", *ptr(-1)); --- No compila 
    printf("Inciso g: %d\n\n", ptr[-1]);
    printf("Inciso h: %d\n\n", ptr[9]);
    printf("Inciso i: %p\n\n", &arr);
    printf("Inciso j: %p\n\n", &ptr);
    printf("Inciso k: %p\n\n", &*ptr);
    printf("Inciso k: %p\n\n", &arr[2]);
    
    
    return 0;
}
