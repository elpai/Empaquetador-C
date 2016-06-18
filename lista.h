#ifndef LISTA_H
#define LISTA_H 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista{
	TIPO_DATO elem;
	struct t_list * sig;
	struct t_list * ant;
} lista_nodo_t;

typedef lista_nodo_t * lista_t
#ifndef TIPO_DATO
# define TIPO_DATO char *
#endif

lista_t ls_crear ();

bool ls_es_vacia (const lista_t self);

int ls_tam (const lista_t self);

TIPO_DATO ls_dato (const list_t self);

list_t ls_sig (const list_t self);

list_t ls_ant (const list_t self);

void ls_agregar (list_t *self, const TIPO_DATO elem);

void ls_agre_ade (list_t *self, const TIPO_DATO elem);

void ls_agre_atras (list_t *self, const TIPO_DATO elem);

TIPO_DATO ls_eliminar (list_t *self);

//char *ls_to_string(const /*@in@*/ list_t self);

//void ls_show(const /*@in@*/ list_t self);

void ls_vaciar (list_t *self);

#endif