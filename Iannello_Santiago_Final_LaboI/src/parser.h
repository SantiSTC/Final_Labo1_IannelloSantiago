/*
 * parser.h
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "utn.h"
#include "LinkedList.h"
#include "Pelicula.h"

int parser_peliculasFromText(FILE* pFile, LinkedList* listaPeliculas);
int parser_textFromPeliculas(FILE* pFile, LinkedList* listaPeliculas);


#endif /* PARSER_H_ */
