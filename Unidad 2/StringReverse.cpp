#include <iostream>

using namespace std;

string reversa(string t)
{
	if(t.length()==0) return t;

	string c = t.substr(1); //Quita el primer caracter el cual sera el primero en quitar y el ultimo en la cadena solucion.
	string r = reversa(c); //Llamada recursiva para ir quitando y guardando los caracteres.
	string solucion = r+t[0]; //Se concatena el caracter.

	return solucion;


}
