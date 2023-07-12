/*
 * Pelicula.c
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */
#include "Pelicula.h"

eMovie* new_pelicula()
{
	eMovie* peli = NULL;

	peli = (eMovie*) malloc(sizeof(eMovie));

	if(peli != NULL)
	{
		peli_setId(peli, 0);
		peli_setTitulo(peli, "");
		peli_setGenero(peli, "");
		peli_setDuracion(peli, 0);
	}

	return peli;
}

eMovie* new_peliculaParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
	eMovie* peli;
	int id;
	int duracion;

	if(idStr != NULL && tituloStr != NULL &&  generoStr != NULL &&  duracionStr != NULL)
	{
		peli = new_pelicula();
		id = atoi(idStr);
		duracion = atoi(duracionStr);

		if(peli != NULL)
		{
			peli_setId(peli, id);
			peli_setTitulo(peli, tituloStr);
			peli_setGenero(peli, generoStr);
			peli_setDuracion(peli, duracion);
		}
	}

	return peli;
}

int peli_getId(eMovie* peli, int* id)
{
	int retorno = 0;

	if(peli != NULL)
	{
		*id = peli->id;
		retorno = 1;
	}

	return retorno;
}

int peli_setId(eMovie* peli, int id)
{
	int retorno = 0;

	if(peli != NULL)
	{
		peli->id = id;
		retorno = 1;
	}

	return retorno;
}

int peli_getDuracion(eMovie* peli, int* duracion)
{
	int retorno = 0;

	if(peli != NULL)
	{
		*duracion = peli->duracion;
		retorno = 1;
	}

	return retorno;
}

int peli_setDuracion(eMovie* peli, int duracion)
{
	int retorno = 0;

	if(peli != NULL)
	{
		peli->duracion = duracion;
		retorno = 1;
	}

	return retorno;
}

int peli_getTitulo(eMovie* peli, char* titulo)
{
	int retorno = 0;

	if(peli != NULL)
	{
		strcpy(titulo, peli->titulo);
		retorno = 1;
	}

	return retorno;
}

int peli_setTitulo(eMovie* peli, char* titulo)
{
	int retorno = 0;

	if(peli != NULL)
	{
		strcpy(peli->titulo, titulo);
		retorno = 1;
	}

	return retorno;
}

int peli_getGenero(eMovie* peli, char* genero)
{
	int retorno = 0;

	if(peli != NULL)
	{
		strcpy(genero, peli->genero);
		retorno = 1;
	}

	return retorno;
}

int peli_setGenero(eMovie* peli, char* genero)
{
	int retorno = 0;

	if(peli != NULL)
	{
		strcpy(peli->genero, genero);
		retorno = 1;
	}

	return retorno;
}

int MostrarUnaPelicula(eMovie* peli)
{
	int retorno = 0;

	int id;
	char titulo[50];
	char genero[50];
	int duracion;

	if(peli != NULL)
	{
		peli_getId(peli, &id);
		peli_getTitulo(peli, titulo);
		peli_getGenero(peli, genero);
		peli_getDuracion(peli, &duracion);

		printf("| %d | %s | %s | %d |\n", id, titulo, genero, duracion);
		retorno = 1;
	}

	return retorno;
}

int MostrarListaPeliculas(LinkedList* listaPeliculas)
{
	int retorno = 0;
	eMovie* peli;

	if(listaPeliculas != NULL)
	{
		printf("|ID |   TITULO   | GENERO | DURACION |\n");

		for(int i = 0; i<ll_len(listaPeliculas); i++)
		{
			peli = ll_get(listaPeliculas, i);

			if(peli != NULL)
			{
				retorno = MostrarUnaPelicula(peli);
			}
		}
	}

	return retorno;
}

int filtrarDrama(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Drama")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarAdventure(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Adventure")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarComedy(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Comedy")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarDocumentary(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Documentary")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarHorror(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Horror")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarMusical(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Musical")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarAnimation(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Animation")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarAction(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Action")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarThriller(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Thriller")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarWestern(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Western")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int filtrarRomance(void* elemento)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) elemento;

	if(strcmp(peli->genero, "Romance")==0)
	{
		retorno = 1;
	}

	return retorno;
}

int mapearDuracion(void* element)
{
	int retorno = 0;
	eMovie* peli = (eMovie*) element;
	int aleatorio = rand()%((240 - 100) + 1)+ 100;;

	if(peli != NULL)
	{
		retorno = peli_setDuracion(peli, aleatorio);
	}

	return retorno;
}

int ordenarPeliculas(void* element1, void* element2)
{
	int retorno = 0;
	eMovie* peli1 = (eMovie*) element1;
	eMovie* peli2 = (eMovie*) element2;

	char genero1[50];
	char genero2[50];
	int duracion1;
	int duracion2;

	if(peli1 != NULL && peli2 != NULL)
	{
		peli_getGenero(peli1, genero1);
		peli_getGenero(peli2, genero2);
		peli_getDuracion(peli1, &duracion1);
		peli_getDuracion(peli2, &duracion2);

		if(strcmp(genero1, genero2)>0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(genero1, genero2)<0)
			{
				retorno = -1;
			}
			else
			{
				if(duracion1 > duracion2)
				{
					retorno = 1;
				}
				else
				{
					if(duracion1 < duracion2)
					{
						retorno = -1;
					}
					else
					{
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}




