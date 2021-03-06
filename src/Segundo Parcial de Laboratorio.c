/*
 ============================================================================
 Name        : Segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"

#define MINOTAURO "minotauro.csv"
#define MAPEADO "mapeado.csv"
int main(void) {
	setbuf(stdout, NULL);
	int option;
	char archivoLibro[128];
	char archivoEditorial[128];
	LinkedList *listaDeLibros = ll_newLinkedList();
	LinkedList *listaDeEditoriales = ll_newLinkedList();
	LinkedList *listaMinotauro = ll_newLinkedList();

	do {
		option = menuPrincipal();
		switch (option) {
		case 1:
			getString("Ingrese el archivo que desee leer\n", archivoLibro);
			if (ll_isEmpty(listaDeLibros) == 1) {
				if (controller_loadFromTextLibro(archivoLibro, listaDeLibros)
						!= -1) {
					printf("Archivos leidos correctamente\n");

				} else {
					printf("El nombre del archivo es incorrecto\n");
				}

			} else {
				printf("Ya se cargaron los libros\n");
			}
			break;
		case 2:
			getString("Ingrese el archivo que desee leer\n", archivoEditorial);
			if (ll_isEmpty(listaDeEditoriales) == 1) {
				if (controller_loadFromTextEditorial(archivoEditorial,
						listaDeEditoriales) != -1) {
					printf("Archivos leidos correctamente\n");

				} else {
					printf("El nombre del archivo es incorrecto\n");
				}

			} else {

				printf("Ya se cargaron las editoriales\n");
			}

			break;
		case 3:
			if (ll_isEmpty(listaDeLibros) == 0
					&& ll_isEmpty(listaDeEditoriales) == 0) {
				if (confirmacionDeAccion(
						"Desea Ordenar los archivos?, si es asi escriba 'si' de lo contrario ingrese no\n")
						== 0) {
					controller_sortAutor(listaDeLibros);
					printf("Archivos Ordenados Correctamente\n");
				}

			} else {
				printf("Faltan cargar archivos\n");
			}

			break;
		case 4:
			if (ll_isEmpty(listaDeLibros) == 0
					&& ll_isEmpty(listaDeEditoriales) == 0) {
				controller_printLibrosConEditorial(listaDeLibros,
						listaDeEditoriales);
			} else {
				printf("Faltan cargar archivos\n");
			}

			break;
		case 5:
			if (ll_isEmpty(listaDeLibros) == 0
					&& ll_isEmpty(listaDeEditoriales) == 0) {
				if (confirmacionDeAccion(
						"Desea crear un archivo solo con los libros de 'MINOTAURO'?, si es asi escriba 'si' de lo contrario ingrese no\n")
						== 0) {
					listaMinotauro = ll_filter(listaDeLibros,
							libro_esDeMinotaro);
					controller_saveAsText(MINOTAURO, listaMinotauro);
					printf("Archivo creado con exito\n");
				}

			} else {
				printf("Faltan cargar archivos\n");
			}

			break;
		case 6:
			if (ll_isEmpty(listaDeLibros) == 0
					&& ll_isEmpty(listaDeEditoriales) == 0) {
				if (confirmacionDeAccion(
						"Desea Aplicar descuentos?, si es asi escriba 'si' de lo contrario ingrese no\n")
						== 0) {

					ll_map(listaDeLibros, libro_modificarSegunPrecio);
					controller_saveAsText(MAPEADO, listaDeLibros);
					printf("Descuentos Aplicados:\n");
					controller_printLibrosConEditorial(listaDeLibros,
							listaDeEditoriales);
					printf("Archivo creado con exito\n");
				}

			} else {
				printf("Faltan cargar archivos\n");
			}
			break;
		}

	} while (option != 7);
	ll_deleteLinkedList(listaMinotauro);
	ll_deleteLinkedList(listaDeEditoriales);
	ll_deleteLinkedList(listaDeLibros);

	return 0;
}
