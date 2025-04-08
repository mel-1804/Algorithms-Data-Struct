#include <iostream>
#include <vector>
using namespace std;

// ORDENACIÓN POR BURBUJA.
// Toma los elementos de a pares y ordena solo pares. Repite la operación hasta que todo el vector este ordenado.

void bubble_sort(vector<int> &v); // Declaración de la función bubble_sort que se desarrolla mas abajo.
void imprime(const vector<int> &v);

int main()
{
    vector<int> cualquiera = {2, 4, 6, 1, 3};
    imprime(cualquiera);     // Imprime el vector original.
    bubble_sort(cualquiera); // Llama a la función de ordenación por burbuja y ordena el vector (aunque no lo muestre en pantalla)
    imprime(cualquiera);     // Imprime el vector pero ordenado, ahora si lo muestra.
}

void bubble_sort(vector<int> &v)
{
    bool sorted = false;
    int last = v.size() - 1;

    while (not sorted)
    { // Mientras no este ordenado el vector
        sorted = true;
        for (int i = 0; i < last; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                sorted = false; // si tuviste que usar este procedimiento entonces aun no esta ordenado.
            }
        }
        --last;
    }
}

void imprime(const vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}
