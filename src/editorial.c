/*
 * editorial.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Thiago
 */
#include "editorial.h"

editorial* editorial_new() {
	editorial *aux;

	aux = (editorial*) calloc(1, sizeof(editorial));

	return aux;
}

editorial* editorial_newParametros(char id[128], char nombre[128]) {
	editorial *aux;
	aux = NULL;
	aux = (editorial*) calloc(1, sizeof(editorial));
	if (aux != NULL) {
		editorial_setId(aux, atoi(id));
		editorial_setNombre(aux, nombre);
	} else {
		printf("Ocurrio un error\n");
	}

	return aux;
}

int editorial_setId(editorial *this, int id) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		this->idEditorial = id;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int editorial_setNombre(editorial *this, char *nombre) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

int editorial_getNombre(editorial *this, char *nombre) {
	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;

}

int editorial_getId(editorial *this, int *id) {
	int retorno;
	retorno = -1;

	if (this != NULL) {
		*id = this->idEditorial;
		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

