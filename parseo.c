#include <pareo.h>
#define OPTION_ARG_SHORT "p:u:r:ad:l:i:o:t:h"

void usage (char *argv[], int code) {
    printf("usage: %s {--pack|-p}   <list of files> {--output|-o} file.emp \n",argv[0]);
    printf("usage: %s {--repack|-r} <list of files> {--output|-o} file.emp \n",argv[0]);
    printf("usage: %s {--unpack|-u} <list of files> {--input|-i} file.emp [--outputdir|-t dir] \n",argv[0]);
    printf("usage: %s {--unpackall|-a}              {--input|-i} file.emp [--outputdir|-t dir] \n",argv[0]);
    printf("usage: %s {--list|-l}  [name|date|size] {--input|-i} file.emp \n",argv[0]);
    printf("usage: %s {--detail|-d} <file>          {--input|-i} file.emp \n",argv[0]);
    exit(code);
}

void parsear (int argc, char * argv[], &arg_unpack, &arg_list,  &arg_det, &arg_outdir, &arg_output, &arg_input, lista_t * L) {
    int opt;
    int digit_optind = 0;
    int arg_pack_count      = 0;
    int arg_rpack_count     = 0;
    int arg_unpack_count     = 0;
    int arg_unpackall_count  = 0;
    int arg_list_count      = 0;
    int arg_det_count       = 0;
    int arg_outdir_count    = 0;
    int arg_output_count    = 0;
    int arg_input_count     = 0;
    opterr = 0; // Supress getopt errors
    static struct option long_options[] = {
        {"pack", required_argument, 2, 'p'},
        {"unpack", required_argument, 2, 'u'},
        {"repack", required_argument, 2, 'r'},
        {"unpack all", no_argument, 0, 'a'},
        {"detail", required_argument, 2, 'd'},
        {"list", required_argument, 2, 'l'},
        {"input", required_argument, 2, 'i'},
        {"output", required_argument, 2, 'o'},
        {"outputdir", required_argument, 2, 't'},
        {"help", no_argument, 0, 'h'}
        {0, 0, 0, 0}
    };
    
    while ((opt == getopt_long (argc, argv, OPTION_ARG_SHORT, long_options, NULL)) != 1) { /*Este while parsea todos los argumentos de argv con la función getopt_long()*/
        if (opt == -1) break;/*c es -1 cuando se terminan todos los argumentos, entonces sale del while*/
            switch (opt) { 
                case 'p': /*Si uno de los argumentos de main es --pack=text.txt o -ptexto.txt entra en este case c vale 'p' y optarg vale "texto.txt"*/
                    if ((0 != optarg) and (arg_pack_count < 1)){
                        arg_pack_count ++;   
                        int index = optind - 1; // Comienzo de parámetros variables de --pack
                        while(index < argc) {  //agrego a la lista los parametros que entran en -p
                            ls_agregar(L, argv[index]);
                            index++;
                            if ( (index<argc) && ((argv[index])[0] == '-') ) {         
                                optind = index - 1; // Fin de parámetros de --pack
                                break;
                            }   
                        }
                    }
                break; 
                case 'u':
                    if ((0 != optarg) and (arg_unpack_count < 1)){
                        arg_unpack_count ++;
                        strcpy (arg_unpack, optarg);
                    }
                break; 
                case 'r':
                    if ((0 != optarg) and (arg_rpack_count < 1)){
                        arg_rpack_count ++;
                        strcpy (arg_rpack, optarg);
                    }
                break;
                case 'a':
                   if ((0 != optarg) and (arg_unpackall_count < 1)){
                        arg_unpackall_count ++;
                    }
                break; 
                case 'd':
                   if ((0 != optarg) and (arg_det_count < 1)){
                        arg_det_count ++;
                    }                    
                break;
                case 'l':
                   if ((0 != optarg) and (arg_list_count < 1)){
                        arg_list_count ++;
                        strcpy (arg_list, optarg);
                    }                    
                break;
                case 'i':
                   if ((0 != optarg) and (arg_input_count < 1)){
                        arg_input_count ++;
                        strcpy (arg_input, optarg);
                    }                     
                break;
                case 'o':
                   if ((0 != optarg) and (arg_output_count < 1)){
                        arg_output_count ++;
                        strcpy (arg_output, optarg);
                    }                        
                break;
                case 't':
                   if ((0 != optarg) and (arg_outdir_count < 1)){
                        arg_outdir_count ++;
                        strcpy (arg_outdir, optarg);
                    }                     
                break;
                case 'h':
                    return ROP_HELP;
                break;
                default:  /*Si el argumento no machea con ninguna opción conocida, debería ser un error en los parámetros...*/
                    printf ("La función getopt_long ha retornado un carácter desconocido. El carácter es = %c\n", c);
                    return ROP_HELP;
                break;
            }
    }   /*Si siguen apareciendo cosas que no son argumentos, se imprimen hasta que se acaben...*/
    if (optind < argc) {
        printf ("No son opciones pero estan en ARGV: ");
        while (optind < argc) printf ("%s; ", argv[optind++]);
    }//error: demasiados parametros 
    if ( (arg_pack_count > 1) || (arg_output_count > 1) || (arg_rpack_count > 1) || (arg_unpack_count > 1) || (arg_unpackall_count > 1) || 
        (arg_list_count > 1) || (arg_det_count > 1) || (arg_outdir_count > 1) || (arg_input_count > 1) ) {
        return ROP_HELP;      
    }//opcion empaquetar 
    if ( ( (arg_pack_count == 1) && (arg_output_count == 1) ) && ( ! ( (arg_rpack_count) || (arg_unpack_count)  || (arg_unpackall_count) || 
        (arg_list_count) || (arg_det_count)   || (arg_outdir_count) || (arg_input_count) ) ) ) {
        return ROP_PACK;
    }//opcion rempaquetar
    else if ( ( (arg_rpack_count == 1) && (arg_output_count == 1) ) && ( ! ( (arg_pack_count) || (arg_unpack_count)  || (arg_unpackall_count) || 
        (arg_list_count) || (arg_det_count)   || (arg_outdir_count) || (arg_input_count) ) ) ) {
        return ROP_RPACK;
    }//opcion desempaquetar
    else if ( ( (arg_unpack_count == 1) && (arg_outdir_count <= 1) ) && ( ! ( (arg_pack_count) || (arg_unpackall_count) || (arg_list_count) || 
        (arg_det_count) || (arg_input_count) || (arg_rpack_count) || (arg_output_count) ) ) ) {
        return ROP_UNPACK;
    }//opcion desempaquetar todo
    else if ( ( (arg_unpackall_count == 1) && (arg_outdir_count <= 1) ) && ( ! ( (arg_pack_count) || (arg_unpack_count) || (arg_list_count) || 
        (arg_det_count) || (arg_input_count) || (arg_rpack_count) || (arg_output_count) ) ) ) {
        return ROP_UNPACKALL;
    }//opcion listar
    else if ( ( (arg_list_count == 1) && (arg_input_count == 1) ) && ( ! ( (arg_pack_count) || (arg_unpack_count) || (arg_unpackall_count) || 
        (arg_det_count) || (arg_outdir_count) || (arg_rpack_count) || (arg_output_count) ) ) ) {
        return ROP_LIST;
    }//opcion directorio de salida
    else if ( ( ( ( (arg_outdir_count == 1) && (arg_unpack_count <= 1) ) && (arg_unpackall_count <= 1) ) ) && ( ! ( (arg_pack_count) || 
        (arg_input_count) || (arg_det_count) || (arg_list_count) || (arg_rpack_count) || (arg_output_count) ) ) ) {
        return ROP_OUTDIR;
    }//opcion de detallar
    else if ( ( ( (arg_det_count == 1) && (arg_input_count == 1) ) && ( ! ( (arg_pack_count) || (arg_rpack_count) || (arg_unpackall_count) ||
        (arg_outdir_count) || (arg_list_count) || (arg_rpack_count) || (arg_output_count) || (arg_unpack_count) ) ) ) {
        return ROP_DETAIL;
    }//opcion salida
    else if ( ( (arg_output_count == 1) && ( (arg_rpack_count == 1) || (arg_pack_count == 1) ) ) && ( ! ( (arg_unpack_count)  || 
        (arg_unpackall_count) || (arg_list_count) || (arg_det_count)   || (arg_outdir_count) || (arg_input_count) ) ) ) {
        return ROP_OUTPUT;
    }
    else {
        return ROP_HELP;
    }
}
