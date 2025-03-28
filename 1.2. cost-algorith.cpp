#include <iostream>
using namespace std;

// EJERCICIO: Diga qué hace el siguiente algoritmo y cuál es su coste en funcipn de n

int mistery(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= 1;
    return f;
}

// SOLUCIÓN SIN MIRAR: se trata de una función llamada mistery, la cual toma como parámetro un entero n.
// Inicializa un auxiliar F en 1, para luego multiplicarlo de acuerdo a un bucle.
// El bucle incia en 2 y termina en n aumentando cada 1 unidad, es decir, se ejecuta n-1 veces.
// Por cada iteración el auxiliar se ve amplificado por i, es decir por el numero de iteraciones realizadas.
// 1ra iteración: 1*2
// 2da iteración: 1*2*3
// 3ra iteración: 1*2*3*4
// n iteración: 1*2*3*4...*n
// Este algoritmo es un factorial, el cual se representa como n!

// El coste de este algoritmo es LINEAL ϴ(n) porque se hace exactamente un total de n iteraciones.
// (En realidad son n-2 iteraciones, pero ese constante que se resta no afecta la tasa de crecimiento lineal)
