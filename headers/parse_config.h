#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 80

typedef struct sample_parameters
{
    char sockname[MAXLEN];
    long nworker;
    long maxfile;
}sample_parameters;
  

void parse_config_file(struct sample_parameters *parms, char *path_to_conf);

void init_parameters(struct sample_parameters *parms);