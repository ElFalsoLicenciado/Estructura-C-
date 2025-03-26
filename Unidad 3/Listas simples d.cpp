#include <iostream>

using namespace std;

/*	Listas simples: Es una estructura de datos que colecciona los elementos
 *	organizados de manera secuencial, donde cada elemento una posición entre
 *	ella.
 *	1. Lista simplemente enlazada
 *	2. Lista doblemente enlazada
 *	3. Lista circular simplemente enlazada
 *	4. Lista circular doblemente enlazada
 *
 */


struct Nodo
{
	int valor;
	Nodo *sig;

	Nodo(int x)
	{
		valor = x;
		sig = nullptr;
	}
};

Nodo *cabeza;

void inicializar()
{
	cabeza = nullptr;
}

bool empty()
{
	return cabeza=nullptr;
}

void insertarFinal(int dato)
{
	Nodo *nuevo = new Nodo(dato);
	if(empty()) cabeza = nuevo;
	else
	{
		Nodo *aux = cabeza;
		while(aux->sig != nullptr) aux = aux->sig;
		aux->sig = nuevo;
	}
	cout << "\nSe ha insertado: " << dato << endl;
}

void insertarPosicion(int dato, int posicion)
{
	Nodo *nuevo = new Nodo(dato);

	if(posicion == 0)
	{
		nuevo->sig = cabeza;
		cabeza = nuevo;
		return;
	}

	Nodo *aux = cabeza;

	int contador = 0;

	while(aux!=nullptr && contador < posicion)
	{
		aux = aux->sig;
		++contador;
	}

	if(aux==nullptr) 
	{
		cout << "\nFuera de rango" << endl;
		return;
	}

}


int main()
{
	return 0;
}
