/*
 * libro.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Thiago
 */

#include "libro.h"

int libro_setId(Libro *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->id = id;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}
int libro_setPrecio(Libro *this, float precio) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->precio = precio;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}
int libro_setIdEditorial(Libro *this, int idEditorial) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		this->idEditorial = idEditorial;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}
int libro_setTitulo(Libro *this, char *titulo) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(this->titulo, titulo);
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}
int libro_setAutor(Libro *this, char *autor) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(this->autor, autor);
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int libro_getId(Libro *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*id = this->id;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int libro_getPrecio(Libro *this, float *precio) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*precio = this->precio;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int libro_getIdEditorial(Libro *this, int *idEditorial) {
	int retorno;
	retorno = -1;
	if (this != NULL) {
		*idEditorial = this->idEditorial;

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int libro_getTitulo(Libro *this, char *titulo) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

int libro_getAutor(Libro *this, char *autor) {
	int retorno;

	retorno = -1;
	if (this != NULL) {
		strcpy(autor, this->autor);
		retorno = 0;

	} else {
		printf("Ocurrio un error\n");
	}
	return retorno;
}

Libro* libro_new() {

	Libro *retorno;

	retorno = (Libro*) calloc(1, sizeof(Libro));

	return retorno;
}

Libro* libro_newParametros(char id[128], char titulo[128], char autor[128],
		char precio[128], char idEditorial[128]) {

	Libro *newLibro;
	newLibro = libro_new();

	if (newLibro != NULL) {
		libro_setAutor(newLibro, autor);
		libro_setId(newLibro, atoi(id));
		libro_setIdEditorial(newLibro, atoi(idEditorial));
		libro_setPrecio(newLibro, atof(precio));
		libro_setTitulo(newLibro, titulo);
	} else {
		printf("Ocurrio un error\n");
	}

	return newLibro;
}

int libro_esDeMinotaro(void *elemento) {
	int retorno;
	int idEditorialLibro;
	Libro *libro;
	retorno = 0;
	if (elemento != NULL) {
		libro = (Libro*) elemento;
		libro_getIdEditorial(libro, &idEditorialLibro);
		if (idEditorialLibro == 4) {
			retorno = 1;
		}

	}

	return retorno;
}

int libro_comparadordDeAutor(void *uno, void *dos) {
	Libro *primerLibro;
	Libro *segundoLibro;
	int retorno;
	char autorUno[128];
	char autorDos[128];
	retorno = -1;
	primerLibro = (Libro*) uno;
	segundoLibro = (Libro*) dos;
	if (libro_getAutor(primerLibro, autorUno) == 0
			&& libro_getAutor(segundoLibro, autorDos) == 0) {
		retorno = stricmp(autorUno, autorDos);
	}

	return retorno;
}



