#ifndef PARSING_DICT_H
#define PARSING_DICT_H

#include "word.h"
#include "reader.h"

typedef struct Dict{
	Unit ** words;
	int size;
	int capacity;
	void (* print)(struct Dict * d);
	void (* add)(struct Dict * d, char * word);
} Dict;

Dict * dict(Reader * r);

void destroy_dict(Dict * d);

void dict_print(Dict * d);

void add(Dict * d, char * word);

#endif