/*
 * libro.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Thiago
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct {
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
} Libro;
#include "input.h"
#endif /* LIBRO_H_ */
/// @fn Libro libro_new*()
/// @brief construye un Libro en memoria dinamica
/// @return retorna el Libro nuevo.
Libro* libro_new();
/// @fn Libro libro_newParametros*(char[], char[], char[], char[], char[])
/// @brief le ingresa los parametros a los campos correspondientes de la estructura Libro
/// @param id
/// @param nombre
/// @param autor
/// @param precio
/// @param idEditorial
/// @return retorna el puntero a Libro
Libro* libro_newParametros(char id[128], char nombre[128], char autor[128],
		char precio[128], char idEditorial[128]);

// Seters.
/// @fn int libro_setId(Libro*, int)
/// @brief setea el id dentro del libro.
/// @param this Libro
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null
int libro_setId(Libro *this, int id);
/// @fn int libro_setTitulo(Libro*, char*)
/// @brief setea el titulo dentro del campo correspondiente.
/// @param this Libro
/// @param titulo
/// @return retorna 0 si se pudo o -1 si el puntero es null
int libro_setTitulo(Libro *this, char *titulo);
/// @fn int libro_setAutor(Libro*, char*)
/// @brief setea el autor dentro del campo correspondiente.
/// @param this
/// @param autor
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_setAutor(Libro *this, char *autor);
/// @fn int libro_setPrecio(Libro*, int)
/// @brief setea el precio dentro del campo correspondiente.
/// @param this
/// @param precio
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_setPrecio(Libro *this, float precio);
/// @fn int libro_setIdEditorial(Libro*, int)
/// @brief setea el id del editorial dentro del campo correspondiente.
/// @param this
/// @param idEditorial
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_setIdEditorial(Libro *this, int idEditorial);

/// @fn int libro_getTitulo(Libro*, char*)
/// @brief ingresa el titulo dentro del campo correspondiente
/// @param this
/// @param titulo
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_getTitulo(Libro *this, char *titulo);
/// @fn int libro_getId(Libro*, int)
/// @brief ingresa el id dentro del campo correspondiente
/// @param this
/// @param id
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_getId(Libro *this, int *id);
/// @fn int libro_getIdEditorial(Libro*, int)
/// @brief ingresa el id del editorial dentro del campo correspondiente
/// @param this
/// @param idEditorial
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_getIdEditorial(Libro *this, int *idEditorial);
/// @fn int libro_getPrecio(Libro*, float)
/// @brief ingresa el precio del editorial dentro del campo correspondiente
/// @param this
/// @param precio
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_getPrecio(Libro *this, float *precio);
/// @fn int libro_getAutor(Libro*, char*)
/// @brief ingresa el autor del editorial dentro del campo correspondiente
/// @param this
/// @param autor
/// @return retorna 0 si se pudo o -1 si el puntero es null.
int libro_getAutor(Libro *this, char *autor);
/// @fn int libro_comparadordDeAutor(void*, void*)
/// @brief compara los autores de los libros.
/// @param uno
/// @param dos
/// @return retorna el resultado de la comparacino
int libro_comparadordDeAutor(void *uno, void *dos);
/// @fn int libro_esDeMinotaro(void*)
/// @brief valida si un elemento es de la editorial minotauro
/// @param elemento
/// @return retorna 0 si no lo es y 1 si lo es
int libro_esDeMinotaro(void *elemento);


