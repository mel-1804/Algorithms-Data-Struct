#include <iostream>
#include <vector>
using namespace std;

// ORDENACIÓN POR MEZCLA.
// Este algoritmo divide el vector muchas veces hasta quedar con elementos aislados que luego une de forma ordenada cada vez.

// ACA DEFINIMOS COMO SERÁ LA MEZCLA MERGE
void merge(vector<int> &v, int left, int mid, int right)
{
    int n = right - left + 1; // Este es el tamaño del vector
    vector<int> aux(n);
    int i = left;    // secuencia para el vector de la izquierda
    int j = mid + 1; // secuencia para el vector de la derecha
    int k = 0;       // parámetro para mi vector auxiliar
    while (i <= mid and j <= right)
    {
        if (v[i] <= v[j])
        {
            aux[k] = v[i];
            ++i;
        }
        else
        {
            aux[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid) // Relleno aux con v[i] si es que me sobraron elementos en Vector izqda
    {
        aux[k] = v[i];
        ++k;
        ++i;
    }
    while (j <= right) // Rellno aux con v[j] si es que me sobraron elementos en Vector derecha
    {
        aux[k] = v[j];
        ++k;
        ++j;
    }

    for (k = 0; k < n; k++)
    {
        v[left + k] = aux[k]; // Copio el vector auxiliar al vector original
    }
}

void merge_sort(vector<int> &v, int left, int right)
{ // Este procedimiento sólo ordena el vector
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);      // Ordeno la primera mitad
        merge_sort(v, mid + 1, right); // Ordeno la segunda mitad
        merge(v, left, mid, right);    // Fusiono el vector
    }
}

int main()
{
    int n;
    cin >> n;         // LEEMOS EL NÚMERO DE ELEMENTOS DEL VECTOR.
    vector<int> v(n); // Creamos un vector de tamaño n.
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; // RELLENAMOS LOS ELEMENTOS DEL VECTOR.
    }

    // Imprimir sin ordenar
    for (int j = 0; j < n; j++)
    {
        if (j == n - 1)
            cout << v[j] << endl;
        else
            cout << v[j] << " ";
    }

    // Ordenar
    merge_sort(v, 0, n - 1);

    // Imprimir luego de haber ordenado
    for (int k = 0; k < n; k++)
    {
        if (k == n - 1)
            cout << v[k] << endl;
        else
            cout << v[k] << " ";
    }
}
