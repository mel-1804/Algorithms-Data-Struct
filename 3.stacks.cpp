#include <stack>
#include <iostream>
using namespace std;

int main()
{

    stack<int> S;

    // VAMOS A INSERTAR ELEMENTOS A LA PILA USANDO EL MÉTODO .push()
    S.push(2);
    S.push(8);
    S.push(10);

    // EN ESTE PUNTO LA PILA TIENE 3 ELEMENTOS

    S.pop(); // Aca estoy eliminando el elemento TOP
    S.pop(); // Aca estoy eliminando el elemento TOP
    S.pop(); // Aca estoy eliminando el elemento TOP

    // EN ESTE PUNTO LA PILA NO TIENE ELEMENTOS PORQUE LOS ELIMINÉ TODOS
    // cout << S.top() << endl;

    // PARA CONTAR LOS ELEMENTOS DE LA PILA CON EL MÉTODO .size()
    cout << "Hay un total de " << S.size() << endl;
}