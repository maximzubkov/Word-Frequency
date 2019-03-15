#include <stdio.h>
#include <stdlib.h>
#include "word.h"

Unit * unit(char * word){
    Unit * u = (Unit *)malloc(sizeof(Unit));
    u->w = (char *)malloc(sizeof(word));
    u->w = word;
    u->num = 1;
    u->inc = inc;
    u->print = unit_print;
    u->get = unit_get;
    u->destroy_unit = destroy_unit;
    return u;
}

void inc(Unit * u){
    u->num++;
}

char * unit_get(Unit * u){
    return u->w;
}

void destroy_unit(Unit * u){
    printf("goodbay unit %s!\n", u->w);
    free(u->w);
    free(u);
}

void unit_print(Unit * u){
    printf("%s %d \n", u->w, u->num);
}
