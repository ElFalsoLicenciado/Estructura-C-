#include <iostream>

using namespace std;

    int mcd(int divisor, int dividendo)
  {
      if(dividendo == 0) return divisor;

      return mcd(dividendo , dividendo % divisor);
  }

 int mcd1(int div1[], int div2[]) {

    }

  void divisores(int num, int arr[], int div, int con = 0) {
        if (div == 0) return;
        if (num % div == 0) {
            arr[con] =  div;
            ++con;
        }
        return divisores(num, arr, --div,con);
    }


  int main()
  {
    int a =15, b =25;
    int div1[100] = {0}, div2[100] = {0}; //Se inicializan todos los valores en 0;

    divisores(a,div1,a);
    divisores(b,div2,a);

    cout << mcd(108,98);
        cout << "\n";

        for (int i = 0; i < 25; i++)
            cout << div1[i] << " ";
    return 0;
  }