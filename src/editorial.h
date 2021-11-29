/*
 * editorial.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Thiago
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "input.h"
typedef struct {
	int idEditorial;
	char nombre[128];

} editorial;

#endif /* EDITORIAL_H_ */

/// @fn editorial editorial_new()
/// @brief construye un editorial en memoria dinamica
/// @return
editorial* editorial_new();

/// @fn editorial editorial_newParametros(char[], char[])
/// @brief le ingresa los parametros a los campos correspondientes de la estructura editorial
/// @param id
/// @param nombre
/// @return
editorial* editorial_newParametros(char id[128], char nombre[128]);

/// @fn int editorial_setId(editorial*, int)
/// @brief Setea el id recibido por parametro en el campo de la editorial que corresponda.
/// @param this
/// @param id
/// @return retorna -1 si el puntero es NULL, 0 si no lo es.
int editorial_setId(editorial *this, int id);

/// @fn int editorial_setNombre(editorial*, char*)
/// @brief Setea el nombre recibido por parametro en el campo de la editorial que corresponda.
/// @param this
/// @param nombre
/// @return retorna -1 si el puntero es NULL, 0 si no lo es.
int editorial_setNombre(editorial *this, char *nombre);
/// @fn int editorial_getNombre(editorial*, char*)
/// @brief retorna el nombre de la editorial recibida como parametro.
/// @param nombre
/// @return retorna -1 si el puntero es NULL, 0 si no lo es.
int editorial_getNombre(editorial *this, char *nombre);
/// @fn int editorial_getId(editorial*, int)
/// @brief retorna el id de la editorial recibida como parametro.
/// @param this
/// @param id
/// @return retorna -1 si el puntero es NULL, 0 si no lo es.
int editorial_getId(editorial *this, int *id);

