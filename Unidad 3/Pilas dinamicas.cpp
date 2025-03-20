#include <iostream>

using namespace std;

/*
		cima
	|---|---|--*|	|   |   |
	^	  ^
	|	  |
	|	  |
	pila	puntero
	vacia	de pila

	Principio LIFO: First In Last Out

	Cada vez que se realize una accion el puntero va cambiando de posicion.
*/


struct Nodo
{
	int valor;
	Nodo *sig ;
};

struct Nodo *pila;

//Inicializar
void iniciar()
{
	pila = NULL;
}

bool vacia()
{
	if(pila == NULL) return true;
	return false;
}


void push(int x)
{
	Nodo *aux = new Nodo();
	aux->valor = x;
	aux->sig = pila;
	pila = aux;
}

void pop()
{
	if(vacia())
		cout << "La pila esta vacia";
	else
	{	
		Nodo *aux = pila;
		pila = pila->sig;
		delete aux;
	}
}

void show()
{	
	if(!vacia())
	{
		cout << "\nValores en tu pila:";
		Nodo *aux = new Nodo();
		aux = pila;
		while(aux != NULL)
		{
			cout << "\n| " << aux->valor << " |\n___";
			aux = aux-> sig;

		}		
	}
	else
		cout << "\nTu pila esta vacia";
}

void borrar()
{	
	while(!vacia())
		pop();
}




int main()
{
	int op; bool f = false;
	iniciar();

	do
	{
		cout << "\n1. Push\n2. Pop\n3. Mostrar\n4. Borrar\n0. Salir\n-->";
		cin >> op;
		switch(op)
		{
			case 1:
				cout << "\nDame un numero a introducir:\n";
				cin >> op;
				push(op);
				break;
			case 2:
				pop();
				break;
			case 3:
				show();
				break;
			case 4:
				borrar();
				break;
			case 0:
				borrar();
				f = true;
				break;
			default: ;
		}
	}
	while(!f);
}

