#include <iostream>

using namespace std;

int maxim(int arr[], int size)
{	
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if(arr[i] > max) max = arr[i];
	return max;
}

void countingSort(int arr[], int size, int exp)
{
	int count[10] = {0};
	int nuevo[size];

	for(int i=0; i<size; i++) 
		count[(arr[i]/exp)%10]++;

	for(int i=1; i <10; i++)
		count[i] += count[i-1];
	
	for(int i=size-1; i >=  0; i--)
	{
		int digito = (arr[i]/exp)%10;
		nuevo[count[digito]-1] = arr[i];
		count[digito]--;
	}

	for(int i=0; i<size; i++)
		arr[i] = nuevo[i];

	return;
}


void radixSort(int arr[], int size)
{
	int m = maxim(arr,size);

	for(int exp = 1; (m/exp) > 0; exp *= 10)
		countingSort(arr,size,exp);
}


int main()
{
	int arr[] = {134,43,21,432,531};
	int size = sizeof(arr)/sizeof(arr[0]);

	radixSort(arr,size);
	
	for(int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << "Yamete kuasai";


	return 0;
}
