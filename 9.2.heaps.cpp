#include <iostream>
#include <queue>
using namespace std;

// EJERCICO COLAS DE PRIORIDAD: Escriba e implemente un programa para mantener una colección de números enteros, mientras realiza las siguientes operaciones:
// 'S' x: Almacena una copia del número dado x.
// 'A': Pregunta por el número mayor.
// 'R': Elimina el número mayor (uno de ellos si se repite).
// 'I' x: Aumenta el número mayor (uno de ellos, si se repite) en x unidades.
// 'D' x: Disminuye el número mayor (uno de ellos, si se repite) en x unidades.

int main()
{
    char op; // Operación a realizar
    priority_queue<int> Q;
    int x;
    while (cin >> op)
    {
        if (op == 'S')
        {
            cin >> x;
            Q.push(x); // Almacena el número x en la cola de prioridad
        }
        else if (op == 'A')
        {
            if (Q.empty())
                cout << "Error!";
            else
                cout << Q.top(); // Devuelve el número mayor de la cola de prioridad
            cout << endl;
        }
        else if (op == 'R')
        {
            if (Q.empty())
                cout << "Error!";
            else
                Q.pop(); // Elimina el número mayor de la cola de prioridad
            cout << endl;
        }
        else if (op == 'I')
        {
            cin >> x;
            if (Q.empty())
                cout << "Error!";
            else
            {
                x = Q.top() + x; // Aumenta el número mayor en x unidades
                Q.pop();         // Elimina el numero original
                Q.push(x);       // Inserta el numero aumentado
            }
            cout << endl;
        }
        else if (op == 'D')
        {
            cin >> x;
            if (Q.empty())
                cout << "Error!" << endl;
            else
            {
                x = Q.top() - x; // Disminuye el número mayor en x unidades
                Q.pop();         // Elimina el numero original
                Q.push(x);       // Inserta el numero disminuido
            }
            cout << endl;
        }
    }
}