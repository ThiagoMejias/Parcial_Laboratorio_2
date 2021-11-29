/*
 * parser.h
 *
 *  Created on: 23 nov. 2021
 *      Author: Thiago
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "input.h"
#include "LinkedList.h"
#include "editorial.h"
#include "Libro.h"

#endif /* PARSER_H_ */
/// @fn int parser_LibroFromText(FILE*, LinkedList*)
/// @brief parsea los datos de texto a libro
/// @param pFile
/// @param pArrayLibroEmployee
/// @return 0
int parser_LibroFromText(FILE *pFile, LinkedList *pArrayLibroEmployee);
/// @fn int parser_EditorialFromText(FILE*, LinkedList*)
/// @brief parsea los datos de editorial a texto.
/// @param pFile
/// @param pArrayLibroEmployee
/// @return

int parser_EditorialFromText(FILE *pFile, LinkedList *pArrayLibroEmployee);
/// @fn int parser_textFromLibro(FILE*, LinkedList*)
/// @brief parsea los datos de libro a texto
/// @param pFile
/// @param pArrayLibro
/// @return
int parser_textFromLibro(FILE *pFile, LinkedList *pArrayLibro);


