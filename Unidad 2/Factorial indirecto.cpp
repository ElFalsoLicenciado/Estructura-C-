#include <iostream>

using namespace std;

int factorial(int n);
int factorial2(int n);
int main();

int factorial(int n) // Funcion directa
{
	if(n==0) return 1; //Checa que el numero de 0
	
	return factorial2(n); //Llama a la otra funcion para esperar el resultado
}

int factorial2(int n)
{
	return n*factorial(n-1); //La funcion llama a la funcion directa
}

int main()
{
	int n; cout << "Dame un numero";
	cin >> n;

	cout << "El factorial del numero es: " << factorial(n) << endl;

}
