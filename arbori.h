#include <stdio.h>
#include <stdlib.h>

typedef int Data ;
struct N { // nod arbore
    Data val;
    struct N *left ,* right ;
};
typedef struct N Node ;
struct Elem {
    // datele memorate sunt de tip pointer la nod arbore
    Node * val;
    struct Elem * next ;
};
typedef struct Elem queueNode ;
struct Q{ 
    queueNode *front , * rear ;
};
typedef struct Q Queue ;


void initTree(Node **, Data );

int isEmpty(Node *);
int isInterior(Node *);
int isLeaf(Node *);

void preorder(Node *);
void postorder(Node *);

Node *Create();

int height(Node *);
void printLevel(Node *, Data );
void levelOrderTraversal(Node *);

void deleteNode(Node **, int );
void deleteDeepest(Node *, Node *);
void delete(Node **);
void deleteSequence(Node **, Data );
void deleteDublicate(Node **, Data, int);
void showAncestors(Node *, Data *, Node *);
void findCCA(Node *, Data *, Data *, Node *);
int isSymetric(Node* , Node *);