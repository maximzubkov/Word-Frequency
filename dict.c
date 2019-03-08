#include "dict.h"
#include "word.h"
#include "reader.h"
#include <stdlib.h>
#include <string.h>

Dict * dict(Reader * r){
    Dict * d = (Dict *)malloc(sizeof(Dict));
    d->print = dict_print;
    d->add = add;
    d->capacity = 10;
    d->size = 0;
    d->words = (Unit **)malloc(d->capacity * sizeof(Unit));
    d->add(d, r->text);
    return d;
}

void add(Dict * d, char * text){
    char * str;
    int j = 0, flag = 0;
    str = strtok(text, " ");
    d->words[d->size] = unit(str);
    d->size++;
    while (1)
    {
        str = strtok (NULL, " ,.!\n\t:");
        if (str != NULL){
            flag = 0;
            for (j = 0; j < d->size ; j++){
                if (strcmp(d->words[j]->get(d->words[j]), str) == 0){
                    d->words[j]->inc(d->words[j]);
                    flag = 1;
                }
            }
            if (flag == 0){
                d->words[d->size] = unit(str);
                d->size++;
                if (d->size >= d->capacity){
                    d->capacity += 10;
                    d->words = (Unit **)realloc(d->words, d->capacity * sizeof(Unit));
                }
            }
        } else {
            break;
        }
    }
}

void destroy_dict (Dict * d){
    free(d->words);
    free(d);
    printf("goodbay dict!");
}
void dict_print(Dict * d){
    int i;
    for (i = 0; i < d->size; i++){
        d->words[i]->print(d->words[i]);
    }
}