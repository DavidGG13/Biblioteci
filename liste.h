#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct List{
	Data val;
	struct List *next;
}List;

void addAtBeginning(List **, Data );
void addAtEnd(List** , Data );
void display(List *);
int replace(List *, int, Data);
int addup(List *, int, Data);