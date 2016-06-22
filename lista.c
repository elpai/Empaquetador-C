#include "lista.h"

lista_t ls_crear (){
	return (lista_t) NULL;
}

bool ls_es_vacia (const lista_t self){
	return (self == (lista_t) NULL);
}

int ls_tam (const lista_t self){
	if (ls_es_vacia (self)) return 0;
  else return 1 + ls_tam (ls_sig (self));
}

TIPO_DATO ls_dato (const lista_t self){
	return self -> elem;
}

lista_t ls_sig (const lista_t self){
	return (lista_t) self -> sig;
}

lista_t ls_ant (const lista_t self){
	return (lista_t) self -> ant;
}

void ls_agregar (lista_t *self, TIPO_DATO elem){
	ls_agre_ade (self, elem);
}

void ls_agre_ade (lista_t *self, TIPO_DATO elem){
	lista_nodo_t * nodo;

  nodo = malloc (sizeof (lista_nodo_t));
  nodo -> elem = elem;
  nodo -> sig = (lista_nodo_t *) (* self);
  nodo -> ant = (lista_nodo_t *) NULL;
  ( *self) = (lista_t) nodo;
}

void ls_agre_atras (lista_t *self, TIPO_DATO elem){
	lista_nodo_t * nodo;

  if (ls_es_vacia (* self)) {
  	nodo = malloc (sizeof (lista_nodo_t));
    nodo -> elem = elem;
    nodo -> sig = (lista_nodo_t *) NULL;
    nodo -> ant = (lista_nodo_t *) (* self);
    (* self) = (lista_t) nodo;
  } else ls_agre_atras (&((*self) -> sig), elem);
}

TIPO_DATO ls_elim_prim (lista_t *self){
  lista_t aux;
  TIPO_DATO elem;

  elem = (* self) -> elem;
  aux = (* self);
  (* self) = (lista_t) (* self) -> sig;
  (* self) -> ant = (lista_t) (aux) -> ant;
  free (aux);
  return elem;
}

//char *ls_to_string(const /*@in@*/ list_t self);

//void ls_show(const /*@in@*/ list_t self);

void ls_liberar (lista_t *self){
	int i;
  int len = ls_tam (*self);
  lista_t aux = NULL;

  if (len !=0 ){
    for(i=0; i<len; i++){
	  	aux = (*self) -> sig;
	  	free (*self);
	  	(*self) = aux;
		}
  }
}