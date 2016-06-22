#ifndef _PARSEO_H
#define _PARSEO_H 1
#include <stdio.h> 
#include <stdlib.h>
#include <getopt.h>

void usage(char *argv[], int code);

void pasear(argc,argv[], &arg_pack, &arg_list,  &arg_det, &arg_outdir, &arg_output, &arg_input);

#endif