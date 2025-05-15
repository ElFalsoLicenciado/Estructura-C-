#include <iostream>
using namespace std;

struct Nodo
{
    int valor;
    Nodo * izq;
    Nodo * der;

    Nodo (int dato){
        valor = dato;
        izq = NULL;
        der = NULL;
    }

};

Nodo * raiz = NULL;

void insertar(int dato, Nodo*& nodo){
    if(nodo == NULL){
        nodo = new Nodo(dato);
        cout << "Se ingreso un nuevo dato " << dato << endl;
    }else if (dato < nodo->valor){
        insertar(dato, nodo->izq);

    }else{
        insertar(dato, nodo->der);
    }

}

void destruir(Nodo*& nodo){
    if(nodo == NULL){
        return;
    }else{
        // recorrido en posorden
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
        nodo = NULL;
    }
}

void inOrden(Nodo* nodo){
    if(nodo == NULL){
        return;
    }else{
    inOrden(nodo->izq);
    cout << nodo->valor << " ";
    inOrden(nodo->der);
}
}

void preOrden(Nodo* nodo){
    if(nodo == NULL){
        return;
    }else{
        cout << nodo->valor << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

void posOrden(Nodo* nodo){
    if (nodo == NULL){
        return;
    }
    posOrden(nodo->izq);
    posOrden(nodo->der);
    cout << nodo->valor << " ";
}


int main(){
    insertar(10, raiz);
    insertar(8, raiz);
    insertar(9, raiz);
    insertar(7, raiz);
    insertar(12, raiz);
    insertar(11, raiz);
    insertar(13, raiz);
    cout << "Recorrido en InOrden: ";
    inOrden(raiz);
    cout << "\n";
    cout << "Recorrido en preOrden: ";
    preOrden(raiz);
    cout << "\n";
    cout << "Recorrido en posOrden: ";
    posOrden(raiz);



    destruir(raiz);


    return 0;
}