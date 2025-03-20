#include <iostream>
using namespace std;

	//lista + 0 	apunta a	lista[0]
	//lista + 1	apunta a	lista[1]
	//lista + n	apunta a	lista[n]

	//*lista = lista[0]
int main()
{
	
	int array[5] = {1,2,3,4,5};
	
	cout << "Sin punteros: ";
	for(int i =0;i<5;++i) //Primero sumo y luego realiza la instruccion
	{
		cout << array[i] << " ";
	}
	
	int *pointer = array; //Es lo mismo que int *pointer = &array[0]
	cout << "\nCon punteros: ";

	for(int i =0; i < 5; ++i)
	{
		cout << *(pointer+i) << " "; //Va cambiando direcciones de memoria para obtener los valores.
	}


	//*(pointer+3) = 7; //Cambiando el valor de la posicion 4;
	//cout << "\nValor cambiado en 4: ";
	//for (int i = 0; i < 5; ++i)
	//	cout << array[i] << " ";
	
	cout << "\nReverso: ";
	for (int i = 4; i > -1; i--) 
	//Empieza en 4 por que la posicion 5 no es del arreglo 
	//pero de otra cosa que no forma parte del arreglo pero aun asi lo toma
		cout << *(pointer+i) << " ";
	
	return 0;
}
