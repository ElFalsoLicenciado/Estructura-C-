#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo * sig;
};

Nodo *frente;
Nodo *final;

void inicializar(){
    frente = NULL;
    final = NULL;
}

bool vacia(){
    return (final==NULL);
}

void enqueue(int x){
    Nodo * aux = new Nodo();
    aux -> valor = x;
    if(vacia()){
        frente=aux;    
    }else{
        final -> sig =aux;
    }
    aux -> sig = frente;
    final = aux;
    cout << "Valor " << x << " se inserto en la cola" << endl;
}

void dequeue(){
    if(vacia()){
        cout << "La cola esta vacia" << endl;
    }else{
        Nodo * aux = frente;
        frente = frente -> sig;
        if(aux->sig==aux){
            final=NULL;
        }else{
        final -> sig = frente;
        }
        delete aux;
        cout << "Nodo eliminado" << endl;
    }
}

void mostrar(){
    if(vacia()){
        cout << "La cola esta vacia" << endl;
    }else{
        cout << "Valores en la cola" << endl;
        Nodo * aux = frente;
        do{
            cout << aux->valor << endl;
            aux = aux->sig;
        }while(aux!=frente);
    }
}

void destruir(){
    while(!vacia()){
        dequeue();
    }
}

int main()
{
	inicializar();

    enqueue(3);
    enqueue(5);
    enqueue(18);
    mostrar();
    dequeue();
    mostrar();
    dequeue();
    mostrar();
    dequeue();
    dequeue();
    mostrar();

	destruir();
	return 0;
}