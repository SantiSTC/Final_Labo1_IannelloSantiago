/*
 * func.c
 *
 *  Created on: 6 jul. 2023
 *      Author: santi
 */

#include "func.h"

int ElegirOpcion(int min, int max)
{
	int validar;
	int opcion;
	char opcionAux[50];

	validar = getStringNumeros("Ingrese una opcion: ", opcionAux);
	opcion = atoi(opcionAux);
	while(validar == 0 || (opcion > max || opcion < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opcion valida: ", opcionAux);
		opcion = atoi(opcionAux);
	}

	return opcion;
}

int MenuPrincipal()
{
	int opcion;

	printf("=== Menu Principal ===\n"
			"1.Cargar archivo\n"
			"2.Imprimir lista\n"
			"3.Asignar tiempo\n"
			"4.Filtrar por tipo \n"
			"5.Mostrar duraciones\n"
			"6.Guardar peliculas\n"
			"7.Salir\n");

	opcion = ElegirOpcion(1,7);

	return opcion;
}

int MenuGeneros()
{
	int opcion;

	printf("\n=== Generos ===\n"
			"1.Drama\n"
			"2.Adventure\n"
			"3.Comedy\n"
			"4.Documentary\n"
			"5.Horror\n"
			"6.Musical\n"
			"7.Animation\n"
			"8.Action\n"
			"9.Thriller\n"
			"10.Western\n"
			"11.Romance\n");

	opcion = ElegirOpcion(1,11);

	return opcion;
}
