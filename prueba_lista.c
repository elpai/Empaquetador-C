#include <stdio.h>
#include "lista.h"

int main(){
	lista_t L;
	char * elem = "hola";
	printf("se inicializaron las variables\n");
	L = ls_crear();
	printf("creo la lista\n");
	ls_agre_atras(&L,elem);
	printf("se agrego atras de la lista\n");
	printf("%s\n",ls_dato(L));
	ls_liberar (&L);
	printf("se libero la lista\n");
	return 0;
}
