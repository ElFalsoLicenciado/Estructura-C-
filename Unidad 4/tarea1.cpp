#include <iostream>
using namespace std;

struct Nodo
{
    int valor;
    Nodo * izq;
    Nodo * der;

    Nodo (int dato){
        valor = dato;
        izq = nullptr;
        der = nullptr;
    }

};

Nodo * raiz = nullptr;

void insertar(int dato, Nodo*& nodo){
    if(nodo == nullptr){
        nodo = new Nodo(dato);
        cout << "Se ingreso un nuevo dato " << dato << endl;
    }else if (dato < nodo->valor){
        insertar(dato, nodo->izq);

    }else{
        insertar(dato, nodo->der);
    }

}

void destruir(Nodo*& nodo){
    if(nodo == nullptr){
        return;
    }else{
        // recorrido en posorden
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
        nodo = nullptr;
    }
}

void inOrden(Nodo* nodo){
    if(nodo == nullptr){
        return;
    }else{
        inOrden(nodo->izq);
        cout << nodo->valor << " ";
        inOrden(nodo->der);
    }
}

void preOrden(Nodo* nodo){
    if(nodo == nullptr){
        return;
    }else{
        cout << nodo->valor << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

void posOrden(Nodo* nodo){
    if (nodo == nullptr){
        return;
    }
    posOrden(nodo->izq);
    posOrden(nodo->der);
    cout << nodo->valor << " ";
}

int hojas(Nodo* nodo)
{

	if(nodo == nullptr) return 0;
	
	if(nodo -> izq == nullptr && nodo -> der == nullptr) return 1;

	return hojas(nodo -> izq) + hojas(nodo -> der);
}

Nodo* eliminarNodo (int b, Nodo* nodo)
{
	if(nodo == nullptr) return nullptr;
	
	cout << nodo -> valor << endl;
	
	if (b < nodo->valor)
		nodo->izq = eliminarNodo(b, nodo->izq);
	else if (b > nodo->valor)
		nodo->der = eliminarNodo(b, nodo->der);

	else
	{
		if(nodo -> izq == nullptr || nodo -> der == nullptr)
		{
			delete nodo;
			return nullptr;
		}
		else if (nodo -> izq == nullptr)
		{
			Nodo* temp = nodo -> der;
			delete nodo;
			return temp;
		}
		else if (nodo -> der == nullptr)
		{
			Nodo* temp = nodo -> izq;
			delete nodo;
			return temp;
		}
		else
		{
			Nodo* temp = nodo -> der;
			while (temp -> izq != nullptr)
				temp = temp -> izq;
			nodo -> valor = temp -> valor;
			nodo -> der = eliminarNodo(temp -> valor, nodo -> der);
		}
	}
	return nodo;
}

bool lleno(Nodo* nodo) {
	if(nodo == nullptr) return true;

	if (nodo -> izq == nullptr && nodo -> der == nullptr) return true;

	if (nodo -> izq != nullptr && nodo -> der != nullptr) return lleno(nodo -> izq) && lleno(nodo -> der);

	return false;
}



int main(){

     // Punto 1	
	insertar(30, raiz);
	insertar(15, raiz);
	insertar(50, raiz);
	insertar(10, raiz);
	insertar(20, raiz);
	insertar(40, raiz);
	insertar(60, raiz);
	insertar(5, raiz);
	insertar(12, raiz);
	insertar(18, raiz);
	insertar(25, raiz);
	insertar(35, raiz);
	insertar(45, raiz);
	insertar(55, raiz);
	insertar(70, raiz);

     // Punto 2
	cout << "\nRecorrido en InOrden" << endl;
	inOrden(raiz);
	cout << "\nRecorrido en PreOrden" << endl;
	preOrden(raiz);
	cout << "\nRecorrido en PosOrden" << endl;
	posOrden(raiz);
	cout << "\n" << endl;

     // Punto 3
 	cout << "Nodo 15 \n";
    raiz = eliminarNodo(15,raiz);
	cout << "Nodo 60 \n";
    raiz = eliminarNodo(60,raiz);
	cout << "Nodo 5 \n";
	raiz = eliminarNodo(5,raiz);
	
	 // Punto 4
	cout << "\nRecorrido en InOrden" << endl;
	inOrden(raiz);
	cout << "\nRecorrido en PreOrden" << endl;
	preOrden(raiz);
	cout << "\nRecorrido en PosOrden" << endl;
	posOrden(raiz);

     // Punto 5
     	cout << "\n Hojas del arbol: "<< hojas(raiz) << endl;

	 // Punto 6
	if(lleno(raiz)) cout << "\nEsta lleno" << endl;
	else cout << "\nNo esta lleno" << endl;
    destruir(raiz);


    return 0;
}
