#include <iostream>

using namespace std;


struct Nodo
{
	int valor;
	Nodo *sig;
	Nodo *ant;

	Nodo (int dato)
	{
		valor = dato;
		sig = nullptr;
		ant = nullptr;
	}
};

Nodo * cabeza;
Nodo * cola;

void inicializar()
{
	cabeza = nullptr;
	cola = nullptr;
}

bool empty()
{
	return cabeza==nullptr; //Si la cabeza es null tambien la cola deberia serlo
}

int numeroNodos()
{
	if(empty())
	{
		return 0;
	}
	
	Nodo *aux = cabeza;
	int contador = 0;
	while(aux != nullptr)
	{
		aux = aux -> sig;
		++contador;
	}
	return contador;

}


void insertarFinal(int dato)
{	
	Nodo * nuevo = new Nodo(dato);

	if(empty())
	{
		cabeza = nuevo;
		cola = nuevo;		
	}
	else
	{
		cola -> sig = nuevo;
		nuevo -> ant = cola;
		cola = nuevo;
	}
	cout << "\nSe inserto: " << dato << endl;
}

void insertarPosicion(int dato, int posicion)
{
	int tamano = numeroNodos();

	if(posicion > tamano)
	{
		cout << "\nOut of range" << endl;
		insertarFinal(dato);
	}

	Nodo *nuevo = new Nodo(dato);
	
	if(posicion == 1)
	{
		nuevo -> sig = cabeza;
		if(cabeza == nullptr) cabeza -> ant = nuevo;
		cabeza = nuevo;

		if(cabeza -> sig == nullptr) cola = cabeza;
		cout << "\nSe inserto: " << dato << endl;
		return;
	}
	Nodo * aux = cabeza;
	int contador = 1;

	while(aux != nullptr && contador < posicion-1)
	{
		aux = aux -> sig;
		++contador;
	}

	nuevo -> sig = aux -> sig;
	nuevo -> ant = aux;
	aux -> sig = nuevo;

	if(aux -> sig != nullptr) nuevo -> sig -> ant = nuevo;

	return;
}

void eliminarPosicion(int posicion)
{
	if(empty())
	{
		cout << "\nLa lista esta vacia" << endl;
		return;
	}
	
	Nodo *aux = cabeza;
	if(posicion==1)
	{
		cabeza = aux -> sig;

		if(cabeza != NULL) cabeza -> ant = nullptr;
		
		else cola = nullptr;
		cout << "\nSe elimino: " << aux -> valor << endl;
		delete aux;
		return;
	}
	else
	{
		int contador = 1;
		while(aux != nullptr && contador < posicion)
		{
			aux = aux->sig;
			++contador;
		}
		if(aux == nullptr)
		{
			cout << "\nPosicion fuera de rango" << endl;
			return;
		}

		if(aux -> sig != nullptr) aux -> sig -> ant = aux -> ant;
		if(aux -> ant != nullptr) aux -> ant -> sig = aux -> sig;
		if(aux == cola) cola = cola -> ant;

		cout << "\nSe elimino: " << aux -> valor << endl;
		delete aux;
	}
}

void mostrar()
{	
	if(empty()) 
	{
		cout << "\nTu lista esta vacia";
		return;
	}
	
	cout <<"\nItems de tu lista: ";
	Nodo *aux = cabeza;
	while(aux!=nullptr)
	{
		cout << aux->valor;
		if(aux->sig!=nullptr) cout << ", ";
		aux = aux->sig;	
	}
	return;
	
}

void destruir()
{
	Nodo *aux = cabeza;
	Nodo *sig;

	while(aux != nullptr)
	{
		sig = aux -> sig;
		delete aux;
		aux = sig;
	}
}


int main()
{
	inicializar();
	insertarFinal(10);
	insertarFinal(20);
	insertarPosicion(15,2);
	mostrar();

	destruir();
	return 0;
}
