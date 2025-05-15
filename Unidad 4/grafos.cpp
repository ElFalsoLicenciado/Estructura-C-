/* Conjunto no vacio de objetos oentes fisicos que tienen relacion entre ellos. Un grefo esta formado por vertices,
   muchasveces tambien llamados nodos y se conectan por medio de aristas.
   Vertices:

   Tipos de Grafos.
   Dirigidos: Las aristas tienen una direccion, es decir, van de un nodo a otro(se representa con flechas)
   No dirigidos: Las aristas no tienen direccion, es decir, la relacion es bidireccional

   Representacion de grafos.
   Matriz adyascente: E suna matriz bidimencional donde el valor en la posicon [i][j], indica si existe una arista
   entre los nodos i y j. Es eficiente para grafos densos
   Lista de adyacencia: Cada nodo tiene una lista de nodos a los que esta conectado. Es mas eficiente para grafos dispersos
   ya que solo almacena conexiones existentes
   Matriz de incidencia: Es una matriz que indica que aristas estsn conectados a que nodos
   */
// de esto, basate en el destructor para hacer la lista de adyasencia
#include <iostream>
using namespace std;


struct Arista; //se decalara para que sepa que existe una estructura arista

struct Vertice {
    string nombre;
    Vertice* sig;
    Arista* ari;

    Vertice(string n) {
        nombre = n;
        sig = NULL;
        ari = NULL;
    }
};

struct Arista {
    Arista* sig;
    Vertice* dest;

    Arista(Vertice* d) {
        dest = d;
        sig = NULL;
    }
};

class Grafo {
private:
    Vertice* principio;

    Vertice* obtenerVertice(string n) {
        Vertice* temp = principio;
        while (temp != NULL) {
            if (temp->nombre == n) {
                return temp;
            }
            temp = temp->sig;
        }
        return NULL;
    }

public:
    Grafo() {
        principio = NULL;
    }

    ~Grafo() {
        while (principio != NULL) {
            Vertice* vTemp = principio;
            principio = principio->sig;

            // Borrar aristas
            while (vTemp->ari != NULL) {
                Arista* aTemp = vTemp->ari;
                vTemp->ari = aTemp->sig;
                delete aTemp;
            }

            delete vTemp;
        }
        cout << "Se libero memoria" << endl;
    }

    void insertarVertice(string n) {
        if (obtenerVertice(n) != NULL) {
            cout << "Ya existe ese vertice" << endl;
            return;
        }

        Vertice* nuevo = new Vertice(n);

        if (principio == NULL) {
            principio = nuevo;
        } else {
            Vertice* temp = principio;
            while (temp->sig != NULL) {
                temp = temp->sig;
            }
            temp->sig = nuevo;
        }
        cout << "Se inserto un vertice: " << n << endl;
    }

    void insertarArista(string origen, string destino) {
        Vertice* vorigen = obtenerVertice(origen);
        Vertice* vdestino = obtenerVertice(destino);

        if (vorigen == NULL || vdestino == NULL) {
            cout << "Uno o ambos vertices no existen" << endl;
            return;
        }

        Arista* nuevaOrigen = new Arista(vdestino);
        nuevaOrigen->sig = vorigen->ari;
        vorigen->ari = nuevaOrigen;

        Arista* nuevaDestino = new Arista(vorigen);
        nuevaDestino->sig = vdestino->ari;
        vdestino->ari = nuevaDestino;

        cout << "Se inserto una arista entre: " <<   origen << " y " << destino << endl;
    }
    void mostrarListaAdyacencia() {
    Vertice* tempV = principio;
    while (tempV != NULL) {
        cout << tempV->nombre << " ";
        Arista* tempA = tempV->ari;
        while (tempA != NULL) {
            cout << tempA->dest->nombre << " ";
            tempA = tempA->sig;
        }
        cout << endl;
        tempV = tempV->sig;
    }
}


};

int main() {
    Grafo g;
    g.insertarVertice("A");
    g.insertarVertice("B");
    g.insertarVertice("C");
    g.insertarArista("A", "B");
    g.mostrarListaAdyacencia();

    return 0;
}

