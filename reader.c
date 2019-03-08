#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "reader.h"

char * get_text(Reader * input){
    return input->text;
}

Reader * reader(char * file_name){
    Reader * r = (Reader *)malloc(sizeof(Reader));
    r->get_text = get_text;
    r->file = fopen(file_name, "r");
    if (r->file == NULL){
        printf("bad file");
    }
    int count = 5;
    int capacity = count;
    r->text = (char *)malloc(count * sizeof(char));
    char tmp[count];
    if (r->file != NULL) {
        while (fgets(tmp, count, r->file) != NULL) {
            capacity += 5;
            r->text = (char *)realloc(r->text, capacity * sizeof(char));
            r->text = strcat(r->text, tmp);
        }
        fclose(r->file);
    }
    return r;
}

