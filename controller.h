#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


/** \brief muestra un menu de opciones
 *
 * \return int devuelve la opcion seleccionada.
 *
 */
int controller_menuInicio();

/** \brief confirma la salida del programa
 *
 * \param x char x es la opcion seleccionada.
 *
 */
void controller_confirmarSalida (char* x);


/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListPosteos LinkedList*
 * \return int retorna 1 en caso de exito, 0 en caso de error y -1 en caso de que la lista tenga datos
 *
 */
int controller_cargarPostDesdeTexto(char* path, LinkedList* pArrayListPosteos);


//\brief Listado de posteos
//
// \param pArrayPosteos Lista a mostrar
// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_imprimirPosteos(LinkedList* pArrayPosteos);




// \brief Funcion que llama a map para asignar la estadistica de likes de manera aleatorio a la estructura pelicula
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error

LinkedList* controller_AsignarEstadisticasLike(LinkedList* pArrayPosteos);



// \brief Funcion que llama a map para asignar la estadistica de dislikes de manera aleatorio a la estructura pelicula
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error
LinkedList* controller_AsignarEstadisticasDislike(LinkedList* pArrayPosteos);


// \brief Funcion que llama a map para asignar la estadistica de followers de manera aleatorio a la estructura pelicula
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error
LinkedList* controller_AsignarEstadisticasFollowers(LinkedList* pArrayPosteos);




// // \brief Funcion que llama a filter y determinar las cantidades de dislikes
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_filtrarHater(LinkedList* pArrayListPost);


// \brief Funcion que llama a filter y determinar las cantidades de likes
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_filtrarLikes(LinkedList* pArrayPosteos);


/** \brief Guarda los datos de los posteos en el archivo(modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListPosteos LinkedList*
 * \return int retorna 1 en caso de exito y 0 en caso de error
 *
 */
int controller_guardarPostDesdeTexto(char* path, LinkedList* pArrayListPost);



// \brief Funcion que determina el user con mayor likes en el programa.
//
// \param pArrayPosteos Puntero a posteo
// \return Retorna 1 en caso de exito y 0 en caso de error
int controller_postConMasLikes(LinkedList* pArrayListPost);
