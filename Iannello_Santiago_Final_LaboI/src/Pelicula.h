/*
 * Pelicula.h
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#ifndef PELICULA_H_
#define PELICULA_H_

#include "utn.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char titulo[50];
	char genero[50];
	int duracion;
}eMovie;

eMovie* new_pelicula();
eMovie* new_peliculaParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr);
int peli_getId(eMovie* peli, int* id);
int peli_setId(eMovie* peli, int id);
int peli_getDuracion(eMovie* peli, int* duracion);
int peli_setDuracion(eMovie* peli, int duracion);
int peli_getTitulo(eMovie* peli, char* titulo);
int peli_setTitulo(eMovie* peli, char* titulo);
int peli_getGenero(eMovie* peli, char* genero);
int peli_setGenero(eMovie* peli, char* genero);
int MostrarUnaPelicula(eMovie* peli);
int MostrarListaPeliculas(LinkedList* listaPeliculas);
int filtrarDrama(void* elemento);
int filtrarAdventure(void* elemento);
int filtrarComedy(void* elemento);
int filtrarDocumentary(void* elemento);
int filtrarHorror(void* elemento);
int filtrarMusical(void* elemento);
int filtrarAnimation(void* elemento);
int filtrarAction(void* elemento);
int filtrarThriller(void* elemento);
int filtrarWestern(void* elemento);
int filtrarRomance(void* elemento);
int mapearDuracion(void* element);
int ordenarPeliculas(void* element1, void* element2);


#endif /* PELICULA_H_ */
