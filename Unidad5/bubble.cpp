#include <iostream>

using namespace std;


int main()
{
	int arr[] = {35,58,77,53,44,17,14,19};

	int n = sizeof(arr) / sizeof(arr[0]);

	for(int i=0; i < n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for(int i=0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
