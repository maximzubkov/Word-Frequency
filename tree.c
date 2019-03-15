

#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "word.h"
#include "dict.h"
#include "tree.h"

int tabs = 1;

Tree * tree_from_dict(Dict * d)
{
    Tree * t = (Tree *) malloc(sizeof(Tree));

    t->word = NULL;
    t->left = NULL;
    t->right = NULL;
    t->cmp = compare;
    t->tree_add = tree_add;
    t->tree_add_word = tree_add_word;
    t->tree_find = tree_find;
    t->tree_print = tree_print;
    t->tree_destroy = tree_destroy;
    t->tree_add_unit = tree_add_unit;
    int i;
    for(i = 0; i < d->size; i++){
    	//printf("\n");
    	d->words[i]->print(d->words[i]);
    	//printf("\n");
    	t->tree_add_unit(t, d->words[i]);
    	//t->tree_print(t);
    	//printf("\n");
    }
    return t;
}

void tree_add_unit(Tree * t, Unit * u){
	if (t->word == NULL){
    	t->word = u;
    }

    int tmp = t->cmp((void *)t->word, (void *)u);
    if (tmp == 0){
    	t->word->inc(t->word);
    }

    if (tmp > 0){
        if (t->left != NULL){
        	//t->left->tree_print(t);
            t->tree_add_unit(t->left, u);
        }
        else{
        	//printf("21\n");
            t->left = tree(u->w);
        }
    }
    
	if (tmp < 0){
        if (t->right != NULL){
        	//printf("24\n");
            t->tree_add_unit(t->right, u);
        }
        else{
        	//printf("22\n");
            t->right = tree(u->w);
        }
    }
}

int compare(void * a, void * b){
    Unit * w1 = (Unit *) a;
    Unit * w2 = (Unit *) b;
    
    return strcmp(w1->w, w2->w);
}

Tree * tree(char * w)
{
    Tree * t = (Tree *) malloc(sizeof(Tree));

    t->word = unit(w);
    t->left = NULL;
    t->right = NULL;
    t->cmp = compare;
    t->tree_add = tree_add;
    t->tree_add_word = tree_add_word;
    t->tree_find = tree_find;
    t->tree_print = tree_print;
    t->tree_destroy = tree_destroy;
    t->tree_add_unit = tree_add_unit;
    return t;
}

Tree * tree_find(Tree * t, char * w)
{
    int res = t->cmp(t->word->w, w);
  
    if (res == 0)
        return t;
    
    if (res > 0 && t->left != NULL)
    {
        return t->tree_find(t->left, w);
    }
    
    if (res < 0 && t->right != NULL)
    {
        return t->tree_find(t->right, w);
    }
        
    return NULL;
}


int tree_size(Tree * t)
{
    if (t == NULL)
        return 0;

    int size = 1;
    
    if (t->left)
        size += tree_size(t->left);

    if (t->right)
        size += tree_size(t->right);

    return size;
}

Tree * tree_add_word(Tree * t, char * str){
	if (t->word == NULL){
    	t->word = unit(str);
    	return t;
    }
    
    int tmp = t->cmp(t->word->w, str);

    if (tmp == 0){
    	t->word->inc(t->word);
    }

    if (tmp > 0){
        if (t->left != NULL)
            t->tree_add_word(t->left, str);
        else
            t->left = tree(str);
    }
    
	if (tmp < 0){
        if (t->right != NULL)
            t->tree_add_word(t->right, str);
        else
            t->right = tree(str);
    }
    return t;
}

/*
void tree_add(Tree * t, char * text)
{
	char * str;
    str = strtok(text, " ,.!\n\t:");
    t->tree_add_word(t, str);
    while (1){
        str = strtok (NULL, " ,.!\n\t:");
        if (str != NULL){
        	t = t->tree_add_word(t, str);
        } else {
            break;
        }
    }
}
*/


void tree_print(Tree * t){
    if (t == NULL){
        return;
    }
    int i;
    tabs++;
    t->tree_print(t->right);
    for (i = 0; i < tabs; i++){
        printf("  ");
    }
    
    t->word->print(t->word);
    
    t->tree_print(t->left);
    tabs--;

    return;
}


void tree_destroy(Tree * t){
    if (t->left != NULL)
        t->tree_destroy(t->left);
    
    if (t->right != NULL)
        t->tree_destroy(t->right);

    t->word->destroy_unit(t->word);
    free(t);
}


