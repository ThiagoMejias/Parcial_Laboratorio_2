/*
 * parser.c
 *
 *  Created on: 23 nov. 2021
 *      Author: Thiago
 */

#include "parser.h"

int parser_LibroFromText(FILE *pFile, LinkedList *pArrayLibro) {
	Libro *aux;

	int retorno;
	char id[128];
	char nombre[128];
	char autor[128];
	char precio[128];
	char idEditorial[128];

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, autor,
			precio, idEditorial);
	do {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, autor,
				precio, idEditorial);

		aux = libro_newParametros(id, nombre, autor, precio, idEditorial);
		if (aux != NULL) {
			ll_add(pArrayLibro, aux);
		} else {
			printf("Ocurrio Un error\n");
		}

		retorno = 0;

	} while (!feof(pFile));

	return retorno;
}

int parser_EditorialFromText(FILE *pFile, LinkedList *pArrayEditorial) {

	editorial *aux;
	char id[128];
	char nombre[128];

	do {
		fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
		aux = editorial_newParametros(id, nombre);
		if (aux != NULL) {
			ll_add(pArrayEditorial, aux);
		} else {
			printf("Ocurrio Un error\n");
		}

	} while (!feof(pFile));;
	return 0;
}

int parser_textFromLibro(FILE *pFile, LinkedList *pArrayLibro) {
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
	int retorno;
	int tam;
	Libro *aux;
	retorno = -1;

	if (pArrayLibro != NULL && pFile != NULL) {

		tam = ll_len(pArrayLibro);
		fprintf(pFile, "id,titulo,autor,precio,id editorial\n");
		for (int i = 0; i < tam; i++) {
			aux = ll_get(pArrayLibro, i);
			libro_getId(aux, &id);
			libro_getAutor(aux, autor);
			libro_getPrecio(aux, &precio);
			libro_getIdEditorial(aux, &idEditorial);
			libro_getTitulo(aux, titulo);
			fprintf(pFile, "%d,%s,"
					"%s,%.2f,%d\n ", id, titulo, autor, precio, idEditorial);

		}

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;

}


