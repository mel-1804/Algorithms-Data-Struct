#include <stack>
#include <iostream>
using namespace std;

// EJERCICIO: UTILICE UNA PILA PARA DETRMINAR PARA UN ENTERO n Y UNA SECUENCIA DE ENTEROS DADO DE LONGITUD n, SI LA SECUENCIA ES UN PALÍDROMO O NO.
// DEBE INDICARSE SI LA SECUENCIA SE LEE IGUAL DE EZQDA A DERECHA QUE AL REVES.
// ENTRADA: CONSISTE EN UN ENTERO n Y UNA SECUCNIA DE ENTEROS DE LONGITUD n.
// SALIDA: DEBE ENTREGAR UN "SI" O UN "NO".
// OBSERVACION: PARA RESOLVER ESTE EJERCICIO, BASTA CON UTILIZAR UN MONTÓN DE ENTEROS PARA GUARDAR LA PRIMERA MITAD DE LA SECUENCIA Y TRATAR CADA ENTERO RESTANDTE SOLO UNA VEZ.

int main()
{
    int n;
    cout << "Ingrese el tamaño de la secuencia y luego la secuencia" << endl;
    cin >> n;
    stack<int> pila;

    int value;
    int count = 0; // ESTE CONTADOR ES PARA SALIR DEL BUCLE CUANDO LA CUENTA ES IGUAL A n. O SEA QUE TERMINÓ DE ITERAR Y ENTREGA LA RESPUESTA AUTOMATICAMENTE.

    for (int i = 0; i < n / 2; i++)
    {
        cin >> value;
        pila.push(value);
        count++;
    }

    if (n % 2 != 0)
        cin >> value;
    count++;

    bool palind = true;

    while (count < n and cin >> value and palind)
    {
        if (value != pila.top())
            palind = false; // CUANDO ESTO SEA FALSO, SALGO DEL BUCLE. AHI SE TERMINA
        pila.pop();
        count++;
    }

    cout << (palind ? "Si" : "No") << endl;
}