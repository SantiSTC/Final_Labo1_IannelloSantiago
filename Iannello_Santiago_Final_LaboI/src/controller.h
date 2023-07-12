/*
 * controller.h
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "utn.h"
#include "Pelicula.h"
#include "parser.h"
#include "func.h"

int controller_parserPeliculasFromText(char* path, LinkedList* listaPeliculas);
int controller_imprimirLista(LinkedList* listaPeliculas);
int controller_filtrarPorGenero(LinkedList* pArrayPelis);
int controller_parserTextFromPeliculas(char* path, LinkedList* listaPeliculas);
int controller_asignarTiempos(LinkedList* listaPeliculas);
int controller_ordenarPeliculas(LinkedList* listaPeliculas);

#endif /* CONTROLLER_H_ */
