#include <iostream>
using namespace std;

struct Nodo
{
	int valor;
	Nodo *sig;
};

Nodo *front;
Nodo *fin;

void inicializar()
{
	front = NULL;
	fin =  NULL;
}


bool empty ()
{
	return (front == NULL && fin == NULL);
}

void enqueue(int x)
{
	Nodo *aux = new Nodo();
	aux->valor = x;
	aux->sig = NULL;

	if(empty()) front = aux;

	else
	{
		fin->sig = aux;
	}
	fin = aux;
	cout << "\nSe inserto un valor: " << x << endl;
}

void dequeue()
{
	if(empty()) cout << "\nLa cola esta vacia";
	else
	{
		Nodo *aux = front;
		front = front->sig;
		
		if(front==NULL) fin = NULL;
		
		delete aux;
	}
}

void show()
{
	if(empty()) cout <<"\nLa cola esta vacia";

	else
	{
		Nodo *aux = front;
		cout << "\nElementos de tu cola:";
		while(aux!=NULL)
		{	
			cout << aux->valor;
			if(aux->sig !=NULL) cout << ", ";
			aux = aux->sig;
		}

	}
}

int main()
{
	return 0;
}
