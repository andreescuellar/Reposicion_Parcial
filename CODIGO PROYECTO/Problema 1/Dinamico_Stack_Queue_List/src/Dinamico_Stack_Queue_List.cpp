//============================================================================
// Name        : Dinamico_Stack_Queue_List.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <stdlib.h>

using namespace std;

/*                CODIGO DE LA PILA
 *
 *
 *
 *
 * 				CODIGO PILA
------------------------------------------------------------------------*/
//Estructura nodo 1
struct nodo{
    int nro;
    struct nodo *sgte;
};
//Estructura nodo 2
struct Nodo{
	int dato;
	Nodo *siguiente;
};

Nodo *lista = NULL;


typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de dato )

//Apilar elemento

void push( ptrPila &p, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;

     aux->sgte = p ;
     p = aux ;
}

// Desapilar elemento(devuelve elemento)
int pop( ptrPila &p )
{
     int num ;
     ptrPila aux;

     aux = p ;
     num = aux->nro;   // asignamos el primer vamor de la pila

     p = aux->sgte ;
     delete(aux);

     return num;
}

//Muestra elementos de la pila

void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista

     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }
}

//Eliminar todos los elementos de la pila

void destruir_pila( ptrPila &p)
{
     ptrPila aux;

     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           delete(aux);
     }
}

//Menu de opciones
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n\n";
    cout<<" 1. APILAR                                "<<endl;
    cout<<" 2. DESAPILAR                             "<<endl;
    cout<<" 3. MOSTRAR PILA                          "<<endl;
    cout<<" 4. DESTRUIR PILA                         "<<endl;
    cout<<" 5. SALIR                                 "<<endl;

    cout<<"\n INGRESE OPCION: ";
}


/*                CODIGO DE LA COLA
 *
 *
 *
 *
 * 				CODIGO COLA
------------------------------------------------------------------------*/
// ver si la cola esta vacia

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

//ingresar elementos a la cola
void insertarCola(Nodo *&frente, Nodo*&fin, int n){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}

	cout<< "\tElemento " << n << " encolado correctamente\n";

}

//borrar cola

void suprimirCola(Nodo *&frente, Nodo*&fin, int &n){

	n = frente->dato;
	Nodo *aux = frente;

	if(frente == fin){
		frente == NULL;
		fin == NULL;
	}else{
		frente = frente->siguiente;

	}

	delete aux;

}

/*                CODIGO DE LA LISTA
 *
 *
 *
 *
 * 				CODIGO LISTA
------------------------------------------------------------------------*/

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

	cout<<"\tElemento " << n << " ha ingresado correctamente \n\n";
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;

	cout<<"La Lista ya ordenada en orden creciente es: \n ";
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
		cout<<"elemeto " << n << " Se encuentra en la lista \n";
	}else{
		cout<<"elemeto " << n << " NO se encuentra en la lista \n";
	}
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




/*                        Funcion Principal
------------------------------------------------------------------------*/
int main()
{
	//PILA PILA PILA PILA

    ptrPila p = NULL;  // creando pila
    int dato;
    int op;
    int x ; // numero que devuelve la funcon pop

    system("color 0b");

    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n NUMERO A APILAR: "; cin>> dato;
                 push( p, dato );
                 cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
            break;


            case 2:

                 x = pop( p );
                 cout<<"\n\n\t\tNumero "<< x <<" desapilado...\n\n";
            break;


            case 3:

                 cout << "\n\n MOSTRANDO PILA\n\n";
                 if(p!=NULL)
                    mostrar_pila( p );
                 else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;


            case 4:

                 destruir_pila( p );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;

         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=5);



    //COLA COLA COLA COLA

    Nodo *frente = NULL;
    		Nodo *fin = NULL;

    		int dato;

    		cout<<"Ingrese un numero";
    		cin>>dato;

    		insertarCola(frente, fin, dato);

    		//Eliminar cola
    		while(frente != NULL){
    			suprimirCola(frente, fin, dato);

    			if(frente != NULL){
    				cout<<dato<< " , ";
    			}else{
    				cout<<dato<< " . ";
    			}
    		}


    //LISTA LISTA LISTA LISTA

    		int dato;

    			//Solicitar datos
    			cout<<"Ingrese un numero: "<< endl;
    			cin>>dato;
    			insertarLista(lista,dato);

    			cout<<"Ingrese un numero: "<< endl;
    			cin>>dato;
    			insertarLista(lista,dato);

    			cout<<"Ingrese un numero: "<< endl;
    			cin>>dato;
    			insertarLista(lista,dato);

    			//Impresion
    			mostrarLista(lista);

    			cout<<"\n\nIngrese el numero a buscar: "<< endl;
    			cin>>dato;
    			buscarLista(lista,dato);

    			cout<<"\n\nIngrese el nodo que desea eliminar: "<< endl;
    			cin>>dato;
    			eliminarNodo(lista,dato);

    			mostrarLista(lista);

    return 0;
}
