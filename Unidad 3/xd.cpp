#include <iostream>
#include <stack>

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
}


void paso1(string cad)
{
    for(int i = 0; i<cad.length(); ++i)
    {
        if(cad[i] == '(' || cad[i] == ')') push(cad[i]);
    }
    show();
}

void paso2()
{
    int pa, pc; pa = pc = 0;


    do
    {
        if(vacia()) false;
    }
    while(true);

    if(vacia()) cout <<"\nTus parentesis estan balanceados";
}


int main()
{
    string cad = "(a+b)/(a*(xd))";
    //cout << "\nDame una cadena: "; cin >> cad;
    paso1(cad);

    return 0;
}