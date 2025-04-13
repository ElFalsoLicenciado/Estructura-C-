#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const int LL = 60;

void iniciar();
bool vacia();
void vaciar();
void mostrar();

void agregar(string desc, int pr);
void eliminar(string desc);
void eliminar(int pr);

void guardar();
void cargar();

void bonito(string s);

int main();

struct Tarea
{
	string desc;
	int pri;
	Tarea *sig;
	Tarea *ant;

	Tarea(string tarea, int lug )
	{
		desc = tarea;
		pri = lug;
		sig = nullptr;
		ant = nullptr;
	}
};

Tarea *primera;
Tarea *ultima;

void iniciar()
{
	/*Agregar condicion que si existe un archivo JSON:
	* Si existe directamente deserializar el contenido.
	* Si no, crear este archivo y iniciar los nodos en nulo.
	*/
	primera = nullptr;
	ultima = nullptr;
}

bool vacia()
{
	return primera == nullptr;
}

void vaciar()
{
	if(!vacia())
	{
		Tarea *aux = primera;
		Tarea *sig;

		while(aux != nullptr)
		{
			sig = aux -> sig;
			delete aux;
			aux = sig;
		}
	cout << "\nAgenda vaciada." << endl;
	}
}

void mostrar()
{
	string encab(LL, '=');
	cout << encab << endl;
	if(vacia())
	{
		bonito("No hay tareas registradas en tu agenda.");
	}
	else		
	{
		Tarea *aux = primera;
		bonito("Tareas en tu agenda");
		string linea(LL,'-');
		cout << linea<<endl;	
		while(aux != nullptr)
		{
			string desc = "Descripcion: "; desc.append(aux -> desc);
			bonito(desc);

			string pri ="Prioridad: "; pri.append(to_string(aux -> pri));
			bonito(pri);

			if(aux -> sig != nullptr) cout << linea << endl;
			aux = aux -> sig;
		}
	}
	cout << encab << endl;
}

void agregar(string desc, int pr)
{
	Tarea *nueva = new Tarea(desc, pr);
	if(vacia())
	{
		primera = nueva;
		ultima = nueva;
	}
	else
	{
		Tarea *aux = primera;
		
		while(aux -> sig != nullptr && pr >= aux -> pri) aux = aux -> sig;
		
		if(pr >= aux -> pri)
		{
			ultima -> sig = nueva;
			nueva -> ant = ultima;
			ultima = nueva;
			return;
		}

		if(pr < aux -> pri)
		{
			if(aux == primera)
			{
				nueva -> sig = primera;
				if(primera != nullptr) primera -> ant = nueva;
				primera = nueva;

				if(primera -> sig == nullptr) ultima = primera;

			}
			else
			{

				nueva -> sig = aux;
				nueva -> ant = aux -> ant;
				aux -> ant -> sig = nueva;
				aux -> ant = nueva;
			}
		}
		
	}
	mostrar();
}

void eliminar(string desc)
{
	Tarea *aux = primera;

	while(aux != nullptr && aux -> desc != desc) aux = aux -> sig;

	if(aux == nullptr)
	{
		string notFound = "\nNo existe la tarea con descripcion: "; 
		notFound.append(desc);
		bonito(notFound);
	}
	else
	{
		//Primera
		
		//Medio
		
		//Ultima
	}
}

void eliminar(int pr)
{
	Tarea *aux = primera;

	while(aux != nullptr && aux -> pri != pr) aux = aux -> sig;

	if (aux == nullptr)
	{
		string notFound = "\nNo existe ninguna tarea con prioridad: ";
		notFound.append(to_string(pr));
		bonito(notFound);
	}
	else
	{
		//Primera
		
		//Medio
		
		//Ultima
	}
}

void guardar()
{
}

void cargar()
{
}

void bonito(string s )
{
   int espacios = ( LL - s.size() ) / 2;
   if ( espacios > 0 ) cout << string( espacios, ' ' );
   cout << s << '\n';
}

int main()
{
	iniciar();
	agregar("Tulan",5);
	agregar("Cande",9);
	agregar("Memo",5);
	agregar("Sergio",5);
	agregar("Arturo",6);
	agregar("Brandon",2);
	agregar("Naty",10);
	agregar("Alejandro",6);
	agregar("Cristofer",3);


	mostrar();
	vaciar();
	/*
	int op; bool f = false;
	iniciar();

	do
	{
		cout << "\n1. Agregar\n2. Eliminar\n3. Mostrar\n0. Salir\n-->";
		cin >> op;
		switch(op)
		{
			case 1:
				{
					cout << "\nDame un numero a introducir:\n";
					cin >> op;
					push(op);
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					show();
					break;
				}
			case 0:
				{
					f = true;
					break;
				}
		
		}
	}
	while(!f);
	*/
	return 0;
}
