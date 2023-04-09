

#include "arbori.h"

void initTree(Node **root, Data d) {
  *root = (Node *)malloc(sizeof(Node));
  (*root)->left = (*root)->right = NULL;
  (*root)->val = d;
}

int isEmpty(Node *root)

{ return (root == NULL); }

int isInterior(Node *n)

{ return (n->left != NULL || n->right != NULL); }

int isLeaf(Node *n) {
  // return !isInterior(n);
  return (n->left == NULL && n->right == NULL);
}

void preorder(Node *root) {
  if (root) {
    printf("%d", root->val);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(Node *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->val);
  }
}

Node *Create() {
  Data val;
  char c;
  Node *root = (Node *)malloc(sizeof(Node));
  printf(" Dati valoarea pentru nod: ");
  scanf("%d", &val);
  root->val = val;
  printf(" Nodul adaugat are subarbore stang ? d/n ");
  scanf("%s", &c);
  if (c == 'd')
    root->left = Create();
  else
    root->left = NULL;
  printf(" Nodul adaugat are subarbore drept ? d/n ");
  scanf("%s", &c);
  if (c == 'd')
    root->right = Create();
  else
    root->right = NULL;
  return root;
}

int height(Node *root) {
  int hs, hd;
  if (root == NULL) return -1;
  // inaltimea subarborelui stang
  hs = height(root->left);
  // inaltimea subarborelui drept
  hd = height(root->right);
  // returneaza inaltimea nodului
  return 1 + ((hs > hd) ? hs : hd);
}
void printLevel(Node *root, int level) {
  if (root == NULL) return;
  if (level == 1)
    printf("%d", root->val);
  else if (level > 1) {
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
  }
}

void levelOrderTraversal(Node *root) {
  int h = height(root);
  int i;
  // consider nivelul 1 cel al radacinii
  for (i = 1; i ¡= h; i++) {
    printLevel(root, i);
    printf("\n");
  }
}

void deleteNode(Node **root, int key) {
  Queue *Q = createQueue();
  enQueue(Q, *root);
  Node *temp, *key˙node = NULL;
  while (!isEmpty(Q)) {
    temp = deQueue(Q);
    if (temp->val == key) key_node = temp;
    if (temp->left != NULL) enQueue(Q, temp->left);
    if (temp->right != NULL) enQueue(Q, temp->right);
  }  // la final in temp , cea mai din dreapta frunza
  if ((*root)->val == key && (*root)->left == NULL && (*root)->right == NULL) {
    free(*root);
    *root = NULL;
  } else {  // parintele trebuie sa indice la NULL
    int aux = temp->val;
    deleteDeepest(*root, temp);
    // valoarea nodului de sters devine
    // cea a celui mai adanc nod din dreapta
    key_node->val = aux;
  }
}

void deleteDeepest(Node *root, Node *d_node) {
  Queue *Q = createQueue();
  enQueue(Q, root);
  // parcurge pana la ultimul element , stocheaza in temp
  Node *temp;
  while (!isEmpty(Q)) {
    temp = deQueue(Q);
    if (temp->right != NULL) {
      if (temp->right == d_node) {
        temp->right = NULL;
        free(d_node);
        return;
      } else
        enQueue(Q, temp->right);
    }
    if (temp->left != NULL) {
      if (temp->left == d_node) {
        temp->left = NULL;
        free(d_node);
        return;
      } else
        enQueue(Q, temp->left);
    }
  }
}

void delete(Node **root) {
  if (*root) {
    delete((*root)->left);
    delete((*root)->right);
    free(*root);
  }
}

void deleteSequence(Node **root, Data v){
  if (*root) {
    if((*root)->val==v){
      delete(root);
    }
    deleteSequence((*root)->left);
    deleteSequence((*root)->right);
  }
}

void deleteDublicate(Node **root, Data v, int bol){
  if(*root){
    if((*root)->val==v && bol==0){
      bol=1;
    }else{
      deleteSequence(root, v);
    }
    deleteDublicate((*root)->left, v, bol);
    deleteDublicate((*root)->right, v, bol);
  }
}

void showAncestors(Node *root, Data *v, Node *prev){
  if(root){
    showAncestors(root->left, v, root);
    showAncestors(root->right, v, root);
    if(root->val==*v){
      printf("%d  ", root->val);
      *v=prev->val;
    }
  }
}

void findCCA(Node *root, Data *a, Data *b, Node *prev){
  //closest common Ancestor
  if(root){
    findCCA(root->left, a, b, root);
    findCCA(root->right, a, b, root);
    if(*a==*b){
      printf("%d", *a);
    }
    if(root->val==*a){
      *a=prev->val;
    }
    if(root->val==*b){
      *b=prev->val;
    }
  }
}

int isSymetric(Node* left, Node *right){
  if(left->left && right->right){
    return isSymetric(left->left, right->right);
  }else if(left->left || right->right){
    return 0;
  }
  if(left->right && right->left){
    return isSymetric(left->right, right->left);
  }else if(left->right || right->left){
    return 0;
  }
  if(left == NULL && right == NULL){
    return 1;
  }
}