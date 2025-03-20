#include <iostream>

using namespace std;

int multiplicacion(int num, int multi)
{
	if(multi==0) return 0;

	return num+multiplicacion(num,--multi);
}

int main()
{	
	/*int num,multi;
	cout << "Dame un numero:" << " ";
	cin >> num;
	cout << "Dame su multiplicador:" << " ";
	cin >> multi;
	*/
	cout << "Dio: " << multiplicacion(5,2);
	return 0;
}
