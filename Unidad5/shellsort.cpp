#include <iostream>

using namespace std;

void shellsort(int a[], int tam)
{
	int paso, i, j, temp;

	paso = tam/2;

	while(paso > 0)
	{
		for(i = paso; i < tam; i++)
		{
			temp = a[i];
			for(j = i;  j>= paso; j -= paso)
			{
				if(a[j-paso] > temp) a[j] = a[j-paso];
				else break;
			}
			a[j] = temp;
		}
		paso = paso/2;
	}
}

int main()
{
	int arr[] = {8,2,5,9,1,6,4,3};
	int tam = sizeof(arr) / sizeof(arr[0]);

	cout << "Arreglo desordenado" << endl;

	for(int i = 0 ; i < tam; i++) cout << arr[i] << " ";
	
	shellsort(arr, tam);

	cout << "\nArreglo ordenado" << endl;
	for(int i = 0; i < tam; i++) cout << arr[i] << " ";

	return 0;
}
