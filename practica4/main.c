#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    lista *l1, l2;
    l1 = crear_lista();
    l2.head = l2.tail = NULL;
    l2.num = 0;

    insertar(l1, 3, 0);
    // insertar(l1, 1, 0);
    // insertar(l1, 3, 0);
    // insertar(l1, 4, 0);
    // insertar(l1, 6, 2);
    imprimir_lista(l1);

    // int p = localizar(l1, 3);
    // printf("Pos = %d\n" , p);

    // p = localizar(l1, -5);
    // printf("Pos = %d\n" , p);

    // INFO *info = buscar(l1, 2);
    // printf("Info = %d\n", *info); //*info se imprime el contenido de la direccion apuntada

    //

    // eliminar(l1, 2);
    // eliminar(l1, 3);
    // imprimir_lista(l1);

    // insertar(&l2, 0, 0);
    // insertar(&l2, 1, 0);
    // insertar(&l2, 2, 0);

    // imprimir_lista(l1);
    // imprimir_lista(&l2);

    vaciar(l1);
    vaciar(&l2);

    free(l1);

    return (EXIT_SUCCESS);
}