#include "type.h"

NODE *mylist, *node;    // pointers, no NODE area yet 

int printlist(NODE *p) { // same as in c2_1}

int main()
{
    int i;
    NODE *p;
    node = (NODE *)malloc(N*sizeof(NODE));
    for (i=0; i < N; i++){
       p = &node[i];         // access each NODE area in HEAP
       sprintf(p->name, "%s%d", "node",i);
       p->next = p+1;        // node[i].next = &node[i+1];
    }
    node[N-1].next = 0;
    mylist = &node[0];
    printlist(mylist);
}

