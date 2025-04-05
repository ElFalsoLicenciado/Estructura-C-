#include <iostream>
using namespace std;
 
struct Nodo{
 	int valor;
 	Nodo * sig;

 	Nodo(int dato){
  	valor=dato;
  	sig=NULL;
 	} 
};

Nodo *cabeza;

void inicializar() {
    cabeza = NULL;
}

bool empty() {
    return cabeza == NULL;
}

void insertarFinal(int dato) {
    	Nodo *nuevo = new Nodo(dato); 
    	if (empty()) {
        	cabeza = nuevo;
        	nuevo->sig = cabeza;
 	}else{
  		Nodo * aux = cabeza;
  		while (aux->sig != cabeza)
  		{
  			aux = aux->sig;
  		}
  		aux->sig = nuevo;
  		nuevo->sig = cabeza;
 	}
 cout << "Se inserto un valor: " << dato << endl;
}

void eliminarFinal()
{
  	Nodo *aux = cabeza;
	if(empty())
	{
		cout << "\nLa lista esta vacia" << endl;
	}
	if(cabeza -> sig != cabeza)
	{
		delete cabeza;
		cabeza = nullptr;
		cout << "\nSe elimino la cabeza" << endl;
		return;
	}

	Nodo *ultimo = aux -> sig;
	aux -> sig = cabeza;
	delete ultimo;
	cout << "\nSe elimino un valor" << endl;
}

int size()
{
	if(empty()) return 0;
	else
	{
		Nodo *aux = cabeza;
		int contador = 0;
		while(aux -> sig != cabeza)
		{
			++contador;
			aux = aux -> sig;
		}
		return contador;
	}
}

void insertarPosicion(int dato, int posicion)
{
	if(posicion > size())
	{
		cout << "\nPosicion fuera de rango, insertando al final..." << endl;
		insertarFinal(dato);
		return;
	}

	Nodo *nuevo = new Nodo(dato);
	if(posicion == 1)
	{
		Nodo *aux= cabeza;
		while(aux -> sig != cabeza) aux = aux -> sig;

		nuevo -> sig = cabeza;
		aux -> sig =nuevo;
		cabeza = nuevo;
	}
	else
	{
		int contador = 1;
		Nodo *aux = cabeza;
		while(contador < posicion-1)
		{
			aux = aux -> sig;
			++contador;
		}
		nuevo -> sig = aux -> sig;
		aux -> sig = nuevo;
	}
	cout << "\nSe inserto un dato " << dato << endl;
	return;
}

void eliminarPosicion(int posicion)
{
	if(empty())
	{
		cout << "\nNada para borrar" << endl;
		return;
	}

	if(posicion > size())
	{
		cout << "\nPosicion fuera de rango, elimando ultimo" << endl;
		eliminarFinal();
		return;
	}

	if(posicion == 1)
	{
		if(cabeza -> sig == cabeza)
		{
			delete cabeza;
			cabeza = nullptr;
		
		}
		else
		{
			Nodo *aux = cabeza;
			while(aux -> sig != cabeza)
			{
				aux = aux -> sig;
			}
			Nodo * primero = cabeza;
			cabeza = cabeza -> sig;
			delete primero;
			aux -> sig = cabeza;
		}
		cout << "\nSe elimino la cabeza" << endl;
		return;
	}
	else
	{
		Nodo *aux = cabeza;
		Nodo *anterior;
		int contador = 1;

		while(contador < posicion)
		{
			anterior = aux;
			aux = aux -> sig;
			++contador;
		}
		anterior -> sig = aux -> sig;
		delete aux;
		
	}
	cout << "\nSe elimino un dato" << endl;
	return;

}

void eliminarValor(int valor)
{
	if(empty())
	{
		cout << "\nLista vacia" << endl;
		return;
	}

	if (cabeza -> valor == valor)
	{
		eliminarPosicion(1);
		return;
	}
	else
	{
		Nodo *aux = cabeza;
		Nodo *anterior = nullptr;

		do
		{
			if(aux -> valor == valor)
			{
				anterior = aux -> sig;
				delete aux;
				cout << "\nSe elimno el valor " << valor << endl;
				return;
			}
			anterior = aux;
			aux = aux -> sig;
			return;
		}while(aux != cabeza);
		cout << "\nNo se encontro nada" << endl;
		return;
	}
}


int main()
{
	return 0;
}
