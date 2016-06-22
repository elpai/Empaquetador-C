#include <pareo.h>

void usage(char *argv[], int code){
    printf("usage: %s {--pack|-p}   <list of files> {--output|-o} file.emp \n",argv[0]);
    printf("usage: %s {--repack|-r} <list of files> {--output|-o} file.emp \n",argv[0]);
    printf("usage: %s {--unpack|-u} <list of files> {--input|-i} file.emp [--outputdir|-t dir] \n",argv[0]);
    printf("usage: %s {--unpackall|-a}              {--input|-i} file.emp [--outputdir|-t dir] \n",argv[0]);
    printf("usage: %s {--list|-l}  [name|date|size] {--input|-i} file.emp \n",argv[0]);
    printf("usage: %s {--detail|-d} <file>          {--input|-i} file.emp \n",argv[0]);
    exit(code);
}
/*  solo en caso de concatenar los string del parametro 
static size_t strlen_null(const char *s) {
    if (s == NULL)
        return 0;
    else
        return strnlen(s, MAX_PATH_LEN);
}

static char *strcat_stuff(char *dest, const char *src, const char *stuff) {
    //completar en casao de usar la concatenacion de string para los parametros
}
*/
void parsear(int argc, char * argv[], &arg_pack, &arg_list,  &arg_det, &arg_outdir, &arg_output, &arg_input){
    int c;
    int digit_optind = 0;
    int arg_pack_count      = 0;
    int arg_rpack_count     = 0;
    int arg_upack_count     = 0;
    int arg_upackall_count  = 0;
    int arg_list_count      = 0;
    int arg_det_count       = 0;
    int arg_outdir_count    = 0;
    int arg_output_count    = 0;
    int arg_input_count     = 0;
    opterr           = 0; // Supress getopt errors
    *arg_pack   =   (NULL);
    *arg_list   =   "name";                               
    *arg_det    =   (NULL);                                       
    *arg_outdir =   (NULL);      
    *arg_output =   (NULL);                 
    *arg_input  =   (NULL);
    
    while (1) { /*Este while parsea todos los argumentos de argv con la función getopt_long()*/
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
         /*Esta estructura sirve para convertir los argumentos largos en cortos
         así, si el argumento es --compress en c se guardará 'c', como c tiene
         un argumento opcional, si éste existe se guarda en optarg.
         no_argument, optional_argument y required_argument son macros que se
         expanden a 0, 1 y 2 respectivamente*/
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
        };  /*La cadena "dhvf:c::" indica que d, h y v no tienen argumentos, f tiene un
            argumento requerido (por eso los dos puntos 'f:') y c tiene un argumento opcional
            (de ahi los dobles dos puntos 'c::')*/
        c = getopt_long (argc, argv, "p:u:r:ad:l:i:o:t:h", long_options, &option_index);
        if (c == -1)break;/*c es -1 cuando se terminan todos los argumentos, entonces sale del while*/
            switch (c) { 
                case 'p': /*Si uno de los argumentos de main es --pack=text.txt o -ptexto.txt entra en este case c vale 'p' y optarg vale "texto.txt"*/
                    int index = optind - 1; // Comienzo de parámetros variables de --pack
                    arg_pack_count++;   
                    while(index < argc) {  // Procesa los parametros para --pack/-p y los concatena en un string separado por "$" Una mejor opcion seria colocarlos en una lista o un arreglo
                        *arg_pack = realloc( *arg_pack, strlen_null(*arg_pack) + 2 + strlen_null(argv[index]) );
                        strcat_stuff(*arg_pack, argv[index], "$");   
                        index++;
                        if ( (index<argc) && ((argv[index])[0] == '-') ) {         
                            optind = index - 1; // Fin de parámetros de --pack
                            break;
                        }
                    }
                break; 
                case 'u':
                    
                break; 
                case 'r':
                    
                break;
                case 'a':
                    
                break; 
                case 'd':
                    
                break;
                case 'l':
                    
                break;
                case 'i':
                    
                break;
                case 'o':
                    
                break;
                case 't':
                    
                break;
                case 'h':
                    return ROP_HELP;
                break;
                default:  /*Si el argumento no machea con ninguna opción conocida, debería ser un error en los parámetros...*/
                    printf ("La función getopt_long ha retornado un carácter desconocido. El carácter es = %c\n", c);
            }
    }   /*Si siguen apareciendo cosas que no son argumentos, se imprimen hasta que se acaben...*/
    if (optind < argc) {
        printf ("No son opciones pero estan en ARGV: ");
        while (optind < argc) printf ("%s;", argv[optind++]);
    }
    if ( (arg_pack_count>1) || //... Completar 
        return ROP_BAD;      
    }// Pack Option
    if ( ( (arg_pack_count==1) && (arg_output_count==1) ) && ( ! ( (arg_rpack_count) || (arg_upack_count)  || (arg_upackall_count) || 
        (arg_list_count) || (arg_det_count)   || (arg_outdir_count) || (arg_input_count) ) ) ) {
        return ROP_PACK;
    }
    else if ( (arg_rpack_count==1)&&(arg_output_count==1)&& // Re-Pack Option //... Completar
    //...
    // Unpack Option
    else if 
    //... Completar 
    // Unpack-all Option
    //... Completar
    // List Option
    //... Completar
    // Detail Option
    //... Completar
    else  {
        return ROP_UNKNOWN;
    }
}