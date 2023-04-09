#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <limits.h>

void push ( Stack ** top , Data v) {
Stack * newStack =( Stack *) malloc ( sizeof ( Stack ));
newStack->val=v;
newStack->next =*top;
*top= newStack ;
}

Data pop( Stack ** top) {
    if ( isEmpty (* top )) return INT_MIN ;
    Stack * temp =(* top );
    Data aux=temp->val;
    *top =(* top)->next ;
    free ( temp );
    return aux ;
}

Data top( Stack * top ){
    if ( isEmpty ( top )) return INT_MIN ;
    return top->val;
}

int isEmpty ( Stack *top ){
return top == NULL ;
}

void deleteStack ( Stack ** top ){
    Stack * temp ;
    while ((* top )!= NULL ){
        temp =* top;
        *top =(* top)->next ;
        free ( temp );
    }
}