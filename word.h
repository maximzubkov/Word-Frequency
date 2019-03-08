#ifndef PARSING_WORD_H
#define PARSING_WORD_H

typedef struct Unit{
	char * w;
	int num;
	void (* inc)(struct Unit * u);
	char * (* get)(struct Unit * u);
	void (* print)(struct Unit * u);
} Unit;

Unit * unit(char * word);

char * unit_get(Unit * u);

void destroy_unit(Unit * u);

void inc(Unit * u);

void unit_print(Unit * u);

#endif
