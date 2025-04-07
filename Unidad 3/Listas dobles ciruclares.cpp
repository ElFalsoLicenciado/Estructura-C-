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

Nodo *cabeza; //No hace falta nodo en cabeza

void inicializar()
{
	cabeza = nullptr;
}

bool empty()
{
	return cabeza == nullptr;
}

void insertarFinal(int dato)
{
	Nodo *nuevo = new Nodo(dato);
	if(empty())
	{
		cabeza = nuevo;
		cabeza -> sig = nuevo;
		cabeza -> ant = nuevo;
	}
	else
	{
		Nodo *aux = cabeza;
		//Nodo *aux = cabeza -> ant (Para evitar el ciclo)	
		while(aux -> sig != cabeza)
			aux = aux -> sig;

		aux -> sig = nuevo;
		nuevo -> sig = cabeza;
		nuevo -> ant = aux;
		cabeza -> ant = nuevo;
	}

	cout << "\nSe inserto al final: " << dato << endl;
	return;
}


void eliminarFinal()
{
	if(empty())
	{
		cout << "\nLa lista esta vacia." << endl;
		return;
	}
	int dato;
	if(cabeza -> sig == cabeza)
	{
		dato = cabeza -> valor;
		delete cabeza;
		cabeza = nullptr;
		cout << "\nSe elimino la cabeza con valor: " << dato << endl;
		return;
	}
	else
	{
		Nodo * aux = cabeza -> ant;
		dato = aux -> valor;
		aux -> ant  -> sig = cabeza;
		cabeza -> ant = aux -> ant;
		delete aux;
		cout << "\nSe elimino el valor: " << dato << endl;
		return;
	}
}

int size()
{
	if(empty()) return 0;
	else
	{
		Nodo *aux = cabeza;
		int contador = 1;
		while ( aux -> sig != cabeza)
		{
			aux = aux -> sig;
			++contador;
		}
		return contador;
	}
}

void insertarPoscion(int dato, int posicion)
{
	if(posicion > size())
	{
		cout << "\nFuera de rango, insertando al final" << endl;
		insertarFinal(dato);
		return;
	}
	else
	{
		Nodo *nuevo = new Nodo(dato);
		
		if(posicion==1)
		{
			nuevo -> sig = cabeza;
			cabeza -> ant -> sig = nuevo;
			nuevo -> ant = cabeza -> ant;
			cabeza -> ant = nuevo;
			cabeza - nuevo;
			cout << "\nSe inserto u nuevo dato: " << dato << endl;
			return;
		}
		else
		{
			Nodo *aux = cabeza;
			int contador = 1;

			while(contador < posicion - 1)
			{
				aux = aux -> sig;
				++contador;
			}
			
			nuevo -> sig = aux -> sig;
			aux -> sig = nuevo;
			nuevo -> sig -> ant = nuevo;
			nuevo -> ant = aux;
			cout << "\nSe inserto un nuevo dato: " << dato << endl;
			return;			
		}
}

int main()
{
	return 0;
}
