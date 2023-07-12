/*
 ============================================================================
 Name        : Iannello_Santiago_Final_LaboI.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#include "LinkedList.h"
#include "controller.h"

int main(void) {
	setbuf(stdout,NULL);

	srand (time(NULL));

	int opcion;
	char path[50];
	int flagArchivo = 0;

	LinkedList* listaPeliculas = ll_newLinkedList();

	do
	{
		opcion = MenuPrincipal();

		switch(opcion)
		{
			case 1:
				if(!flagArchivo)
				{
					/*
					getString("Ingrese el nombre del archivo a abrir: ", path);
					while(strcmp(path, "movies.csv") != 0)
					{
						getString("ERROR, no se ha encontrado, Ingrese nuevamente el nombre del archivo a abrir: ", path);
					}
					*/

					controller_parserPeliculasFromText("movies.csv", listaPeliculas);
					flagArchivo = 1;
				}
			break;
			case 2:
				if(flagArchivo)
				{
					controller_imprimirLista(listaPeliculas);
				}
			break;
			case 3:
				if(flagArchivo)
				{
					controller_asignarTiempos(listaPeliculas);
				}
			break;
			case 4:
				if(flagArchivo)
				{
					controller_filtrarPorGenero(listaPeliculas);
				}
			break;
			case 5:
				if(flagArchivo)
				{
					controller_ordenarPeliculas(listaPeliculas);
				}
			break;
			case 6:
				if(flagArchivo)
				{
					controller_parserTextFromPeliculas("movies.csv", listaPeliculas);
				}
			break;
		}

	}while(opcion != 7);

	return 0;
}
