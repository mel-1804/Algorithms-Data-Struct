#include <iostream>
#include <vector>
using namespace std;

// EJERCICIO TWO COLORS:Escribe un programa que dado un grafo no dirigido,
// diga si podemos pintar todos los vértices con solo dos colores, de tal manera que no haya dos vértices vecinos que tengan el mismo color.
// ENTRADA: consta de varios casoso, cada uno con el número de vértices n y número de aristas m, seguidos de m pares "xy" que indican una arista entre x e y.
// Suponga que 1 <=n <= 104, 0 <= m <= 5n, que los vértices estan numerados de 0 a n-1, x != y y que no hay mas de una arista entre cualquier par "xy".
// SALIDA: Para todos los casos, escriba "Yes" si el gráfico es de dos colores y "No" en caso contrario.

// PRIMER COLOR = 0
// SEGUNDO COLOR = 1

// G es nuestro grafo, colores es el vector de colores del grafo, u es un vertice cualquiera y viejou es una vertice antiguo adyacente a u.

bool es_doscoloreable(const vector<vector<int>> &G, vector<int> &colores, int u, int viejou)
{
    if (colores[u] == 0)
    {
        colores[u] = colores[viejou] % 2 + 1; // poner colores distintos a u y a viejou
        for (int i : G[u])
        { // iteramos sobre los vertices adyacentes a u
            if (not es_doscoloreable(G, colores, i, u))
            {
                return false;
            }
        }
        return true;
    }

    else
    {
        return colores[u] != colores[viejou]; // retorno cierto si son distintos, falso si son iguales
    }
}

// Este es el algoritmo DFC que recorre todoel grafo mediante una busqueda en profundidad

bool dfs(const vector<vector<int>> &G)
{
    int n = G.size();        // obtenemos el número de vertices
    vector<int> color(n, 0); // vector de colores para cada vertice
    for (int i = 0; i <= n; i++)
    {
        if (color[i] == 0 and not es_doscoloreable(G, color, i, i))
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> G(n); // Declaro un grafo con n vertices

        int x, y; // dos vertices cualquiera

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;     // Leer una pareja x,y que es una arista del grafo G
            G[x].push_back(y); // El vertice y es adyacente a x
            G[y].push_back(x); // El vertice x es adyacente a y
        }
        // El grafo esta relleno.-

        if (dfs(G))
            cout << "Yes" << endl; // Si el grafo es de dos colores, escribo "Yes"
        else
            cout << "No" << endl; // Si no es de dos colores, escribo "No"
        cout << endl;
    }
}
