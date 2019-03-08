#include <stdio.h>
#include "reader.h"
#include "word.h"
#include "dict.h"
int main(int argv, char * argc[]) {
    Reader * r = reader("/Users/MaximZubkov 1/Desktop/Programming/C++/parsing/test.txt");
    //printf("%s", r->get_text(r));
    Unit * u = unit("result");
    u->inc(u);
    //u->print(u);
    Dict * d = dict(r);
    d->print(d);
    printf("\n\n");
    d->print(d);
    destroy_dict(d);
    return 0;
}