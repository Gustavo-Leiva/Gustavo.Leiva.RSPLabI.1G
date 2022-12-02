#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "validaciones.h"
#include "post.h"
#include "parser.h"
#include <ctype.h>


int controller_menuInicio()
{

    int opcion;

    system("cls");
    if(utn_getNumeroInt(&opcion,
                        "\n********** Menu Inicio*******\n\n"
                        "1. Cargar Archivo\n"
                        "2. Imprimir Lista\n"
                        "3. Asignar Estadisticas\n"
                        "4. Filtrar mejores posteos\n"
                        "5. Filtrar por haters\n"
                        "6. ordenar por cantidad de followers\n"
                        "7. mostrar mas popular\n"
                        "8. Salir\n"
                        "ingrese opcion:\n","Error; reingrese una opcion entre 1 y 8\n",1,8,10)==0)
    {}
    return opcion;
}




int controller_cargarPostDesdeTexto(char* path, LinkedList* pArrayListPosteos)
{

    int todoOk = 0;
    if(pArrayListPosteos != NULL && path != NULL)
    {
        FILE* f = fopen(path, "r");

        if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            parser_PostFromText(f, pArrayListPosteos);
            printf("Lista de posteos cargada con exito!\n");
        }
        fclose(f);
         todoOk = 1;




    }
    return todoOk;
}



int controller_imprimirPosteos(LinkedList* pArrayPosteos)
{
    int todoOk = 0;
    ePost* unPost;
    int len = ll_len(pArrayPosteos);
    if(pArrayPosteos != NULL)
    {
        printf("*********************************LISTADO DE POSTEOS***********************************\n\n");
        printf("      ID                  USER                  LIKE       DISLIKES          FOLLOWERS\n");
        printf("--------------------------------------------------------------------------------------\n");

        for(int i=0; i < len ; i++)
        {
            unPost = (ePost*) ll_get(pArrayPosteos, i);
            Post_mostrarDinamico(unPost);
        }
        todoOk = 1;
    }
    else
    {
        printf("Debe cargar primero el archivo\n");
    }
    return todoOk;
}






LinkedList* controller_AsignarEstadisticasLike(LinkedList* pArrayPosteos)
{
    LinkedList* bufferLista = NULL;
    if(pArrayPosteos != NULL)
    {
        bufferLista = ll_map(pArrayPosteos, Posteos_AsignarEstadisticasLike);

    }
    return bufferLista;
}


LinkedList* controller_AsignarEstadisticasDislike(LinkedList* pArrayPosteos)
{
    LinkedList* bufferLista = NULL;
    if(pArrayPosteos != NULL)
    {
        bufferLista = ll_map(pArrayPosteos, Posteos_AsignarEstadisticasDislike);

    }
    return bufferLista;
}



LinkedList* controller_AsignarEstadisticasFollowers(LinkedList* pArrayPosteos)
{
    LinkedList* bufferLista = NULL;
    if(pArrayPosteos != NULL)
    {
        bufferLista = ll_map(pArrayPosteos, Posteos_AsignarEstadisticasFollowers);

    }
    return bufferLista;
}








int controller_filtrarHater(LinkedList* pArrayPosteos)
{
    int todoOk = 0;
    char bufferCadenaPath[30];
    if (pArrayPosteos != NULL)
    {
        printf("Espere un momento! Buscando informacion\n");
        printf("Listado de usuarios cuyos dislikes es mayor a likes\n\n\n");
        pArrayPosteos = ll_filter(pArrayPosteos,filtrar_hater);
        strcpy(bufferCadenaPath, "posteosConMasHater.csv");

        if(pArrayPosteos != NULL)
        {
            controller_imprimirPosteos(pArrayPosteos);
            system("pause");
            controller_guardarPostDesdeTexto(bufferCadenaPath, pArrayPosteos);
            todoOk = 1;
        }
    }
    return todoOk;
}




int controller_filtrarLikes(LinkedList* pArrayPosteos)
{
    int todoOk = 0;
    char bufferCadenaPath[30];
    if (pArrayPosteos != NULL)
    {
        printf("Espere un momento! Buscando informacion\n");
        printf("Listado de usuarios con Likes mayores a 4000\n\n\n");

        pArrayPosteos = ll_filter(pArrayPosteos,filtrar_likes);
        strcpy(bufferCadenaPath, "posteosConMasLikes.csv");

        if(pArrayPosteos != NULL)
        {
            controller_imprimirPosteos(pArrayPosteos);
            system("pause");
            controller_guardarPostDesdeTexto(bufferCadenaPath, pArrayPosteos);
            todoOk = 1;
        }
    }
    return todoOk;
}




/** \brief Guarda los datos de las (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_guardarPostDesdeTexto(char* path, LinkedList* pArrayListPost)
{
    int todoOk = 0;
    FILE* f;
    int id;
    char user[100];
    int likes;
    int dislikes;
    int followers;
    ePost* auxPost=NULL;

    if ( path != NULL && pArrayListPost != NULL )
    {

        f = fopen(path, "w"); // abro el archivo
        if ( f == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }

        fprintf( f, "id,user,likes,dislikes,followers\n" );

        for (int i = 0; i < ll_len(pArrayListPost); i++)
        {
            auxPost = ll_get(pArrayListPost, i);
            if (    Post_GetIdPost( auxPost, &id ) &&
                    Post_GetUser( auxPost, user ) &&
                    Post_GetLikes( auxPost, &likes) &&
                    Post_GetDislikes(auxPost, &dislikes)&&
                    Post_GetFollowers(auxPost,&followers)
               )
            {
                fprintf(f, "%d,%s,%d,%d,%d\n", id,user, likes, dislikes,followers);
                todoOk = 1;
            }
        }
        system("cls");
        printf("\nGuardado correctamente.\n");
        system("pause");
    }
    fclose(f);
    return todoOk;
}




int controller_postConMasLikes(LinkedList* pArrayListPost)
{
    int todoOk = 0;
    ePost* auxPost=NULL;
    if (pArrayListPost != NULL)
    {
        ll_sort(pArrayListPost, compararLikesPost, 0);
        system("cls");

        auxPost=(ePost* )ll_get(pArrayListPost,0);
        printf("*** Post con mayor cantidad de Likes *** \n\n");
        printf("     ID           user               Likes              Dislikes          Followers\n\n");
        listadosDePosteos(auxPost);
        printf("Post mas likeado\n");
        system("pause");
        todoOk = 1;
    }
    return todoOk;
}


void controller_confirmarSalida (char* x)
{
    printf("confirma salida? (S/N): ");
    fflush(stdin);
    scanf("%c", x );
    *x=toupper(*x);

    while(!(*x =='S' || *x =='N'))
    {
        printf("Error!! Ingrese 'S' o 'N': ");
        fflush(stdin);
        scanf("%c",x);
        *x = toupper(*x);
    }


}
