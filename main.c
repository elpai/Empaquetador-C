#include <stdio.h>   //inlcucón de librerias
#include <stdlib.>
#include <parceo.h>  //inlcucón de arvhivos
#include "lista.h"
#include "parseo.h"
/*#include "funciones_empack.h"
#include "funciones_despack.h"
#include "funciones_mostar.h"*/

int main (int argc , char * argv[] ){
	int  opt;
  char * arg_list;		    
  char * arg_det;	    
  char * arg_outdir;		    
  char * arg_output;		    
  char * arg_input;
  char * arg_umpack;
  lista_t * L;

  L = ls_crear();
  opt = parse_args(argc, argv, &arg_umpack, &arg_list,  &arg_det, &arg_outdir, &arg_output, &arg_input, L);
  if (opt<=0) {
  	usage (argv, EXIT_FAILURE);
  }
  switch(opt) {
  	case ROP_PACK:
  		emp_pack(L, arg_output);
  	break;
  	case ROP_RPACK:
  		emp_rpack(arg_pack, arg_output);
  	break;
  	case ROP_UNPACK:
  		emp_upack(arg_pack, arg_input, arg_outdir);
  	break;
  	case ROP_UNPACKALL:
  		emp_uapack(arg_input, arg_outdir);
  	break;
  	case ROP_LIST:
  		emp_list(arg_list, arg_input);
  	break;
  	case ROP_DETAIL:
  		emp_detail(arg_det, arg_input);
  	break;
  	case ROP_IMPUT:
      
  	break;
  	case ROP_OUTPUT:
      
    break;
    case ROP_OUTPUTDIR:

    break;
    case ROP_HELP:

    break;
  	default :
  		printf("No se que carajo paso\n");
  	break;

  }
  return EXIT_SUCCESS;
}
/*  
Una forma de obtener el tamaño de un archivo que se me ocurre, es utilizar las funciones "fseek()" y "ftell()"

ejemplo:

int tamanio; // declaro la variable que recibira el tamanio.
FILE* arch; // declaro un puntero de tipo FILE.

arch=fopen("miArchivo.dat", "rb"); // abro el archivo de solo lectura.
fseek(arch, SEEK_END);            // me ubico en el final del archivo.
tamanio=ftell(arch);                     // obtengo su tamanio en BYTES.
fclose(arch);                               // cierro el archivo.
---------------------------------------------------------------------------------------------------------------------
http://www.gnu.org/savannah-checkouts/gnu/libc/manual/html_node/File-Attributes.html
*/