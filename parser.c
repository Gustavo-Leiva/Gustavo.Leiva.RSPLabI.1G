#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "post.h"



int  parser_PostFromText(FILE* pFile, LinkedList* pArrayListPosteos)
{
    int todoOk = 0;
    char buffer[5][50];
    char falsa[5][50];
    ePost* unPost = NULL;

    if(pFile != NULL && pArrayListPosteos != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", falsa[0], falsa[1], falsa[2], falsa[3],falsa[4]);
        while(!feof(pFile))
        {
            todoOk = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

            if(todoOk!=5)
            {
                printf("Hubo un problema para leer el post\n");
                exit(1);
            }
            else
            {
                unPost = Post_newStr(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);


                if( unPost != NULL)
                {
                    todoOk = ll_add(pArrayListPosteos, unPost);
                }
            }
        }
    }
    return todoOk;
}
