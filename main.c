#include <stdio.h>   //inlcucón de librerias
#include <stdlib.h>
#include "lista.h"
#include "parseo.h"
#include "codigo.h"
/*#include "funciones_empack.h"
#include "funciones_despack.h"
#include "funciones_mostar.h"*/

int main (int argc , char * argv[] ){
	int  opt;
	char * arg_rpack;	
	char * arg_list;		    
	char * arg_det;	    
	char * arg_outputdir;		    
	char * arg_output;		    
	char * arg_input;
	char * arg_unpack;
	lista_t L;

  L = ls_crear();
  opt = parsear (argc, argv, &arg_rpack, &arg_unpack, &arg_list,  &arg_det, &arg_outputdir, &arg_output, &arg_input, &L);
  if (opt<=0) {
  	usage (argv, EXIT_FAILURE);
  }
  switch(opt) {
  	case OP_PACK:
  		emp_pack (&L, arg_output, arg_outputdir);
  	break;
  	case OP_RPACK:
  		emp_rpack (arg_rpack, arg_output, arg_outputdir);
  	break;
  	case OP_UNPACK:
  		emp_unpack (arg_unpack, arg_input, arg_outputdir);
  	break;
  	case OP_UNPACKALL:
  		emp_unpackall (arg_input, arg_outputdir);
  	break;
  	case OP_LIST:
  		emp_list(arg_list, arg_input);
  	break;
  	case OP_DETAIL:
  		emp_detail(arg_det, arg_input);
	break;
	case OP_HELP:

	break;
  	default :
  		printf("No se que carajo paso\n");
  	break;

  }
  return EXIT_SUCCESS;
}
