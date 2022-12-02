#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "post.h"
#include "validaciones.h"
#include <time.h>


/*
------------------------------------------------------------------------------------------------

                                          MOSTRAR

------------------------------------------------------------------------------------------------
*/



void Post_mostrar(ePost unPost)
{
    printf("%4d      %10s      %10d      %4d       %4d\n\n",
           unPost.id,
           unPost.user,
           unPost.likes,
           unPost.dislikes,
           unPost.followers);
}

void Post_mostrarDinamico(ePost* pPost)
{
    printf("%8d      %20s      %10d      %10d       %10d\n\n",
           pPost->id,
           pPost->user,
           pPost->likes,
           pPost->dislikes,
           pPost->followers);
}


/*
------------------------------------------------------------------------------------------------

                                          CONSTRUCCTORES

------------------------------------------------------------------------------------------------
*/

ePost* Post_new()
{
    ePost* nuevoPost = (ePost*) malloc(sizeof(ePost));
    if(nuevoPost != NULL)
    {
        nuevoPost->id = 0;
        strcpy(nuevoPost->user, "");
        nuevoPost->likes = 0;
        nuevoPost->dislikes = 0;
        nuevoPost->followers = 0;
    }
    return nuevoPost;
}


ePost* Post_new_Param(int idPost, char* user, int likes, int dislikes, int followers)
{
    ePost* nuevoPost = Post_new();

    if(!(Post_SetIdPost(nuevoPost, idPost) &&
            Post_SetUser(nuevoPost, user) &&
            Post_SetLikes(nuevoPost, likes) &&
            Post_SetDislikes(nuevoPost, dislikes) &&
            Post_SetFollowers(nuevoPost, followers)))
    {
        free(nuevoPost);
        nuevoPost = NULL;
    }
    return nuevoPost;
}



ePost* Post_newStr(char* idPost, char* user, char* likes, char* dislikes, char* followers)
{
    ePost* nuevoPost = Post_new();


    if(!(Post_SetIdPost(nuevoPost, atoi(idPost)) &&
           Post_SetUser(nuevoPost, user) &&
            Post_SetLikes(nuevoPost, atoi(likes)) &&
            Post_SetDislikes(nuevoPost, atoi(dislikes)) &&
            Post_SetFollowers(nuevoPost, atoi(followers))))
    {
        free(nuevoPost);
        nuevoPost = NULL;
    }
    return nuevoPost;
}


/*
------------------------------------------------------------------------------------------------

                                          SETTERS

------------------------------------------------------------------------------------------------
*/

int Post_SetIdPost(ePost* post, int idPost)
{
    int todoOk = 0;

    if(post != NULL && idPost > 0)
    {
        post->id = idPost;
        todoOk = 1;
    }
    return todoOk;


}


int Post_SetUser(ePost* post, char* user)
{
    int todoOk = 0;

    if(post != NULL && user != NULL && strlen(user) < 100 && strlen(user) > 2)
    {
        strcpy(post->user, user);
        strlwr(post->user);
        post->user[0] = toupper(post->user[0]);
        todoOk = 1;
    }
    return todoOk;
}



int Post_SetLikes(ePost* post, int like)
{
    int todoOk = 0;

    if(post != NULL && like >= 0)
    {
        post->likes = like;
        todoOk = 1;
    }
    return todoOk;
}

int Post_SetDislikes(ePost* post, int dislike)
{
    int todoOk = 0;

    if(post != NULL && dislike >= 0)
    {
        post->dislikes = dislike;
        todoOk = 1;
    }
    return todoOk;
}




int Post_SetFollowers(ePost* post, int follower)
{
    int todoOk = 0;

    if(post != NULL && follower >= 0)
    {
        post->followers = follower;
        todoOk = 1;
    }
    return todoOk;
}



/*
------------------------------------------------------------------------------------------------

                                          GETTERS

------------------------------------------------------------------------------------------------
*/

int Post_GetIdPost(ePost* post, int* idPost)
{
    int todoOk = 0;

    if(post != NULL && idPost != NULL)
    {
        *idPost = post->id;
        todoOk = 1;
    }
    return todoOk;
}

int Post_GetUser(ePost* post, char* user)
{
    int todoOk = 0;

    if(post != NULL && user != NULL)
    {
        strcpy(user, post->user);
        todoOk = 1;
    }
    return todoOk;
}


int Post_GetLikes(ePost* post, int* likes)
{
    int todoOk = 0;

    if(post != NULL && likes > 0)
    {
        *likes = post->likes;
        todoOk = 1;
    }
    return todoOk;
}


int Post_GetDislikes(ePost* post, int* dislikes)
{
    int todoOk = 0;

    if(post != NULL && dislikes > 0)
    {
        *dislikes = post->dislikes;
        todoOk = 1;
    }
    return todoOk;
}


int Post_GetFollowers(ePost* post, int* followers)
{
    int todoOk = 0;

    if(post != NULL && followers > 0)
    {
        *followers = post->followers;
        todoOk = 1;
    }
    return todoOk;
}



/*
-----------------------------------------------------------------------------

                                 OTRAS FUNCIONES

------------------------------------------------------------------------------
*/



void* Posteos_AsignarEstadisticasLike(void* pElement)
{

    srand(time(NULL));
    int like;
    int min = 600;
    int max = 5000;
    int idP;
    if(pElement != NULL)
    {
        Post_GetIdPost(pElement, &idP);
        for(int i=0; i<=idP;i++)
        {
            srand(rand());
            like = (rand() % (max - min +1) + min);
        }
        Post_SetLikes(pElement, like);
    }
    return pElement;


}



void* Posteos_AsignarEstadisticasDislike(void* pElement)
{

    srand(time(NULL));
    int dislike;
    int min = 300;
    int max = 3500;
    int idP;
    if(pElement != NULL)
    {
        Post_GetIdPost(pElement, &idP);
        for(int i=0; i<=idP;i++)
        {
            srand(rand());
            dislike = (rand() % (max - min +1) + min);
        }
        Post_SetDislikes(pElement, dislike);
    }
    return pElement;


}




void* Posteos_AsignarEstadisticasFollowers(void* pElement)
{

    srand(time(NULL));
    int follower;
    int min = 10000;
    int max = 20000;
    int idP;
    if(pElement != NULL)
    {
        Post_GetIdPost(pElement, &idP);
        for(int i=0; i<=idP;i++)
        {
            srand(rand());
            follower = (rand() % (max - min +1) + min);
        }
        Post_SetFollowers(pElement, follower);
    }
    return pElement;


}


/*
------------------------------------------------------------------------------

                                 FILTROS

------------------------------------------------------------------------------
*/




int filtrar_hater(void* post)
{
    int todoOk = 0;
    ePost* bufferPost = NULL;
    if (post != NULL)
    {
        bufferPost=(ePost*) post;
        if(bufferPost->likes < bufferPost->dislikes)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}





int filtrar_likes(void* post)
{
    int todoOk = 0;
    ePost* bufferPost = NULL;
    if (post != NULL)
    {
        bufferPost = (ePost*) post;

        if (bufferPost->likes > 4000)
        {
           todoOk = 1;
        }
    }
    return todoOk;
}

/*
------------------------------------------------------------------------------

                               COMPARACION

------------------------------------------------------------------------------
*/


int compararFollower(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    int user1;
    int user2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        Post_GetFollowers(pElement1, &user1);
        Post_GetFollowers(pElement2, &user2);
        if(user1 > user2)
        {
            todoOk = 1;
        }
        else
        {
            if(user1 < user2)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}


int compararLikesPost(void* post1, void* post2)
{
    int todoOk= 0;

    if(((ePost*)post1)->likes <
            ((ePost*)post2)->likes)
    {
        todoOk = -1;
    }
    return todoOk;

}


void listadosDePosteos(ePost* this)
{

    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;
    if (this != NULL)
    {

        if (    Post_GetIdPost( this, &id ) &&
                Post_GetUser (this, user ) &&
                Post_GetLikes( this, &likes) &&
                Post_GetDislikes(this, &dislikes)&&
                Post_GetFollowers(this,&followers)
           )
        {
            printf ("%-7d      %-15s          %-8d                %-6d              %-6d \n", id, user, likes, dislikes,followers);

        }
    }


}
