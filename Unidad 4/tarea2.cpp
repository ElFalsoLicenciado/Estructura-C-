#include <iostream>
using namespace std;

const int LL = 60;
const string encab(LL,'=');
const string encab2(LL,'-');
const string encab3(LL, '+');
const string encab4(LL,'*');
const string warn(LL,'!');
const string ques(LL,'?');

void centrar(string s);


struct Arista;

struct Vertice {
    string nombre;
    Vertice* sig;
    Arista* ari;

    Vertice(string n) {
        nombre = n;
        sig = nullptr;
        ari = nullptr;
    }
};

struct Arista {
    Arista* sig;
    Vertice* dest;

    Arista(Vertice* d) {
        dest = d;
        sig = nullptr;
    }
};

class Grafo {
private:
    Vertice* principio;

    Vertice* obtenerVertice(string n) {
        Vertice* temp = principio;
        while (temp != nullptr) {
            if (temp->nombre == n) {
                return temp;
            }
            temp = temp->sig;
        }
        return nullptr;
    }

public:
    Grafo() {
        principio = nullptr;
    }

    ~Grafo() {
        while (principio != nullptr) {
            Vertice* vTemp = principio;
            principio = principio->sig;

            // Borrar aristas
            while (vTemp->ari != nullptr) {
                Arista* aTemp = vTemp->ari;
                vTemp->ari = aTemp->sig;
                delete aTemp;
            }

            delete vTemp;
        }
        cout << encab2 << endl;
        centrar("Se libero memoria");
        cout << encab2 << endl;
    }

    void insertarVertice(string n) {
        if (obtenerVertice(n) != nullptr) {
            cout << warn << endl;
            centrar("Ya existe ese vertice");
            cout << warn + "\n" << endl;
            return;
        }

        Vertice* nuevo = new Vertice(n);

        if (principio == nullptr) {
            principio = nuevo;
        } else {
            Vertice* temp = principio;
            while (temp->sig != nullptr) {
                temp = temp->sig;
            }
            temp->sig = nuevo;
        }

        cout << encab3 << endl;
        centrar("Se inserto un vertice: "+ n);
        cout << encab3 + "\n"  << endl;
    }

    void insertarArista(string origen, string destino) {
        Vertice* vorigen = obtenerVertice(origen);
        Vertice* vdestino = obtenerVertice(destino);

        if (vorigen == nullptr || vdestino == nullptr) {
            cout << warn << endl;
            centrar("Uno o ambos vertices no existen");
            cout << warn + "\n" << endl;
            return;
        }

        if (vorigen == vdestino ) {
            cout << warn << endl;
            cout << "No se puede insertar una arista a si mismo." << endl;
            cout << warn + "\n" << endl;
            return;
        }

        Arista* nuevaOrigen = new Arista(vdestino);
        nuevaOrigen->sig = vorigen->ari;
        vorigen->ari = nuevaOrigen;

        Arista* nuevaDestino = new Arista(vorigen);
        nuevaDestino->sig = vdestino->ari;
        vdestino->ari = nuevaDestino;

        cout << encab3 << endl;
        centrar("Se inserto una arista entre: " + origen + " y " + destino);
        cout << encab3 + "\n" << endl;
    }

    void eliminarVertice(string n) {
        Vertice* vDel = obtenerVertice(n);
        if (vDel == nullptr) {
            cout << warn << endl;
            centrar("No se encontro el vertice");
            cout << warn + "\n" << endl;
            return;
        }

        while (vDel->ari != nullptr) {
            Arista* aDel = vDel->ari;
            vDel->ari = aDel->sig;
            delete aDel;
        }

        Vertice* aux = principio;
        while (aux != nullptr) {
            if (aux != vDel) {
                Arista* curr = aux->ari;
                Arista* ant = nullptr;


                while (curr != nullptr) {
                    if (curr->dest == vDel) {
                        if (ant == nullptr) aux->ari = curr->sig;
                        else ant->sig = curr->sig;

                        delete curr;
                        break;
                    }
                    ant = curr;
                    curr = curr->sig;
                }
            }
            aux = aux->sig;
        }

        if (vDel == principio) principio = vDel->sig;
        else {
            Vertice* anterior = principio;
            while (anterior->sig != nullptr && anterior->sig != vDel) anterior = anterior->sig;

            if (anterior->sig == vDel) anterior->sig = vDel->sig;
        }

        delete vDel;

        cout << encab3 << endl;
        centrar("Se elimino el vertice: " + n);
        cout << encab3 + "\n" << endl;
    }


    void mostrarListaAdyacencia() {
    Vertice* tempV = principio;
        if(tempV == nullptr) return;

        cout << encab4 << endl;
        centrar("Lista de adyacencia.");
    while (tempV != nullptr) {
        string list;
        list.append(tempV->nombre);
        Arista* tempA = tempV->ari;
        while (tempA != nullptr) {
            list.append(" -> " +tempA->dest->nombre);
            tempA = tempA->sig;
        }
        centrar(list);
        tempV = tempV->sig;
    }
        cout << encab4 + "\n" << endl;

}


    void mostrarVertices() {
        Vertice* aux = principio;
        string list;
        while (aux != nullptr) {
            list.append(aux->nombre);
            if (aux->sig != nullptr) list.append(" , ");
            aux = aux->sig;
        }
        if (!list.empty()) {
            cout << encab4 << endl;
            centrar("Lista de vertices");
            centrar(list);
            cout << encab4 + "\n" <<endl;
        }
    }

    void mostrarVertices(string n) {
        Vertice* aux = principio;
        string list;
        while (aux != nullptr) {
            if (aux->nombre != n) {
                list.append(aux->nombre);
                if (aux->sig != nullptr && aux -> sig ->nombre != n) list.append(" , ");
            }
            aux = aux->sig;
        }
        if (!list.empty()) {
            cout << encab4 << endl;
            centrar("Lista de vertices");
            centrar(list);
            cout << encab4 + "\n" <<endl;
        }
    }

};

void centrar(string s )
{
    int espacios = ( LL - s.size() ) / 2;
    if ( espacios > 0 ) cout << string( espacios, ' ' );
    cout << s << '\n';
}

int main() {
    Grafo g;

    int op; bool f = false;

    do {
        cout << encab4 << endl;
        centrar("Tarea de grafos");
        cout << encab4 + "\n" << endl;

        cout << ques << endl;
        centrar("Que quieres hacer?");
        centrar("1. Agregar vertice"); centrar("2. Agregar arista"); centrar("3. Eliminar vertice");
        centrar("4. Mostrar lista de adyacencia"); centrar("0. Salir");
        centrar("-->");
        cin >> op;

        cout << ques << "\n" << endl;

        switch (op) {
            case 1: {
                string in;
                cout << ques << endl;
                centrar("Dame el nombre del vertice");
                cin >> in;
                cout << ques << endl;

                g.insertarVertice(in);
                break;
            }
            case 2: {
                string s, e;
                cout << ques << endl;
                //funcion para mostrar todos los vertices ir aqui.
                centrar("De que vertice sale la arista.");
                g.mostrarVertices();
                cin >> s;

                cout << "\n" << endl;
                centrar("A que vertice llega la arista.");
                g.mostrarVertices(s);
                cin >> e;
                cout << ques << endl;

                g.insertarArista(s,e);
                break;
            }
            case 3: {
                string d;
                cout << ques << endl;
                centrar("Que vertice quieres borrar?");
                cin >> d;
                cout << ques << endl;

                g.eliminarVertice(d);
                break;
            }
            case 4: {g.mostrarListaAdyacencia(); break;}

            case 0: f = true;
            default: {break;}
        }

    }
    while (!f);
    /*
    g.insertarVertice("A");
    g.insertarVertice("B");
    g.insertarVertice("C");
    g.insertarArista("A", "B");
    g.mostrarListaAdyacencia();
    g.mostrarVertices();
    return 0;
    */
}

