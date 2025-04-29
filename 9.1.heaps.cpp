#include <iostream>
#include <queue>
using namespace std;

// COLAS DE PRIORIDAD: INTERCAMBIO DE ELEMENTOS ENTRE COLAS.

int main()
{
    priority_queue<int> Q; // por defecto esta implementación es un MAX HEAP. El elemento top es el elemento mayor.
    priority_queue<int> M;
    priority_queue<int> Z;

    Q.push(6);
    Q.push(8);
    Q.push(2);

    M.push(12);
    M.push(18);
    M.push(21);
    M.push(15);

    Z.push(-3);
    Z.push(-1);

    Q.swap(M); // Intercambiamos los elementos entre Q y M
    M.swap(Z); // Z tendra los elementos de Q

    cout << "Los elementos de la cola Q son: " << endl;
    while (not Q.empty())
    {
        cout << Q.top() << ' ';
        Q.pop();
    }

    cout << endl;

    cout << "Los elementos de la cola M son: " << endl;
    while (not M.empty())
    {
        cout << M.top() << ' ';
        M.pop();
    }

    cout << endl;

    cout << "Los elementos de la cola Z son: " << endl;
    while (not Z.empty())
    {
        cout << Z.top() << ' ';
        Z.pop();
    }
}
