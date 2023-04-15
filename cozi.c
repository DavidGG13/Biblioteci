#include "cozi.h"

Queue *createQueue() {
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  if (q == NULL)
    return NULL;
  q->front = q->rear = NULL;
  return q;
}

void enQueue(Queue *q, Data v) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = v;
  newNode->next = NULL;
  // nodurile noi se adauga la finalul cozii
  if (q->rear == NULL)
    q->rear = newNode;
  // daca nu exista niciun nod in coada
  else {
    (q->rear)->next = newNode;
    (q->rear) = newNode;
  }
  // daca exita un singur element in coada
  if (q->front == NULL)
    q->front = q->rear;
}

int isEmpty(Queue *q) { return (q->front == NULL); }

Data deQueue(Queue *q) {
  Node *aux;
  Data d;
  if (isEmpty(q))
    return INT_MIN;
  aux = q->front;
  d = aux->val;
  q->front = (q->front)->next;
  free(aux);
  return d;
}

void deleteQueue(Queue *q) {
  Node *aux;
  while (!isEmpty(q)) {
    aux = q->front;
    q->front = q->front->next;
    // printf (”% d ” , aux -> val );
    free(aux);
  }
  free(q);
}