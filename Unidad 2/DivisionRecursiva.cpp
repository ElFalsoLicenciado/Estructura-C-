#include <iostream>

using namespace std;

int division(int num, int div)
{
	if(num<div) return 0;

	return 1+division(num-div, div);
}

int main()
{
	int num,div;
	cout << "Dame un numero:" << " ";
	cin >> num;
	cout << "Dame su divisor:" << " ";
	cin >> div;

	cout << "Dio: " << division(num,div);
	return 0;
}
