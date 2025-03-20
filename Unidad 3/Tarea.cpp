#include <iostream>

using namespace std;

struct Nodo
{
	char item;
	Nodo *sig;
};

struct Nodo *pila;

void iniciar()
{
	pila = NULL;
}

bool vacia()
{
	return (pila == NULL);
}

void push (char in)
{
	Nodo *aux = new Nodo();
	aux->item = in;
	aux->sig = pila;
	pila = aux;
}

void pop()
{
	if(vacia()) cout << "\nLa pila esta vacia.";
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
		Nodo *aux = pila;
		while(aux != NULL)
		{
			cout << "\n| " << aux->item<< " |";
			aux = aux->sig;
		}
	}
	else cout << "\nTu cola esta vacia.";
}


void verificador(string cad)
{
	int pa = 0;
	for(int i = 0; i<cad.length(); ++i)
	{
		cout << "\n( en pila: " << pa << "\n";
		if(cad[i] == '(')
		{	
			++pa;
			push(cad[i]);
			cout << i <<" ( encontrado.\n";
		}
		
		if(cad[i] == ')')
		{
			cout << i <<" ) encontrado.\n";
			if(pa>0)
			{
				pop();
				--pa;
			}
			else push(cad[i]);
		}
	}
	if(vacia()) cout << "\nTu expresion esta balanceada.";	
	else 
	{
		cout <<"\nTu expresion no esta balanceada.";
		show();
	}
}



int main()
{
	string cad = "((a+b/(x))-c)";
	//cout << "\nDame una cadena: "; cin >> cad; 	
	if (cad[0] == ')') cout << "No se puede iniciar con un )";
	else verificador(cad);

	return 0;
}
