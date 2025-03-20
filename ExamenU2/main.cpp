#include <iostream>

using namespace std;


//YO DIGO QUE REVISE EL COMUN1
//aunque se ve bien feo :(  y por que se ve muy forzado no creo que valga mucho... Pero como usted vea.
//¡APIADESE DE MI!

int comun1(int a, int b, int mcd, int i)
{
	if(i==b) return mcd;
	
	if((a%i==0)&&(b%i==0)) mcd = i;

	return comun1(a,b,mcd,++i);
}

int comun2(int a, int b)
{

	if((b%a)==0) return a;
	
	int temp = b%a;
	return comun2(temp,a);
}


int main() 
{

	int a , b ;

	cout << "Dame un numero: "; cin >> a;
	cout << "Dme otro numero: "; cin >> b;
    	cout << "\nComun divisor resiuduo: " << comun2(a,b) <<endl;
	
	int aux;
	if(b<a)  
	{
		aux = b;
		b = a;
		a = aux;
	}
	cout << "\nComun divisor divisores: " << comun1(a,b,1,1);
	return 0;
}
