#include <stack>
#include <iostream>
using namespace std;

// EJERCICIO: DADA UNA EXPRESIÓN CO PARENTESIS DE DOS TIPOS DIFERENTES, ESCRIBA UN PROGRAMA QUE EVALÚE SU CORRECCION UTILIZANDO PILAS.
// ENTRADA: UNA SECUENCIA DE PARÉNTESIS (, ), [, ] TERMINADA EN PUNTO.
// SALIDA: ESCRIBA "CORRECTO" O "INCORRECTO" SEGUN SEA EL CASO.

int main()
{
    char x;
    stack<char> p;

    cin >> x;
    bool correcto = true;

    while (correcto and x != '.')
    {
        if (x == '[' or x == '(')
        {
            p.push(x);
        }
        else if (x == ']')
        {
            if (p.empty() or p.top() != '[')
                correcto = false;
            else
                p.pop();
        }
        else if (x == ')')
        {
            if (p.empty() or p.top() != '(')
                correcto = false;
            else
                p.pop();
        }

        cin >> x;
    }

    if (correcto and p.empty())
        cout << "Correcto";
    else
        cout << "Incorrecto";
    cout << endl;
}