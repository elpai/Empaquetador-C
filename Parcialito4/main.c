#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"

int main(){
	T_pelicula peli1;
	T_pelicula peli2;
	T_pelicula peli3;
	char * cadena;
	int puntaje_anterior;

	cadena = malloc (sizeof (char));
	peli1 = t_p_crear ("Cocacola", "Pait", "Rodrigo", 300, 3, 2014);
	peli2 = t_p_crear ("Apple", "Bigote", "Yo", 550, 1, 2016);
	peli3 = t_p_crear ("Mate", "Termo", "Yerba", 10, 3, 2015);
	printf ("|%-15s| |%-15s| |%-15s| |%-15s| |%-15s| |%-15s| |%-16s|\n", "Pelicula", "Titulo", "Director/a", "Protagonista", "Presupuesto", "Puntaje", "Año");
	printf ("|%-15s| |%-15s| |%-15s| |%-15s| |%-15d| |%-15d| |%-15d|\n", "Peli 1", peli1.titulo, peli1.director, peli1.protagonista, peli1.presupuesto, peli1.puntaje, peli1.anio);
	printf ("|%-15s| |%-15s| |%-15s| |%-15s| |%-15d| |%-15d| |%-15d|\n", "Peli 2", peli2.titulo, peli2.director, peli2.protagonista, peli2.presupuesto, peli2.puntaje, peli2.anio);
	printf ("|%-15s| |%-15s| |%-15s| |%-15s| |%-15d| |%-15d| |%-15d|\n", "Peli 3", peli3.titulo, peli3.director, peli3.protagonista, peli3.presupuesto, peli3.puntaje, peli3.anio);
	printf ("La pelicula 1 tiene %d puntaje con respecto a la pelucula 2\n", t_p_cmp_puntaje(&peli1,&peli2));
	puntaje_anterior = peli2.puntaje;
	t_p_sumar_puntaje (&peli2, 4);
	printf ("A la pelicula 2 que tiene %d de puntaje le sumo 4 y queda en %d\n", puntaje_anterior, peli2.puntaje);
	t_p_a_cadena (&peli3, cadena);
	printf ("la pelicula 3 es %s\n", cadena);
	free (cadena);
	printf("Se libero el espacio de la variable 'cadena'\n");
	t_p_destruir(&peli1);
	t_p_destruir(&peli2);
	t_p_destruir(&peli3);
	printf("Se libero el espacio de las 3 pelicualas\n");

	return 0;
}