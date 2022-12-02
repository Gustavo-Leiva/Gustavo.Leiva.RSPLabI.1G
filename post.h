#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

typedef struct
{
    int id;
    char user[20];
    int likes;
    int dislikes;
    int followers;

}ePost;

#endif // POST_H_INCLUDED


// \brief Muestra  de posteos
//
// \return retorna datos a posteos

void Post_mostrar(ePost unPost);



// \brief Muestra  de posteos
//
// \return retorna datos a posteos
void Post_mostrarDinamico(ePost* pPost);

// \brief Constructor por defecto de posteos
//
// \return retorna puntero a posteos
ePost* Post_new();



ePost* Post_new_Param(int idPost, char* user, int likes, int dislikes, int followers);


// \brief Constructor por parametros de posteos
//
// \param idPost id en forma de char
// \param user  en forma de char
// \param likes  en forma de char
// \param dislikes  en forma de char
// \param followers  en forma de char
// \return
ePost* Post_newStr(char* idPost, char* user, char* likes, char* dislikes, char* followers);


//setters

// \brief Setter de id
//
// \param post puntero a posteo
// \param idPost de id a cargar
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_SetIdPost(ePost* post, int idPost);



// \brief Setter de User
//
// \param post puntero a posteo
// \param user valor de usuario a cargar
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_SetUser(ePost* post, char* user);


// \brief Setter de Likes
//
// \param post puntero a posteo
// \param user valor de likes a cargar
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_SetLikes(ePost* post, int like);



// \brief Setter de Dislikes
//
// \param post puntero a posteo
// \param user valor de dislikes a cargar
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_SetDislikes(ePost* post, int dislike);




// \brief Setter de Followers
//
// \param post puntero a posteo
// \param user valor de followers a cargar
// \return retorna 1 en caso de exito y 0 en caso de error

int Post_SetFollowers(ePost* post, int follower);



//getters

// \brief Getter de id
//
// \param post Puntero a posteo
// \param idPost variable que almacena id
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_GetIdPost(ePost* post, int* idPost);



// \brief Getter de user
//
// \param post Puntero a posteo
// \param user variable que almacena usuario
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_GetUser(ePost* post, char* user);




// \brief Getter de likes
//
// \param post Puntero a posteo
// \param likes variable que almacena like
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_GetLikes(ePost* post, int* likes);




// \brief Getter de dislike
//
// \param post Puntero a posteo
// \param dislikes variable que almacena dislikes
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_GetDislikes(ePost* post, int* dislikes);




// \brief Getter de followers
//
// \param post Puntero a posteo
// \param followers variable que almacena followers
// \return retorna 1 en caso de exito y 0 en caso de error
int Post_GetFollowers(ePost* post, int* followers);



// \brief recibe un elemnto y asigna un valor al campo estadistica.
//
// \param void recibe un elmento void
// \return
void* Posteos_AsignarEstadisticasLike(void* pElement);


// \brief recibe un elemnto y asigna un valor al campo estadistica.
//
// \param void recibe un elmento void
// \return
void* Posteos_AsignarEstadisticasDislike(void* pElement);



// \brief recibe un elemnto y asigna un valor al campo estadistica.
//
// \param void recibe un elmento void
// \return
void* Posteos_AsignarEstadisticasFollowers(void* pElement);



// \brief Crea un nuevo listado en base al criterio de filtrado seleccionado
//
// \param post Lista de posteos
// \return retorna 1 en caso de poder crear el archivo filtrado y 0 en caso de error
int filtrar_hater(void* post);

// \brief Crea un nuevo listado en base al criterio de filtrado seleccionado
//
// \param post Lista de posteos
// \return retorna 1 en caso de poder crear el archivo filtrado y 0 en caso de error
int filtrar_likes(void* post);


// \brief compara dos elementos del listado
//
// \param pElment1 elemento a comparar
// \param pElment2 elemento a comparar
// \return retorna 1 en caso de poder comparar los elmentos  y 0 en caso de error

int compararFollower(void* pElement1, void* pElement2);


// \brief compara dos elementos del listado
//
// \param pElment1 elemento a comparar
// \param pElment2 elemento a comparar
// \return retorna 1 en caso de poder comparar los elmentos  y 0 en caso de error
int compararLikesPost(void* post1, void* post2);



//\brief Listado de posteos
//
// \param this Lista a mostrar
// \return Retorna 1 en caso de exito y 0 en caso de error
void listadosDePosteos(ePost* this);

