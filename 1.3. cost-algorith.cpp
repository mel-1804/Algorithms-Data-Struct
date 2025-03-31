#include <iostream>
#include <vector>
using namespace std;

// DISEÑAR UN ALGORITMO LALMADO TOP QUE ENCUENTRE LA MODA DE UN VECTOR UNIMODAL.
// EL COSTE DEL ALGORITMO DEBE SER COMO MÁXIMO logn, ES DECIR, O(logn).

int top(const vector<int> &v, int l, int r)
{
    // caso base cuando size <= 2
    if (l + 1 >= r)
        return max(v[l], v[r]);
    // caso recursivo
    else
    {
        int m = (l + r) / 2; // elemento del medio
        // la moda esta por la derecha
        if (v[m] < v[m + 1])
            top(v, m + 1, r);

        // la moda esta por la isquierda
        else if (v[m - 1] > v[m])
            top(v, m - 1, r);
        else
            return v[m]; // v[m] es el top ya que v[m] > v[m + 1] y v[m] > v[m - 1]
    }
}

// COSTE DEL ALGORITMO: CUANTAS LLAMADAS RECURSIVAS SE REALIZAN?
// Dadas las condiciones de las líneas 18 a 22, se realiza una llamada recursiva  alas funcion top sea en un caso o en el otro (de forma excluyente).
// El vector se aborda por la derecha o por la izquierda, desde el medio, por lo tanto iteramos sobre un vector de tamaño n/2.

// MODELO A USAR:   T(n) = T(n/2) + g(n)
// Considerando que el "trabajo extra" de este algoritmo son: el caso base (coste constante de 1) y el return de la línea 25 (coste constante de 1), se cumple que:
// T(n) = T(n/2) + ϴ(1)
//
// 1) Definir parámetros:
// a = 1
// b = 2
// k = 0
// α = logb a = log2 1 = 0
//
// 2) Evaluamos α versus k:
// α = k
//
// 3) Conclusión: T(n) = ϴ(nk - logn) = ϴ(logn)
