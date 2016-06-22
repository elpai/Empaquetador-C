#include <stdio.h>
#include "lista.h"

int main(){
	lista_t L;
	char * elem = "hola";
	L = ls_crear();
	ls_agre_atras(&L,elem);
	printf("%s",ls_dato(L));
	return 0;
}