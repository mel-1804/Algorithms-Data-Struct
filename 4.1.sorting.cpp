#include <iostream>
#include <vector>
using namespace std;

// ORDENACIÓN POR INSERCIÓN.
// Es un algoritmo INDUCTIVO  que siempre trata el caso anterior. Trabaja el orden ascendente ordenando de menor a mayor valor.

void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i]; // Acá almaceno mi valor actual
        int j = i;
        while (j > 0 and v[j - 1] > x)
        {                    // Acá comparo el valor actual con el anterior
            v[j] = v[j - 1]; // Acá hago el desplazamiento de los valores
            j--;
        }
        v[j] = x;
    }
}

int main()
{
    int n;
    cin >> n; // LEEMOS EL NÚMERO DE ELEMENTOS DEL VECTOR.
    vector<int> francisco(n);
    for (int i = 0; i < n; i++)
    {
        cin >> francisco[i]; // RELLENAMOS LOS ELEMENTOS DEL VECTOR.
    }

    cout << "El vector original es: " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << francisco[j] << " "; // IMPRIMIMOS EL VECTOR ORIGINAL.
    }
    cout << endl;

    cout << "Este es el vector ordenado: " << endl;
    insertion_sort(francisco); // LLAMAMOS A LA FUNCIÓN DE ORDENACIÓN POR INSERCIÓN.
    for (int k = 0; k < n; k++)
    {
        cout << francisco[k] << " "; // IMPRIMIMOS EL VECTOR ORDENADO.
    }
}
