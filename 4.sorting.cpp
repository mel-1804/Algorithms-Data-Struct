#include <iostream>
#include <vector>
using namespace std;

// ORDENACIÓN POR SELECCION.
// Vamos a ordenar un vector: la posición right nunca vambia, pero la posición left si, proque se inetercambia con el menor valor encontrado ene l vector.

// PASO 1: BUSCAR EL MÍNIMO VALOR, CREAMOA LA FUNCION pos_min() PARA ENCONTRARLO:
int pos_min(const vector<int> &v, int left, int right)
{
    int pos = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (v[i] < v[pos])
        {
            pos = i;
        }
    }
    return pos;
}

// PASO 2: INTERCAMBIAR LOS VALORES DE LAS POSICIONES left Y right. ESTA ES LA ORDENACIÓN POR SELECCIÓN.
void selection_sort(vector<int> &v)
{
    int last = v.size() - 1;
    for (int i = 0; i < last; i++)
    {
        int k = pos_min(v, i, last); // LA VARIABLE k ALMACENA LA POSICIÓN DEL MÍNIMO VALOR DE ESTE VECTOR.
        swap(v[k], v[i]);
    }
}

int main()
{
    int n;
    cin >> n; // LEEMOS EL NÚMERO DE ELEMENTOS DEL VECTOR.
    vector<int> california(n);
    for (int i = 0; i < n; i++)
    {
        cin >> california[i]; // RELLENAMOS LOS ELEMENTOS DEL VECTOR.
    }

    cout << "El vector original es: " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << california[j] << " "; // IMPRIMIMOS EL VECTOR ORIGINAL.
    }
    cout << endl;

        cout << "Este es el vector ordenado: " << endl;
    selection_sort(california); // LLAMAMOS A LA FUNCIÓN DE ORDENACIÓN POR SELECCIÓN.
    for (int j = 0; j < n; j++)
    {
        cout << california[j] << " "; // IMPRIMIMOS EL VECTOR ORDENADO.
    }
    cout << endl;
}