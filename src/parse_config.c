#include <parse_config.h>

/*
 * initialize data to default values
 */

void init_parameters(struct sample_parameters *parms)
{
    strncpy(parms->sockname, "cup", MAXLEN);
    parms->nworker = 0;
    parms->maxfile = 0;
}

char *trim(char *s)
{
    /* Initialize start, end pointers */
    char *s1 = s, *s2 = &s[strlen(s) - 1];

    /* Trim and delimit right side */
    while ((isspace(*s2)) && (s2 >= s1))
        s2--;
    *(s2 + 1) = '\0';

    /* Trim left side */
    while ((isspace(*s1)) && (s1 < s2))
        s1++;

    /* Copy finished string */
    strcpy(s, s1);
    return s;
}

int parse_int(char* name){

}

void parse_config_file(struct sample_parameters *parms, char *path_to_conf)
{
    printf("Ok man\n");
    char *s, buff[256];
    FILE *fp = fopen(path_to_conf, "r");
    if (fp == NULL)
    {
        perror("opening config file");
        return;
    }
    printf("FILENAME: %s\n",path_to_conf);
    /* Read next line */
    while ((s = fgets(buff, sizeof buff, fp)) != NULL)
    {
        /* Skip blank lines and comments */
        if (buff[0] == '\n' || buff[0] == '#')
            continue;

        /* Parse name/value pair from line */
        char name[MAXLEN], value[MAXLEN];
        s = strtok(buff, "=");
        if (s == NULL)
            continue;
        else
            strncpy(name, s, MAXLEN);
        trim(name);    
        s = strtok(NULL, "=");
        if (s == NULL)
            continue;
        else
            strncpy(value, s, MAXLEN);
        trim(value);

        /* Copy into correct entry in parameters struct */
        printf("strcmp: %d\n",strcmp(name, "SOCKNAME"));
        if (strcmp(name, "SOCKNAME") == 0)
            strncpy(parms->sockname, value, MAXLEN);
        else if (strcmp(name, "nworker") == 0) //gestire il fatto che sia un int
             strncpy(parms->nworker, value, MAXLEN);
        // else if (strcmp(name, "size") == 0)
        //     strncpy(parms->size, value, MAXLEN);
        else
            printf("WARNING: %s/%s: Unknown name/value pair!\n",
                   name, value);
    }

    /* Close file */
    fclose(fp);
}