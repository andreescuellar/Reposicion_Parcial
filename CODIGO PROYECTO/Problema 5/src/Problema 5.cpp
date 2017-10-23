//============================================================================
// Name        : Problema.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

Nodo *lista = NULL;

void ale();
void insertarLista(Nodo *&,int );
void buscarLista(Nodo *&,int );
void mostrarLista(Nodo *);
void eliminarNodo(Nodo *&,int);

int main()
{
	int i;

		for ( i = 1; i <= 10; i++){
			insertarLista(lista,i);
		};

    ale();

    return 0;
}

void ale(){
	int num, dom;


	    srand(time(NULL));
	    num = 1 + rand() % (5 - 1);
		cout<<"Los numeros vendidos del sorteo son: \n ";
	    mostrarLista(lista);
	    buscarLista(lista,num);
	    cout <<"\t Participante " << num << " ha Ganado un Galaxy s8\n";
	    cout <<"\t El participante "<< num << " ha sido eliminado de la lista de participantes\n\n ";
	    eliminarNodo(lista,num);


	    srand(time(NULL));
	    dom = 1 + rand() % (10 - 1);
		cout<<"Los numeros vendidos del sorteo son: \n ";
	    mostrarLista(lista);
	    buscarLista(lista,dom);
	    cout <<"\t Participante " << dom << " ha Ganado un Ipad mini\n";
	    cout <<"\t El participante "<< dom << " ha sido eliminado de la lista de participantes\n\n ";
	    eliminarNodo(lista,dom);

	    cout << "La lista de participantes que no ganaron fueron: \n";
	    mostrarLista(lista);
	    cout << "Suerte en el futuro";





}

void eliminarNodo(Nodo *&lista,int n){
	//Verificar que no este vacia la lista
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;

		aux_borrar = lista;
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}

		//No se encuentra elemento
		if (aux_borrar == NULL){
			cout<<"Elemento no ha sido encontrado en la lista";
		}else if (anterior == NULL){
		//Primer elemento sera eliminado
			lista = lista->siguiente;
			delete aux_borrar;
		} else{
			//Esta en la lista pero es distinto al primero
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;

	Nodo *aux1 = lista;
	Nodo *aux2;
	//Ordenar
	while ((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	//Almacenar los datos
	if(lista == aux1){
		lista = nuevo_nodo;
	}else{
		aux2->siguiente = nuevo_nodo;
	}

	nuevo_nodo->siguiente = aux1;

}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;

	//Recorrido e impresion de toda la lista
	while (actual != NULL){

		cout<<actual->dato<<" -> ";
		actual = actual->siguiente;

	}

}


void buscarLista(Nodo *&lista,int n){
	bool band =false;

	Nodo *actual = new Nodo();
	actual = lista;
	while ((actual != NULL) && (actual->dato <= n)){
			if(actual->dato == n){
				band = true;
			}
			actual = actual ->siguiente;
	}//While

	if(band == true){
		cout<<"el numero " << n << " Si se vendio \n";
	}else{
		cout<<"el numero " << n << " NO se vendio \n";
	}
}



