#include <iostream>

using namespace std;

int *p,y;

void func()
{
    int x = 40; //x es una variable local la cual al terminar las instrucciones se elimina
    p = &x; //p toma la direccion de memoria de x
    y = *p; // y obtiene la direccion.
    *p =23; // recibe un valor.
}


int main() {

    func();
    y = *p; //Como x ya no existe, el apuntador no referencia a nada.
    *p = 45;  //No tiene direccion a donde guardar y por ende no puede guardar nada.

    return 0;
}