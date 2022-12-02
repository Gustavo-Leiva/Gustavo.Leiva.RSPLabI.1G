#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "post.h"

#include <string.h>

int main()
{
    char salir = 'N';
    char nombreArchivo[20];
    LinkedList* listaPosteos = ll_newLinkedList();
    LinkedList* listaMap = ll_newLinkedList();



    do
    {
        switch(controller_menuInicio())
        {
        case 1:
            printf("Ingrese Nombre del Archivo a cargar (posts)\n");
            fflush(stdin);
            gets(nombreArchivo);
            strcat(nombreArchivo, ".csv");
            if ( !controller_cargarPostDesdeTexto(nombreArchivo, listaPosteos) )
            {
                controller_cargarPostDesdeTexto("posts.csv", listaPosteos);
            }
            system("pause");
            break;
        case 2:
            controller_imprimirPosteos(listaPosteos);
            system("pause");
            break;
        case 3:
            listaMap = controller_AsignarEstadisticasLike(listaPosteos);
            listaMap = controller_AsignarEstadisticasDislike(listaPosteos);
            listaMap = controller_AsignarEstadisticasFollowers(listaPosteos);
            controller_imprimirPosteos(listaMap);
            system("pause");
            break;
        case 4:

            if (!controller_filtrarLikes(listaPosteos))
            {
                printf("Error al listar posteos\n");
            }
            system("pause");
            break;
        case 5:

            if ( !controller_filtrarHater(listaPosteos))
            {
                printf("Error al listar posteos\n");
            }
            system("pause");
            break;
        case 6:
            ll_sort(listaPosteos,compararFollower,0);
            controller_imprimirPosteos(listaPosteos);
            system("pause");
            break;
        case 7:
            controller_postConMasLikes(listaPosteos);
            break;
        case 8:
            controller_confirmarSalida(&salir);
            break;

        }
    }
    while(salir != 'S');


    ll_deleteLinkedList(listaPosteos);
    ll_deleteLinkedList(listaMap);

    return 0;
}

