#include <iostream>
#include <cstring> //Manejo de arreglos char

using namespace std;

void ordenar_arreglo(char arr[], int n,int index);

void ordenar_arreglo(char arr[], int n,int index)
{
      if (index >= n-1) return;


}

int main()
{
      const char palabra1[] = "Hola";
      const char palabra2[] = "lofh";

      if (son_anagramas(palabra1, palabra2))
        cout << "Las palabras son anagramas" << endl;
      else cout << "Las palabras no son anagramas" << endl;

      return 0;
}