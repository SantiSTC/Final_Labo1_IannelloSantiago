/*
 * parser.c
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#include "parser.h"

int parser_peliculasFromText(FILE* pFile, LinkedList* listaPeliculas)
{
	int retorno = 0;
	int cant;

	char idStr[50];
	char tituloStr[50];
	char generoStr[50];
	char duracionStr[50];

	eMovie* peli;

	if(pFile != NULL && listaPeliculas != NULL)
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, generoStr, duracionStr);

		if(cant == 4)
		{
			do
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, generoStr, duracionStr);

				if(cant == 4)
				{
					peli = new_peliculaParametros(idStr, tituloStr, generoStr, duracionStr);

					if(peli != NULL)
					{
						ll_add(listaPeliculas, peli);
						retorno = 1;
					}
					else
					{
						free(peli);
					}
				}

			}while(!feof(pFile));
		}
	}

	return retorno;
}

int parser_textFromPeliculas(FILE* pFile, LinkedList* listaPeliculas)
{
	int retorno = 0;

	int id;
	char titulo[50];
	char genero[50];
	int duracion;

	eMovie* peli;

	if(pFile != NULL && listaPeliculas != NULL)
	{
		fprintf(pFile, "%s,%s,%s,%s\n", "id", "titulo", "genero", "duracion");

		for(int i=0; i<ll_len(listaPeliculas); i++)
		{
			peli = ll_get(listaPeliculas, i);

			if(peli != NULL && peli_getId(peli, &id) && peli_getTitulo(peli, titulo) && peli_getGenero(peli, genero) && peli_getDuracion(peli, &duracion))
			{
				fprintf(pFile, "%d, %s, %s, %d\n", id,titulo,genero,duracion);
				retorno = 1;
			}
		}
	}

	return retorno;
}
