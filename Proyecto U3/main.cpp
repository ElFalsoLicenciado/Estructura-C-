#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const int LL = 60;
const string encab(LL,'=');
const string encab2(LL,'-');
const string encab3(LL, '+'); 
const string encab4(LL,'*');
const string warn(LL,'!');
const string ques(LL,'?');


struct Tarea;

void iniciar();
bool vacia();
void vaciar();
void mostrar();

void agregar(string desc, int pr);
void eliminar(string desc);
void eliminar(int pr);

void eliminacion(Tarea *del);

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
	cout << "\n" << encab << endl;
	if(vacia())
	{
		cout << warn << endl;
		bonito("No hay tareas registradas en tu agenda.");
		cout << warn << endl;
	}
	else		
	{
		Tarea *aux = primera;
		bonito("Tareas en tu agenda");
		
		cout << encab3 <<endl;	
		while(aux != nullptr)
		{
			string desc = "Descripcion: "; desc.append(aux -> desc);
			bonito(desc);

			string pri ="Prioridad: "; pri.append(to_string(aux -> pri));
			bonito(pri);

			if(aux -> sig != nullptr) cout << encab3 << endl;
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
			mostrar();
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
	if(vacia())
	{
		cout << warn << endl;
		bonito("No hay tareas registradas en tu agenda.");
		cout << warn << endl;
		return;
	}

	Tarea *aux = primera;

	while(aux != nullptr && aux -> desc != desc) aux = aux -> sig;

	if(aux == nullptr)
	{
		cout << warn << endl;
		string notFound = "No existe la tarea con descripcion: "; 
		notFound.append(desc);
		bonito(notFound);
		cout << warn << endl;
	}
	else 
	{
		eliminacion(aux);
		mostrar();
	}
}

void eliminar(int pr)
{
	if(vacia())
	{
		cout << warn << endl;
		bonito("No hay tareas registradas en tu agenda.");
		cout << warn << endl;
		return;
	}
	Tarea *aux = primera;

	while(aux != nullptr && aux -> pri != pr) aux = aux -> sig;

	if (aux == nullptr)
	{
		cout << warn << endl;
		string notFound = "No existe ninguna tarea con prioridad: ";
		notFound.append(to_string(pr));
		bonito(notFound);
		cout << warn << endl;
	}
	else 
	{
		eliminacion(aux);
		mostrar();
	}
}

void eliminacion(Tarea *del)
{
	cout << "\n" << encab4 << endl;
	bonito("Se elimino una tarea");
	cout << encab2 << endl;
	string elimDesc = "Descripcion: "; elimDesc.append(del -> desc);
	bonito(elimDesc);
	string elimPri = "Prioridad: ";elimPri.append(to_string(del -> pri));
	bonito(elimPri);
	//Primera y Ultima
	
	if(del == primera)
	{
		primera = del -> sig;
		if(primera != nullptr) primera -> ant = nullptr;
		
		else ultima = nullptr;

		delete del;
		
		cout << encab4 << endl;	
		return;
	}
	
	if(del -> ant != nullptr) del -> ant -> sig = del -> sig;
	if(del -> sig != nullptr) del -> sig -> ant = del -> ant;
	delete del;
	cout << encab4 << endl;
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
	
	/*agregar("Tulan",5);
	agregar("Tulan",6);
	agregar("Cande",7);
	agregar("Memo",5);
	agregar("Sergio",5);
	agregar("Arturo",6);
	agregar("Brandon",2);
	agregar("Naty",10);
	agregar("Alejandro",6);
	agregar("Cristofer",3);
	
	eliminar(7);
	eliminar(6);
	eliminar(5);


	vaciar();
	*/

	int op; bool f = false;
	iniciar(); cargar();

	do
	{
		cout << "\n1. Agregar\n2. Eliminar\n3. Mostrar\n0. Salir\n-->";
		cin >> op;
		switch(op)
		{
			case 1:
				{
					string desc;
					
					cout << ques << endl;
					bonito("Dame la descripcion: ");
					cin >> desc;

					cout << encab2 << endl;
					bonito("Y la prioridad: ");
					cin >> op;
					cout << ques << endl;

					agregar(desc,op);
					break;
				}
			case 2:
				{
					cout << ques << endl;
					bonito("1. Descripcion 2. Prioridad 0. Salir");
					cout << ">>";
					cin >> op;
					cout << ques << endl;

					if(op == 0) break;
					
					if(op == 1)
					{
						string desc;
						bonito("Dame la descripcion: ");
						cin >> desc;
						cout << ques << endl;

						eliminar(desc);
						break;
					}
					bonito("Dame la prioridad: ");
					cin >> op;
					cout << ques << endl;

					eliminar(op);
					break;

				}
			case 3:
				{
					mostrar();
					break;
				}
			case 0:
				{
					f = true;
					cout << ques << endl;
					bonito("Deseas guardar tu agenda");
					cout << endl;
					bonito("1. Si 0. No");
					cout << ques << endl;

					cin >> op;

					if(op == 1) guardar();
					vaciar();
					break;
				}
			default :
				{
					break;
				}
		}
	}
	while(!f);
	return 0;
}
