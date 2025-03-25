#include <iostream>

using namespace std;

/* 		Bicolas: Permite insertar y eliminar elementos desde ambos extremos,
 *  		tanto desde el frente como desde el final, 
 *  		lo que la hace más flexible que una cola tradicional,
 *  		que solo permite operaciones en un extremo (el frente).
 *
 *
 *  		Dado que permite eliminar elementos desde el final (o insertar 
 *  		desde el principio), una bicola puede ser 
 *  		utilizada en situaciones en las que no necesitas 
 *  		la restricción de FIFO, sino que busques más flexibilidad
 *  		para las operaeiones.	
 *
 */

struct Nodo
{
	int valor;
	Nodo *sig;
	Nodo *ant;
};

Nodo *frente;
Nodo *fin;

void inicializar()
{
	frente = nullptr;
	fin = nullptr;
}

bool empty()
{
	return (frente == nullptr && fin == nullptr);
}

void enqueueFin(int x)
{
	Nodo *aux = new Nodo();
	aux->valor = x;
	aux->sig = nullptr;
	aux->ant = nullptr;

	if(empty())
	{
		frente = aux;
		fin = aux;
	}
	else
	{
		fin->sig = aux;
		aux->ant = fin;
		fin = aux;
	}

	cout << "\nSe ha insertado: " << x << endl;
}

void dequeueFin()
{
	if(empty()) cout << "\nNo hay nada que eliminar." << endl;
	else
	{
		Nodo *aux = fin;
		fin = fin->ant;

		if(fin != nullptr) fin->sig = nullptr;
		else frente = nullptr;

		delete aux;
	}
}

void enqueueFrente(int x)
{
	Nodo *aux = new Nodo();
	aux->valor = x;
	aux->sig = frente;
	aux->ant = nullptr;

	if(empty())
	{
		frente = aux;
		fin = aux;
	}
	else
	{
		frente->ant = aux;
		frente = aux;
	}
	cout << "\nSe ha insertado: " << x << endl;
}

void dequeueFrente()
{
	if(empty()) cout << "\nNo hay nada que eliminar." << endl;
	else
	{
		Nodo *aux = frente;
		frente = frente->sig;

		if(frente != nullptr) frente->ant = nullptr;
		else fin = nullptr;

		delete aux;
	}
}

void show()
{
	if(empty()) cout << "\nNo hay nada que mostrar" << endl;
	else
	{
		cout << "\nElementos:";
		Nodo *aux = frente;
		while(aux != nullptr)
		{
			cout << " " << aux->valor;
			aux = aux->sig;
		}
		cout << endl;
	}
}

void destruction()
{	
	while(!empty()) dequeueFin();
}


int main()
{
	enqueueFin(10);
	enqueueFin(20);
	enqueueFin(30);
	show();

	dequeueFin();
	show();

	enqueueFrente(5);
	enqueueFrente(8);
	show();

	dequeueFrente();
	show();

	destruction();
	return 0;
}
