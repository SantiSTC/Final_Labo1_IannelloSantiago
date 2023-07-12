/*
 * controller.c
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#include "controller.h"

int controller_parserPeliculasFromText(char* path, LinkedList* listaPeliculas)
{
	int retorno = 0;

	FILE* pFile = fopen(path, "r");

	retorno = parser_peliculasFromText(pFile, listaPeliculas);

	fclose(pFile);

	return retorno;
}

int controller_parserTextFromPeliculas(char* path, LinkedList* listaPeliculas)
{
	int retorno = 0;

	FILE* pFile = fopen(path, "w");

	retorno = parser_textFromPeliculas(pFile, listaPeliculas);

	fclose(pFile);

	return retorno;
}

int controller_imprimirLista(LinkedList* listaPeliculas)
{
	int retorno = MostrarListaPeliculas(listaPeliculas);

	return retorno;
}

int controller_filtrarPorGenero(LinkedList* listaPeliculas)
{
	int retorno;
	int opcion = MenuGeneros();

	LinkedList* listaFiltrada;
	FILE* pFile;
	char path[50];

	switch(opcion)
	{
		case 1:
			listaFiltrada = ll_filter(listaPeliculas, filtrarDrama);
			strcpy(path, "drama.csv");
		case 2:
			listaFiltrada = ll_filter(listaPeliculas, filtrarAdventure);
			strcpy(path, "adventure.csv");
		break;
		case 3:
			listaFiltrada = ll_filter(listaPeliculas, filtrarComedy);
			strcpy(path, "comedy.csv");
		break;
		case 4:
			listaFiltrada = ll_filter(listaPeliculas, filtrarDocumentary);
			strcpy(path, "documentary.csv");
		break;
		case 5:
			listaFiltrada = ll_filter(listaPeliculas, filtrarHorror);
			strcpy(path, "horror.csv");
		break;
		case 6:
			listaFiltrada = ll_filter(listaPeliculas, filtrarMusical);
			strcpy(path, "musical.csv");
		break;
		case 7:
			listaFiltrada = ll_filter(listaPeliculas, filtrarAnimation);
			strcpy(path, "animation.csv");
		break;
		case 8:
			listaFiltrada = ll_filter(listaPeliculas, filtrarAction);
			strcpy(path, "action.csv");
		break;
		case 9:
			listaFiltrada = ll_filter(listaPeliculas, filtrarThriller);
			strcpy(path, "thriller.csv");
		break;
		case 10:
			listaFiltrada = ll_filter(listaPeliculas, filtrarWestern);
			strcpy(path, "western.csv");
		break;
		case 11:
			listaFiltrada = ll_filter(listaPeliculas, filtrarRomance);
			strcpy(path, "romance.csv");
		break;
	}

	pFile = fopen(path, "w");
	retorno = controller_parserTextFromPeliculas(path, listaFiltrada);
	fclose(pFile);

	//retorno = controller_imprimirLista(listaFiltrada);

	return retorno;
}

int controller_asignarTiempos(LinkedList* listaPeliculas)
{
	int retorno = 0;
	/*
	LinkedList* listaMapeada = ll_newLinkedList();

	if(listaMapeada != NULL)
	{
		listaMapeada = ll_map(listaPeliculas, mapearDuracion);

		retorno = controller_imprimirLista(listaMapeada);
	}
	*/

	listaPeliculas = ll_map(listaPeliculas, mapearDuracion);

	retorno = controller_imprimirLista(listaPeliculas);

	return retorno;
}

int controller_ordenarPeliculas(LinkedList* listaPeliculas)
{
	int retorno;

	retorno = ll_sort(listaPeliculas, ordenarPeliculas, 0);

	controller_imprimirLista(listaPeliculas);

	return retorno;
}
