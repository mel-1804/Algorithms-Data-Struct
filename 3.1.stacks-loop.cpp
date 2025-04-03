#include <stack>
#include <iostream>
using namespace std;

int main()
{

    stack<int> S;

    // 1.-VAMOS A ITERAR SOBRE LA PILA DESDE EL TOP HACIA ABAJO

    // for (int i = 1; i <= 10; i++)
    // {
    //     S.push(i);
    // }
    // // AL TERMINAR EL BUCLE, SE INSERTARÁ LOS NUMEROS DEL 1 AL 10 Y EL 10 SE ENCONTRARÍA EN EL TOP DE LA PILA
    // // cout << S.size() << endl;

    // while (not S.empty())
    // {
    //     cout << S.top() << " "; // IMPRIMO EL ELEMENTO E
    //     S.pop();                // ELIMINO EL ELEMENTO E PARA PODER SALIR DEL BUCLE Y QUE NO SEA INFINITO.
    // }
    // cout << endl;

    // 2.-AHORA VAMOS A ITERAR SOBRE LA PILA EN REVERSA

    for (int i = 10; i >= 1; i--)
    {
        S.push(i);
    }

    while (not S.empty())
    {
        cout << S.top() << " "; // IMPRIMO EL ELEMENTO E
        S.pop();                // ELIMINO EL ELEMENTO E PARA PODER SALIR DEL BUCLE Y QUE NO SEA INFINITO.
    }
    cout << endl;
}
