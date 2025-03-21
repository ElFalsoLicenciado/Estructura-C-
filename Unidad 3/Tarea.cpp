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
	int pa = 0;	//Contador de "("
	for(int i = 0; i<cad.length(); ++i) //Ciclo donde se va llenando la pila con los parentesis, este ciclo se itera depnendiendo de la longitud de cad.
	{
		cout << "\n( en pila: " << pa << "\n";
		if(cad[i] == '(') //Si se encuentra un "C" se suma al contador +1 y se mete a la pila.
		{	
			++pa;
			push(cad[i]);
			cout << i <<" ( encontrado.\n";
		}
		
		if(cad[i] == ')')
		{
			cout << i <<" ) encontrado.\n";
			if(pa>0) //Si ya hay un "(" antes entonces no es necesario meter a la pila el "(" y solo se hace un solo pop para quitar el "("
			{
				pop();
				--pa;
			}
			else push(cad[i]); //Si no hay ningun "(" se mete a la pila, significando que es probable que sea uno extra o este mal acomodado.
		}
	}
	if(vacia()) cout << "\nTu expresion esta balanceada.";	//Hay la misma cantidad de "(" como de ")" y bien puestos.
	else 
	{
		cout <<"\nTu expresion no esta balanceada."; //No hay lo misma cantidad de "(" como de ")". Probablemente uno te sobro o estan mal puestos.
		show();
	}
}

void sintax(string cad) //Se encarga de buscar que ningun "(" antes que un ")". Si es el caso no se procede a verificar si esta o no balanceado.
{
	int pa = 0;
	for (int i = 0; i < cad.length(); ++i)
	{
		if(cad[i] == '(') ++pa; //Contador para cada "(" que se encuentre
		if(cad[i] == ')' && pa==0) //Si hay un ")" antes de cualquier "(" se cancela todo proceso.
		{
			cout << "\nNo autorizo";
			return;
		}
	}
	cout << "\nAutorizo";
	verificador(cad);
}

int main()
{
	string cad = "((a+b/(x))-c)";
	//cout << "\nDame una cadena: "; cin >> cad; 	
	
	sintax(cad);
	//verificador(cad);

	return 0;
}
