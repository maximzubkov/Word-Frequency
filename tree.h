#ifndef PARSING_TREE_H
#define PARSING_TREE_H

#include "word.h"
#include "dict.h"
#include "reader.h"

typedef struct Tree{
    Unit * word;
    struct Tree * left;
    struct Tree * right;
	int (* cmp)(void * a, void * b);

	struct Tree * (* tree)(char * w, int (* cmp)(void * a, void * b));
	struct Tree * (* tree_find)(struct Tree * t, char * w);
	int (* tree_size)(struct Tree * t);
	void (* tree_add)(struct Tree * t, char * w);
	struct Tree * (* tree_add_word)(struct Tree * t, char * text);
	void (* tree_print)(struct Tree * t);
	void (* tree_destroy)(struct Tree * t);
	void (* tree_add_unit)(struct Tree * t, struct Unit * u);
} Tree;

void tree_add_unit(Tree * t, Unit * u);

int compare(void * a, void * b);

Tree * tree(char * w);

Tree * tree_from_dict(Dict * d);

Tree * tree_find(Tree * t, char * w);

int tree_size(Tree * t);

void tree_add(Tree * t, char * text);

Tree * tree_add_word(Tree * t, char * word);

void tree_print(Tree * t);

void tree_destroy(Tree * t);

Dict * tree_dict();

#endif