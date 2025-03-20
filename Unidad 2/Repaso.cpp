#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int producto(int n, int m, int i);//P1a
void combinaciones(string charr, int i, int j);//P2
void print(string arr, int i, int j);//P2
int suma_pares(int n);//P3
int suma_vector(int vec[], int l,int b);//P4
int suma_digitos(int n, int d);//P5

int producto(int n, int m, int i = 0)
{
	if(i==m) return 0;
	
	return n+producto(n,m,++i);
}

void combinaciones(string arr, int i, int j)
{
	if(i==j) 
	{	cout << arr[0] << arr[1];	
		return;
	}
	print(arr,1,j);
	arr.erase(0,1);
	cout << "" << endl;
	return combinaciones(arr,++i,--j);	
}

void print(string arr, int i, int j)
{
	if(i==j) return;
	cout << ""  << arr[0] << "" << arr[i] << " ";
	return print(arr,++i,j);
}

int suma_pares(int n)
{
	
	int v = 0;

	if(n==1) return 2;

	return (2*n)+ suma_pares(--n);
	
}



int suma_vector(int vector[], int l, int i ,int b)
{		    
	int v = 0;
	if (vector[i]>b) v = vector[i];
	
	if(i==l) return v;

	return v + suma_vector(vector,l,++i,b);
}


int mayor(int vector[], int may, int i) {
	if (may<vector[i]) may = vector[i];
	cout << vector[i] << " " << may << endl;
	if (i==4) return may;

	return mayor(vector, may, ++i);

}

int suma_digitos(int n, int d)
{

	if(d-1==0) return n;

	int p = pow(10,d-1);	

	return n/p + suma_digitos(n%p,--d);
}

int main()
{
	/*
	cout << "Resultado: " << producto(3,6) << endl;;

	string arr = "ABCDEF";
	combinaciones(arr,0,arr.length());

	cout << "\nSuma de pares de 6: " << suma_pares(6);

	int vec[] = {1,3,4,7,9}; int b = 5;
	cout << "\nLa suma de los valores mayores a : " << b << " son: " << suma_vector(vec,4,0,b);

	int n = 1987; string l = to_string(n);
	cout << "\nLa suma de los digitos de "<< n <<" son: " << suma_digitos(n,l.length());
	return 0;
	*/
	int vec [] = {5,7,2,8};
	cout << mayor(vec,0,0);
	return 0;
}
