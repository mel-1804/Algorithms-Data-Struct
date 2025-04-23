#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; // nro de vertices (filas en la matriz)
    int m; // nro de aristas (columnas en la matriz)

    cin >> n >> m; // leer el nro de vertices y aristas MATRIZ DE ADYACENCIA

    vector<vector<int>> G(n);

    // Leer el grafo por la consola. Hagoun bucle for para contar aristas m.
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // leer los vertices de la arista

        // Validar que x y y estén dentro del rango válido
        if (x < 0 || x >= n || y < 0 || y >= n)
        {
            cerr << "Error: Vertices fuera de rango. Deben estar entre 0 y " << n - 1 << "." << endl;
            return 1; // Salir del programa con un código de error
        }

        G[x].push_back(y); // Voy a la fila x e introduzco el valor y
        G[y].push_back(x); // Voy a la fila y e introduzco el valor x
    }

    // Imprimir el grafo
    for (int i = 0; i < n; i++)
    {
        cout << "Vertices Adyacentes a " << i << ": ";
        for (int j = 0; j < G[i].size(); j++)
            cout << G[i][j] << " ";
        cout << endl;
    }
}
