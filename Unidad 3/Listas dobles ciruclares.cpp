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
	


int main()
{
	return 0;
}
