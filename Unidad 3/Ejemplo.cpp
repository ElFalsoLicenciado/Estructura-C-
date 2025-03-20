#include <iostream>

using namespace std;

int main()
{
	int valor = 10;
	int *p, *q;
	p = &valor;
	q = p;
	cout << "Valor: " << valor << "\nEspacio en memoria: " << q << " Valor guardado en ese espacio: " << *q;
	/* p = valor; //Esto no es posible ya que solo acepta la direccion de memoria.
	cout << "Valor " << valor <<"\nLugar asignado: " << p;
	*/
	
	*q = 20; //Variable = 20; // Se va directamente al espacio de memoria y cambia el valor guardado
	cout << "\nVariable reasignada: " << valor;
	


	return 0;
}
