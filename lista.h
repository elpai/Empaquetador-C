#ifndef LISTA_H
#define LISTA_H 1

#include <stdlib.h>
#include <stdbool.h>

#ifndef TIPO_DATO
# define TIPO_DATO char *
#endif

typedef struct lista{
	TIPO_DATO elem;
	struct t_list * sig;
	struct t_list * ant;
} lista_nodo_t;

typedef lista_nodo_t * lista_t;



lista_t ls_crear ();

bool ls_es_vacia (const lista_t self);

int ls_tam (const lista_t self);

TIPO_DATO ls_dato (const lista_t self);

lista_t ls_sig (const lista_t self);

lista_t ls_ant (const lista_t self);

void ls_agregar (lista_t *self, TIPO_DATO elem);

void ls_agre_ade (lista_t *self, TIPO_DATO elem);

void ls_agre_atras (lista_t *self, TIPO_DATO elem);

TIPO_DATO ls_eliminar (lista_t *self);

//char *ls_to_string(const /*@in@*/ list_t self);

//void ls_show(const /*@in@*/ list_t self);

void ls_vaciar (lista_t *self);

#endif