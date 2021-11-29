#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromTextLibro(char *path, LinkedList *parray) {
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "r");
	if (pFile != NULL) {
		parser_LibroFromText(pFile, parray);
		retorno = 0;
	}
	fclose(pFile);
	return retorno;
}

int controller_loadFromTextEditorial(char *path, LinkedList *parray) {
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "r");

	if (pFile != NULL) {
		parser_EditorialFromText(pFile, parray);
		retorno = 0;
	}

	fclose(pFile);
	return retorno;
}

int controller_encontrarEditorialPorId(LinkedList *pArrayEditorial,
		int idAbuscar) {
	editorial *aux;
	int tamEditorial;
	int idAuxiliar;
	int retorno = -1;
	if (pArrayEditorial != NULL) {
		tamEditorial = ll_len(pArrayEditorial);

		for (int i = 0; i < tamEditorial; i++) {
			aux = ll_get(pArrayEditorial, i);
			editorial_getId(aux, &idAuxiliar);
			if (idAbuscar == idAuxiliar) {
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

int controller_sortAutor(LinkedList *pArrayLibros) {
	int retorno;
	retorno = -1;
	if (pArrayLibros != NULL) {

		ll_sort(pArrayLibros, libro_comparadordDeAutor, 1);

		retorno = 0;
	}

	return retorno;
}

int controller_saveAsText(char *path, LinkedList *pArrayLibros) {

	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen(path, "w");
	if (pFile != NULL) {

		parser_textFromLibro(pFile, pArrayLibros);

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}
	fclose(pFile);
	return retorno;

	return 1;
}

int controller_printLibrosConEditorial(LinkedList *pArrayLibros,
		LinkedList *pArrayEditorial) {
	Libro *auxLibro;
	int retorno;
	int tam;
	retorno = -1;
	if (pArrayLibros != NULL && pArrayEditorial != NULL) {
		tam = ll_len(pArrayLibros);
		printf(
				"__________________________________________________________________________________________________\n"
						"|id   |titulo                          |autor                 |precio  |Editorial                |\n"
						"|_____|________________________________|______________________|________|_________________________|\n");
		for (int i = 0; i < tam; i++) {
			auxLibro = (Libro*) ll_get(pArrayLibros, i);
			printLibroConEditorial(auxLibro, pArrayLibros, pArrayEditorial);
		}

		retorno = 0;
	}

	return retorno;
}

int printLibroConEditorial(Libro *auxLibro, LinkedList *pArrayLibros,
		LinkedList *pArrayEditorial) {
	editorial *auxEditorial;
	int retorno;
	int id;
	char titulo[128];
	char autor[128];
	char descripcionEditorial[128];
	float precio;
	int idEditorial;
	int pos;
	retorno = -1;
	if (auxLibro != NULL) {
		libro_getId(auxLibro, &id);
		libro_getPrecio(auxLibro, &precio);
		libro_getIdEditorial(auxLibro, &idEditorial);
		libro_getAutor(auxLibro, autor);
		libro_getTitulo(auxLibro, titulo);
		pos = controller_encontrarEditorialPorId(pArrayEditorial, idEditorial);
		if (pos != -1) {
			auxEditorial = ll_get(pArrayEditorial, pos);
			editorial_getNombre(auxEditorial, descripcionEditorial);
			printf("|%5d|%32s|%22s|%8.2f|%25s|\n", id, titulo, autor, precio,
					descripcionEditorial);

		} else {
			printf("Algo ocurrio mal\n");
		}

		retorno = 0;
	} else {
		printf("Ocurrio un error\n");
	}

	return retorno;
}

int menuPrincipal() {
	int retorno;
	printf("Menu\n"
			"1-Cargar la informacion de libros\n"
			"2-Cargar la informacion de las editoriales\n"
			"3-Ordenar la lista de forma ascendente por autor\n"
			"4-Listar Los libros\n"
			"5-Realizar una listado de los libros de la editorial Minotauro\n"
			"6-Crear Lista con descuentos\n"
			"7-Salir\n");
	getIntWithParams("Ingrese una opcion\n", "Ingrese una opcion valida\n",
			&retorno, 1, 7);
	return retorno;
}

