#include <stdio.h>
#include "reader.h"
#include "word.h"
#include "dict.h"
#include "tree.h"


int main(int argv, char * argc[]) {
    Reader * r = reader("/Users/MaximZubkov/Desktop/Programming/C++/Word_frequency/test.txt");
    //printf("%s", r->get_text(r));
    Unit * u = unit("result");
    u->inc(u);
    //u->print(u);
    Dict * d = dict(r);
    d->print(d);
    printf("\n\n");
    d->print(d);
    //destroy_dict(d);
    Tree * t = tree_from_dict(d);
    t->tree_print(t);
    return 0;
}