#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

T_pelicula t_p_crear (char * titulo, char * director, char * protagonista, int presupuesto, int puntaje, int anio){
	T_pelicula * peli;
	peli = (T_pelicula *) malloc (sizeof(T_pelicula));
	(* peli).titulo = titulo;
	(* peli).director = director;
	(* peli).protagonista = protagonista;
	(* peli).presupuesto = presupuesto;
	(* peli).puntaje = puntaje;
	(* peli).anio = anio;
	return (* peli);
}

int t_p_cmp_puntaje (T_pelicula * peli1, T_pelicula * peli2){
	if ((* peli1).puntaje > (* peli2).puntaje) return 1;
	else {
		if ((* peli1).puntaje < (* peli2).puntaje) return -1;
		else return 0;
	}
}

T_pelicula * t_p_sumar_puntaje (T_pelicula * peli, int pntj){
	(*peli).puntaje += pntj;
	return peli;
}

void t_p_a_cadena (T_pelicula * peli, char * cadena){
	cadena = realloc (cadena, strlen ((* peli).titulo) + strlen ((* peli).director) + strlen ((* peli).protagonista) + sizeof (char));
	strcat (cadena, (* peli).titulo);
	strcat (cadena, ": ");
	strcat (cadena, (*peli).director);
	strcat (cadena, ", ");
	strcat (cadena, ( *peli).protagonista);
	strcat (cadena, ".");
}

void t_p_destruir (T_pelicula * peli){
	free (peli);
}
