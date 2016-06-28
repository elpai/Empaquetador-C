#ifndef PELICULA_H
#define PELICULA_H 1

typedef struct movie{
	char * titulo;
	char * director;
	char * protagonista;
	int presupuesto;
	int puntaje;
	int anio;
}T_pelicula;

T_pelicula t_p_crear (char * titulo, char * director, char * protagonista, int presupuesto, int puntaje, int anio);

int t_p_cmp_puntaje (T_pelicula * peli1, T_pelicula * peli2);

T_pelicula * t_p_sumar_puntaje (T_pelicula * peli, int pntj);

void t_p_a_cadena (T_pelicula * peli, char * cadena);

void t_p_destruir (T_pelicula * peli);

#endif