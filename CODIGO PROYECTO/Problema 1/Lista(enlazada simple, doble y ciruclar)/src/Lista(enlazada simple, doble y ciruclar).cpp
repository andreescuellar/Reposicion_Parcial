//============================================================================
// Name        : Lista(enlazada.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;


/*                CODIGO LISTA ENLAZADA SIMPLE
 *
 *
 *
 *
 * 				CODIGO LISTA ENLAZADA SIMPLE
------------------------------------------------------------------------*/
struct node
       {
       int data;
       node *prev;
       node *next;
       };
       node *top = NULL;


   int compare_fn(int a,int b){
       if(a>b)
           return 1;
       else if(b>a)
           return -1;
   };

   int compare_no=1;

   struct Node {
           int x;
           struct Node *next;
           int data;
   };

class LinkedList{
public:
    // constructor
    LinkedList(){
        head = NULL; // igualamos la cabeza de la lista a NULL
    }

    // Agregar un nuevo valor al inicio de la lista
    void addValue(int val){
        Node *n = new Node();   // crea nodo
        n->x = val;             // dar valor
        n->next = head;         // hacer que el nodo apunte al siguiente nodo
                                //  si la lista esta vacia, esta null entonces head y tail es la misma.
        head = n;               // hacer que head apunte al nuevo nodo
    }

    // retornar el primer elemento y borrar el nodo
    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
    }

private:
    Node *head;
};

/*                CODIGO LISTA DOBLEMENTE ENLAZADA
 *
 *
 *
 *
 * 				CODIGO LISTA DOBLEMENTE ENLAZADA
------------------------------------------------------------------------*/

//buscar en la lista
int searchint(int x)
{
int count=0;
node *searchele=top;
while( searchele!=NULL)
{
    if(compare_fn(x,searchele->data)==compare_no)
    {
        searchele=searchele->next;
    count+=1;
    }
    else
        break;
}
return count;
}
//insertar elemento a la lista
int insertdata(int x)
{
	//verificar si esta vacia
    if(top==NULL)
    {
        top=new node;
        top->data=x;
        top->next=NULL;
        top->prev=NULL;
    }
    //sino esta vacia:
    else if(compare_fn(top->data ,x)==compare_no)
    {
        node *n=new node;
        n->data=x;
        n->next=top;
        n->prev=NULL;
        top->prev=n;
        top=n;
    }
    else
    {
    int c=searchint(x);
    node *insertele=top;
    for(int i=0;i<c-1;i++)
        insertele=insertele->next;
    node *n=new node;
    n->data=x;
    node *b=insertele->next;
    node *N =insertele;
    n->prev=insertele;
    n->next=b;
    insertele->next=n;
    if(b!=NULL)
        b->prev=n;
    }
}
//mostrar la lista
void display()
{
cout<<"Los elementos de la lista son: ";
node *disp=top;
while(disp!=NULL)
{
    cout<<" "<<disp->data;
    if(disp->next==NULL)
    {
        break;
    }
    disp=disp->next;
}
}
//eliminar de la lista
void deleteint(int x)
{
    node *del=top;
    if(del->data == x)
    {
        if(del->next==NULL && del->prev==NULL)
        {
            top=NULL;
            return;
        }
        del->next->prev=NULL;
        top=del->next;
    }
    else
    {
        node *delsuc=del->next;
        if(del==NULL)
        {
            cout<<"\nElemento NO encontrado\n";
            return;
        }
            if(delsuc==NULL)
        {
            cout<<"\nElemento NO encontrado\n";
            return;
        }
        while(delsuc->data != x)
        {
            del=del->next;
            delsuc=delsuc->next;
            if(del==NULL)
        {
            cout<<"\nElemento NO encontrado\n";
            return;
        }
            if(delsuc==NULL)
        {
            cout<<"\nElemento NO encontrado\n";
            return;
        }
        }
        del->next=delsuc->next;
        if(delsuc->next!=NULL)
        delsuc->next->prev=del;
    }
}
//invertir la lista
void reversel()
{
node *a=top;
node *b,*c,*d;
while(a!=NULL)
{
    d=a;
    c=a->next;
    b=a->prev;
    a->prev=a->next;
    a->next=b;
    a=c;
}
top=d;
cout<<"Despues de invertir la lista";
display();
compare_no*=-1;
}

/*                CODIGO LISTA CIRCULAR
 *
 *
 *
 *
 * 				CODIGO LISTA CIRCULAR
------------------------------------------------------------------------*/

//insertar elemento a la lista circular
void push(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    //si la lista no se encuentra vacia:
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    //si se encuentra la lista vacia
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

// Imprimir la lista circular
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}


int main() {

	// CODIGO LISTA ENLAZADA SIMPLE  CODIGO LISTA ENLAZADA SIMPLE
    LinkedList list;

    list.addValue(5);
    list.addValue(10);
    list.addValue(20);

    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;


    //CODIGO LISTA DOBLEMENTE ENLAZADA CODIGO LISTA DOBLEMENTE ENLAZADA

    int ch,d,y;

        char ans='y';
        while(ans=='y')
        {
            cout<<"\n\t 1.Insertar        2. Borrar        3.Invertir      4.EXIT\nIngrese una opcion : ";
            cin>>ch;
            if(ch==1)
            {
                cout<<"Ingrese elemento para ser insertado : ";
                cin>>d;
                d=insertdata(d);
                display();
            }
            else if(ch==2)
            {
                cout<<"Ingrese el elemento para eliminar: ";
                cin>>d;
                deleteint(d);
                display();
            }
            else if(ch==3)
                reversel();
            else
                return 0;
        }

        // CODIGO LISTA CIRCULAR CODIGO LISTA CIRCULAR CODIGO LISTA CIRCULAR

        //inicializar la lista
            struct Node *head = NULL;

            /* Created linked list will be 11->2->56->12 */
            push(&head, 12);
            push(&head, 56);
            push(&head, 2);
            push(&head, 11);

            printf("Contenido de la lista circular\n ");
            printList(head);

    return 0;
}
