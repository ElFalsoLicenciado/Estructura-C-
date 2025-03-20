#include <iostream>

using namespace std;

void ulam(int n);
void ulamPar(int n);
void ulamImpar(int n);


void ulam(int n)
{
	if(n==1)
	{
		cout << n;
		return;
	}
	else
	{
		cout << n << " ";
		if(n%2==0) ulamPar(n);
		else ulamImpar(n);
	}
}

void ulamPar(int n)
{
	ulam(n/2);
}

void ulamImpar(int n)
{
	ulam(n*3+1);
}

int main()
{
	int n; cout << "Dame un numero:";
	cin >> n;
	
	cout << "La serie ULAM es: " << endl; ulam(n);

	return 0;
}
