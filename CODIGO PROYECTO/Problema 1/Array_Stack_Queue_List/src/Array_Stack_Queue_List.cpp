//============================================================================
// Name        : Array_Stack_Queue_List.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================



#include<iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX_SIZE 101  //maxima capacidad para la Queue.

/*                CODIGO DE LA COLA
 *
 *
 *
 *
 * 				CODIGO COLA
------------------------------------------------------------------------*/

// Creando la clase Queue (Cola)
class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear;
public:
	// Constructor
	// Asumiento la cola vacia.
	Queue()
	{
		front = -1;
		rear = -1;
	}

	// Chequear que la cola este vacia.
	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}

	// Chequear que la cola este llena.
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Encolar
	void Enqueue(int x)
	{
		cout<<" Encolado "<<x<<" \n";
		if(IsFull())
		{
			cout<<"Error: la Cola esta llena \n";
			return;
		}
		if (IsEmpty())
		{
			front = rear = 0;
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}

	// Desencolar
	void Dequeue()
	{
		cout<<"Desencolado \n";
		if(IsEmpty())
		{
			cout<<"Error: La cola esta vacia\n";
			return;
		}
		else if(front == rear )
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Retornar elemento al frente de la cola/
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: No se puede devolver de una Cola Vacia \n";
			return -1;
		}
		return A[front];
	}
	/*
	   Imprimir la cola.
	*/
	void Print()
	{
		// Finding number of elements in queue
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};

/*                CODIGO DE LA PILA
 *
 *
 *
 *
 * 				CODIGO PILA
------------------------------------------------------------------------*/
class IntStack
{
public:

   IntStack(int num) {  top = 0; maxelem = num; s = new int[maxelem]; }
   //funcion para meter de la pila
   void  push(int t)
   {
      if (top == maxelem) return;
      s[top++] = t;
   }
   //funcion para sacar de la pila
   int pop()
   {
      if (top == 0) return -1;
      return s[--top];
   }
   //funcion para mostrar la pila
   void display()
   {
     if (top == 0) { cout << "(Vacio)\n";  return; }
     for (int t=0 ; t < top ; t++) cout << s[t] << " ";
     cout << "\n";
   }
   //ver si la pila esta vacia
   int   empty()  {  return top == 0;  }

private:
   int *s;
   int top;
   int maxelem;
};

/*                CODIGO DE LA LISTA
 *
 *
 *
 *
 * 				CODIGO LISTA
------------------------------------------------------------------------*/
class List
{
public:

    //   Constructor por DEFAULT
    List();
    // Deconstructor para liberar memoria
    ~List();

    List(const List& value);
    void Insert(const int);
    void display(void) const;

private:
    int size;// MAXIMO tamaño de la lista
    int count;// numero de elementos en la lista

protected:
    int *intptr;// puntero
};

// CONSTRUCTOR
List::List() {
    size = 2; // inicializando tamaño
    count = 0;
    intptr = new int[size]; //
}
// DECONSTRUCTOR
List::~List() {
    delete[] intptr; // liberar memoria
}

List::List(const List& value) {
    size = value.size;
    cout << "copiando con size : " << size << endl;
    count = value.count;

    cout << "Compy count : " << count << endl;
    if (count < size) {
        intptr = new int[size];
        intptr = new int[size + 2];
    }

    for (int index = 0; index < count; index++) {
        intptr[index] = value.intptr[index];
    }

    size = size + 2;
    delete[] intptr;
    intptr = value.intptr;
}

void List::Insert(const int value) {
    //
    if (count < size) {
        intptr[count] = value;
    } else { // se agrega mas espacio si ya esta lleno
        intptr[count] = value; //EEP copy invoked with copy constructor
    }

    cout << "Tamaño: " << size << endl;
    cout << "Contador" << count << endl;
    count++; // Increase items added in array
}

void List::display() const {
    for (int i = 0; i < count; i++)
        cout << intptr[i] << endl;
}

int main()
{

	//COLA COLA COLA COLA

   Queue Q;
   Q.Enqueue(2);  Q.Print();
   Q.Enqueue(4);  Q.Print();
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();

   //PILA PILA PILA PILA
   IntStack *s = new IntStack(100);
      int d;

      s->display();
      s->push(1);
      s->display();
      s->push(2);
      s->display();
      s->push(3);
      s->display();
      s->push(4);
      s->display();
      s->pop();
      s->display();
      s->pop();
      s->display();
      s->push(10);
      s->display();
      s->pop();
      s->display();
      s->pop();
      s->display();
      s->pop();
      s->display();
      s->pop();
      s->display();
      s->pop();
      s->display();

      // LISTA LISTA LISTA LISTA

      List mylist;

          mylist.Insert(5);
          mylist.Insert(6);
          mylist.Insert(2);
          mylist.Insert(8);
          mylist.Insert(4);
          mylist.Insert(5);
          mylist.Insert(9);
          mylist.Insert(8);
          mylist.Insert(5);
          mylist.Insert(9);
          mylist.Insert(8);
          mylist.Insert(5);
          mylist.Insert(9);
          mylist.Insert(8);
          mylist.Insert(5);
          mylist.Insert(9);

          mylist.display();

          return 0;

}
