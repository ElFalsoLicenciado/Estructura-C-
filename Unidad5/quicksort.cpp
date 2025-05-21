#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& a, int inicio, int fin){
  if(inicio >= fin) return;

  int i = inicio;
  int d = fin;
  int pivote = a[(inicio+fin)/2];

  while (i <= d){
    while(a[i] < pivote) ++i;
    while(a[d] > pivote) --d;

    if(i <= d){
      swap(a[i], a[d]);
      ++i;
      --d;
    }
  }

  quicksort(a, inicio, d);
  quicksort(a, i, fin);


}

int main(){
  vector<int> arr = {7, 9, 1, 6, 4, 5, 3, 8};
  cout << "Arreglo original" << endl;

  for(int num: arr){
    cout << num << " ";
  }
  cout << endl;

  quicksort(arr, 0, arr.size() - 1);

  cout << "Arreglo Ordenado" << endl;
  for(int num: arr){
    cout << num << " ";
  }

  cout << endl;

  return 0;

}