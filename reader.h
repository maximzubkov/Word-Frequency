#ifndef PARSING_READER_H
#define PARSING_READER_H
#include <stdio.h>
typedef struct Reader{
    FILE * file;
    char * text;
    char * (* get_text)(struct Reader * input);
} Reader;

Reader * reader(char * file_name);

char * get_text(Reader * input);

#endif
