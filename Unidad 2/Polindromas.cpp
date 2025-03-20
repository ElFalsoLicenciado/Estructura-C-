#include <iostream>

using namespace std;
/*
string palindroma(string cad, int con = 0)
{
	if(con == cad.length()) return cad;

	if (cad.at(con)== cad.at((cad.length() - 1)-con))
		cout << cad.at(con)  ;
		return palindroma(cad, con+1);
}
*/

bool palindroma(string t, int inicio, int fin)
{
	if (inicio >= fin) return  true;

	if (t[inicio] != t[fin]) return false;

	palindroma(t, ++inicio, --fin);
}

int main()
{
	string cadena;
	cout << "Dame una cadena:  " << endl;
	cin >> cadena;
	if (palindroma	(cadena,0,cadena.length()-1))
	cout << "Es palindroma";
	else cout << "No palindroma";
	return 0;
}
