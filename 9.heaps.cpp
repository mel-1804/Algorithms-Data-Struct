#include <iostream>
#include <queue>
using namespace std;

// COLAS DE PRIORIDAD: se implementan mediante monticulos (heaps).

int main()
{
    priority_queue<int> Q; // por defecto esta implementación es un MAX HEAP. El elemento top es el elemento mayor.
    Q.push(6);
    Q.push(8);
    Q.push(2);
    Q.push(9);

    cout << "El top de la cola MAX HEAP es " << Q.top() << endl; // devuelve el elemento mayor (8)

    priority_queue<int, vector<int>, greater<int>> Q2; // Esta implementación es un MIN HEAP. El elemento top es el elemento menor.
    Q2.push(6);
    Q2.push(8);
    Q2.push(2);
    Q2.push(9);

    cout << "El top de la cola MIN HEAP es " << Q2.top() << endl; // devuelve el elemento menor (2)
}
