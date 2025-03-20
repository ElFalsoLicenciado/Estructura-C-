#include <iostream>
using namespace std;


void cambio(int *a, int *b)
{
	int temp = *a; //La variable auxiliar almacena el valor de que menciona la direccion de memoria a.
	*a = *b; //La direccion de a ahora almacena lo que guarda la direccion de b.
	*b = temp; // mientras que b recibe el valor que guardado en temp que es el valor guardado de la direccion vieja de a.
}


int main()
{
	int x=10, y=9;

	cout << "Antes de cambiar x: " << x << " y: " << y;

	cambio (&x,&y);

	cout << "\nDespues de cambiar x: " << x << " y: " << y;
	return 0;
}
