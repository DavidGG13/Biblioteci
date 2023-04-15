#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Elem {
  Data val;
  struct Elem *next;
};
typedef struct Elem Node;
struct Q {
  Node *front, *rear;
};
typedef struct Q Queue;

Queue *createQueue();
void enQueue(Queue *, Data);
int isEmpty(Queue *);
Data deQueue(Queue *);
void deleteQueue(Queue *);