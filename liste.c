#include "liste.h"
void addAtBeginning(List **head, Data v)
{
	List* newList = (List*)malloc(sizeof(List));
	newList->val = v;
	newList->next = *head;
	*head = newList;
}

void addAtEnd(List** head, Data v)
{
	List *aux=*head;
	List* newList = (List*)malloc(sizeof(List)); 
	newList->val = v; 
	if (*head == NULL) addAtBeginning(&*head, v);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newList;  
		newList->next = NULL; 
	}
}

void display(List *head)
{
	while (head!=NULL){
		printf ("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}

int replace(List * head, int poz,Data val){
	int i;
	for(i=0;i<poz;i++, head=head->next){
		if (head== NULL){
			printf("The pozition isn't in the dimension of the list.");
			return -1;
		}
	}
	head->val=val;
	return 0;
}
int addup(List * head, int poz,Data val){
	int i;
	for(i=0;i<poz;i++, head=head->next){
		if (head== NULL){
			printf("The pozition isn't in the dimension of the list.");
			return -1;
		}
	}
	head->val=head->val+val;
	return 0;
}