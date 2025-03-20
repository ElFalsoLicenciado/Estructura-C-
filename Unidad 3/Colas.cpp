#include <iostream>
using namespace std;

const int MAX=5;

class Cola
{
	private:
		int arr[MAX];
		int front;
		int end;
	
	public:
		Cola()
		{
			front = -1; end = -1;
		}
	
	//empty
	bool empty()
	{
		if(front == -1 && end == -1) return true;
		return false;
	}
	//full
	bool full()
	{
		return (end == MAX-1);
	}

	//enqueue
	void enqueue(int valor)
	{
		if(full()) cout << "\nLa cola esta llena.";
		else 
		{	
			if(front==-1) front = 0;

			++end;
			arr[end] = valor;
			cout << "\nValor insertado: " << valor;
			show();
		}
	}
	
	//dequeue
	void dequeue()
	{
		if(empty()) cout << "\nLa cola esta vacia.";
		else
		{
			cout << "\nSe ha eliminado: " << arr[0];
			for(int i = front; i < end; ++i)
				arr[i] = arr[i+1]; //El valor que esta en 0 sera remplazado por su siguiente.
			--end;
			
			if(end==-1) front = -1;
			show();
		}
	}
	
	//show
	void show()
	{
		if(!empty())
		{
			cout << "\nElementos de tu cola: ";
			for(int i = front; i <= end; ++i)
			{
				cout << arr[i];
				if(!(i == end)) cout << " , ";
			}
		}
	}
	//top
	void top()
	{
		cout << "\nValor al final de la cola: " << arr[end-1];
	}
};

int main()
{
	Cola simple;

	simple.enqueue(1);
	simple.enqueue(2);
	simple.enqueue(3);
	simple.enqueue(4);
	simple.enqueue(5);
	simple.enqueue(6);
	simple.dequeue();
	simple.dequeue();
	simple.dequeue();
	simple.dequeue();
	simple.dequeue();
	simple.dequeue();
}
