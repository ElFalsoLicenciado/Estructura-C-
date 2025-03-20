#include <iostream>
#include <math.h>

using namespace std;

int binToDec(int n, int power = 0) {
	
	if (n==0) return n;

	return n%10*pow(2,power) + binToDec(n/10,++power);
}

int main() 
{
	int n;
	cin >> n;
	cout << n << " en decimal es: " << binToDec(n) << endl;
    	
	return 0;
}
