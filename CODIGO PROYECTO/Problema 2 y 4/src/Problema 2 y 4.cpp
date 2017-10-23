//============================================================================
// Name        : Problema.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// Nodo para primera lista
void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}


void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(struct Node **head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "No hay nodo " << n << " en la list.\n";
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}

	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

/* Invertir */
struct Node* reverse(struct Node** head)
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;


	parent->next = NULL;
	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

/* crear la copia */
void copyLinkedList(struct Node *node, struct Node **pNew)
{
	if(node != NULL) {
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copyLinkedList(node->next, &((*pNew)->next));
	}
}

/* Comparar  */
/* retorna : igual(1), diferente(0) */
int compareLinkedList(struct Node *node1, struct Node *node2)
{
	static int flag;

	/* las dos listas son NULL */
	if(node1 == NULL && node2 == NULL) {
		flag = 1;
	}
	else {
		if(node1 == NULL || node2 == NULL)
			flag = 0;
		else if(node1->data != node2->data)
			flag = 0;
		else
			compareLinkedList(node1->next, node2->next);
	}

	return flag;
}

void deleteLinkedList(struct Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main()
{
	struct Node *newHead;
	struct Node *head = new Node;

	initNode(head,10);
	display(head);

	addNode(head,20);
	display(head);

	addNode(head,30);
	display(head);

	addNode(head,35);
	display(head);

	addNode(head,40);
	display(head);

	insertFront (&head, 5);
	display(head);

	int numDel = 5;
	Node *ptrDelete = searchNode(head, numDel);
	if(deleteNode (&head, ptrDelete))
		cout<<"Nodo"<<numDel << "eliminado\n";
	display (head);



	cout << "La list Inversa\n";
	reverse(&head);
	display(head);

	cout << "La list fue duplicada\n";
	copyLinkedList (head, &newHead);
	display(newHead);

	cout << "Comparando las listass...\n";
	cout << "Las listas son la misma?\n";
	if(compareLinkedList(head,newHead))
		cout << "Sí, son la misma!\n";
	else
		cout << "No, son distintas!\n";
	cout << endl;


	numDel = 35;
	ptrDelete = searchNode(newHead,numDel);

	if (deleteNode (&newHead, ptrDelete)){
		cout << "Node "<< numDel << " Eliminado!\n";
		cout << "La lista tras haber eliminado\n";
		display(newHead);
	}


	cout << "Comparando de nuevo las listas...\n";
	cout << "Son iguales las listas?\n";
	if (compareLinkedList(head, newHead))
		cout << "Sí, son la misma!\n";
	else
		cout << "No, son distintas!\n";

	cout << endl;
	cout << "Eliminando la lista duplicada\n";
	deleteLinkedList (&newHead);
	display(newHead);
	return 0;
}
