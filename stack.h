#include <stdio.h>
#include <stdlib.h>

typedef int Data ;
struct Elem {
    Data val;
        struct Elem * next ;
};
    typedef struct Elem Stack ;
struct Q{
    Stack *front ,* rear ;
};
typedef struct Q Queue ;

void push ( Stack ** , Data );
Data pop( Stack ** );
Data top( Stack * );
int isEmpty ( Stack *);
void deleteStack ( Stack **);