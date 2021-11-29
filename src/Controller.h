// nexo-

#include "input.h"
#include "LinkedList.h"
#include "parser.h"
#include "Libro.h"
#include "editorial.h"

int controller_loadFromTextEditorial(char *path, LinkedList *parray);

int controller_loadFromTextLibro(char *path, LinkedList *parray);

/// @fn int controller_encontrarEditorialPorId(LinkedList*, LinkedList*, int)
/// @brief busca la editorial que coincida con esa id.
/// @param pArrayEditorial
/// @param idAbuscar
/// @return retorna -1 si no encontro el id o uno de los punteros es NULL o  la posicion de la editorial.
int controller_encontrarEditorialPorId(LinkedList *pArrayEditorial,
		int idAbuscar);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @param path
/// @param pArrayLibros
/// @return
int controller_saveAsText(char *path, LinkedList *pArrayLibros);
/// @fn int controller_sortAutor(LinkedList*)
/// @brief ordena lalista de forma ascendente por autor
/// @param pArrayLibros
/// @return retorna -1 si el puntero es NULL o 0 si se pudo concretar
int controller_sortAutor(LinkedList *pArrayLibros);

int menuPrincipal();

/// @fn int controller_printLibrosConEditorial(LinkedList*, LinkedList*)
/// @brief printea todos los libros con su editorial
/// @param pArrayLibros
/// @param pArrayEditorial
/// @return retorna -1 si el puntero es NULL o 0 si se pudo concretar
int controller_printLibrosConEditorial(LinkedList *pArrayLibros,
		LinkedList *pArrayEditorial);

/// @fn int printLibroConEditorial(Libro*, LinkedList*, LinkedList*)
/// @brief printea su libro con la editorial
/// @param auxLibro
/// @param pArrayLibros
/// @param pArrayEditorial
/// @return  retorna -1 si el puntero es NULL o 0 si se pudo concretar
int printLibroConEditorial(Libro *auxLibro, LinkedList *pArrayLibros,
		LinkedList *pArrayEditorial);

