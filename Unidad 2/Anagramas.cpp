#include <algorithm>
#include <iostream>

using namespace std;

bool verificador(string p1, string p2);
int buscador(char l, string p, int i =0);
string lowercase(string p);
int main();

bool verificador(string p1, string p2)
{
	if(p1.length()!=p2.length()) return false;
	if (p1.length()== 0) return true;
	int i = buscador(p1[0],p2);

	if(i==-1) return false;

	p1.replace(0,1,"");
	p2.replace(i,1,"");
	return verificador(p1,p2);
}

int buscador(char l, string p, int i)
{
	if(i>p.length()) return -1;
	if(p[i]==l) return i;
	return buscador(l,p,++i);
}

string lowercase(string p)
{
	string copy = p;
	transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
	return copy;
}

int main()
{
	int d;
	do {
		string p1, p2;
		cout << "Dame una palabra: "; cin >> p1; p1 = lowercase(p1);

		cout << "Dame otra palabra:"; cin >> p2; p2 = lowercase(p2);
		cout << " " << endl; cout << "Son anagramas? ";

		if(verificador(p1,p2)) cout << " Si lo son" << endl;
		else cout << "No lo son."<< endl;

		cout << "Continuar? 1. Si 0. No" << endl; cin >> d;
	}
	while (d == 1);
	return 0;
}


