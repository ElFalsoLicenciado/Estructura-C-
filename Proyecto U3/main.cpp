#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"

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
bool cargar();

void centrar(string s);

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
	primera = nullptr;
	ultima = nullptr;
	cargar();
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
		primera = ultima = nullptr;
	}
}

void mostrar()
{
	cout << "\n" << encab << endl;
	if(vacia())
	{
		cout << warn << endl;
		centrar("No hay tareas registradas en tu agenda.");
		cout << warn << "\n" <<endl;
	}
	else		
	{
		Tarea *aux = primera;
		centrar("Tareas en tu agenda");
		
		cout << encab3 <<endl;	
		while(aux != nullptr)
		{
			string desc = "Descripcion: "; desc.append(aux -> desc);
			centrar(desc);

			string pri ="Prioridad: "; pri.append(to_string(aux -> pri));
			centrar(pri);

			if(aux -> sig != nullptr) cout << encab3 << endl;
			aux = aux -> sig;
		}
	}
	cout << encab << "\n" << endl;
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
}

void eliminar(string desc)
{
	if(vacia())
	{
		cout << warn << endl;
		centrar("No hay tareas registradas en tu agenda.");
		cout << warn << "\n" << endl;
		return;
	}

	Tarea *aux = primera;

	while(aux != nullptr && aux -> desc != desc) aux = aux -> sig;

	if(aux == nullptr)
	{
		cout << warn << endl;
		string notFound = "No existe la tarea con descripcion: "; 
		notFound.append(desc);
		centrar(notFound);
		cout << warn << "\n" << endl;
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
		centrar("No hay tareas registradas en tu agenda.");
		cout << warn << "\n" << endl;
		return;
	}
	Tarea *aux = primera;

	while(aux != nullptr && aux -> pri != pr) aux = aux -> sig;

	if (aux == nullptr)
	{
		cout << warn << endl;
		string notFound = "No existe ninguna tarea con prioridad: ";
		notFound.append(to_string(pr));
		centrar(notFound);
		cout << warn << "\n" << endl;
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
	centrar("Se elimino una tarea");
	cout << encab2 << endl;
	string elimDesc = "Descripcion: "; elimDesc.append(del -> desc);
	centrar(elimDesc);
	string elimPri = "Prioridad: ";elimPri.append(to_string(del -> pri));
	centrar(elimPri);
	//Primera y Ultima
	
	if(del == primera)
	{
		primera = del -> sig;
		if(primera != nullptr) primera -> ant = nullptr;
		
		else ultima = nullptr;

		delete del;
		
		cout << encab4 << "\n" << endl;	
		return;
	}
	
	if(del -> ant != nullptr) del -> ant -> sig = del -> sig;
	if(del -> sig != nullptr) del -> sig -> ant = del -> ant;
	delete del;
	cout << encab4 << "\n" << endl;
}


void guardar()
{
		ofstream archivo("C:/Users/User/Documents/JetBrains/CLion Projects/Estructura de Datos/Proyecto U3/tareas.json");

	if(vacia())
	{
		archivo.close();
		cout << warn << endl;
		centrar("No hay nada que guardar");
		cout << warn << "\n" << endl;
		return;
	}

	json jTareas = json::array();
	Tarea *aux = primera;

	while(aux != nullptr)
	{
		json tareaJson = {
			{"pri", aux -> pri},
			{"desc", aux -> desc},
		};
		jTareas.push_back(tareaJson);
		aux = aux -> sig;
	}
	
	archivo << jTareas.dump(4);
	archivo.close();

	cout << encab3 << endl;
	centrar("Archivo guardado correctamente.");
	cout << encab3 << "\n" << endl;


}

bool cargar()
{
	ifstream archivo;
	archivo.open("C:/Users/User/Documents/JetBrains/CLion Projects/Estructura de Datos/Proyecto U3/tareas.json");

	if(!archivo.is_open())
	{
		cout << warn << endl;
		centrar("No hay una agenda previa.");
		centrar("Creando una nueva...");
		cout << warn << "\n" << endl;
		return false;
	}

	else
	{
		json jTareas;
		archivo >> jTareas;
		archivo.close();

		for(const auto& tareas : jTareas)
		{
			int pri = tareas["pri"].get<int>();
			string desc= tareas["desc"].get<string>();

			agregar(desc,pri);
		}
		cout << encab3 << endl;
		centrar("Agenda cargada correctamente.");
		cout << encab3 << "\n" << endl;

		return true;
	}

}

void centrar(string s )
{
   int espacios = ( LL - s.size() ) / 2;
   if ( espacios > 0 ) cout << string( espacios, ' ' );
   cout << s << '\n';
}

int main()
{
	/*
	json Ordenes = json::array();
	int xd = 2;
	json orden =
		{
			{"comida", "Sushi"},
			{"orden", 2},
			{"pointer", nullptr},
			{"empleado", "Pedro"}
		};
	Ordenes.push_back(orden);

	ofstream file("C:/Users/User/Documents/JetBrains/CLion Projects/Estructura de Datos/Proyecto U3/foods.json");
	file << Ordenes.dump(4);
	file.close();
	*/	
	
		
	int op; bool f = false;
	iniciar();

	do
	{	
		cout << encab4 << endl;
		centrar("Bienvenido a tu administrador de tareas.");
		cout << encab << endl;

		cout << ques << endl;
		centrar("Que quieres hacer?");
		centrar("1. Agregar"); centrar("2. Eliminar"); centrar("3. Mostrar");
		centrar("4. Vaciar"); centrar("0. Salir");
		centrar("--> ");
		cin >> op;
		cout << ques << "\n" <<endl;
		switch(op)
		{
			case 1:
				{
					string desc;
					
					cout << ques << endl;
					centrar("Dame la descripcion: ");
					cin >> desc;

					cout << encab2 << endl;
					centrar("Y la prioridad: ");
					cin >> op;
					cout << ques << endl;

					agregar(desc,op);
					mostrar();
					break;
				}
			case 2:
				{
					cout << ques << endl;
					centrar("1. Descripcion 2. Prioridad 0. Salir");
					cout << ">>";
					cin >> op;
					cout << ques << endl;

					if(op == 0) break;
					
					if(op == 1)
					{
						string desc;
						centrar("Dame la descripcion: ");
						cin >> desc;
						cout << ques << endl;

						eliminar(desc);
						break;
					}
					centrar("Dame la prioridad: ");
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
			case 4:
				{
					vaciar();
					cout << encab2 << endl;
					centrar("Agenda vaciada.");
					cout << encab2 << "\n" << endl;
					break;
				}
			case 0:
				{
					f = true;
					cout << ques << endl;
					centrar("Deseas guardar cambios?");
					cout << endl;
					centrar("1. Si 0. No");
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
