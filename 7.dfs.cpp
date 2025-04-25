#include <iostream>
#include <vector>
using namespace std;

// EJERCICIO BUSQUEDA DEL TESORO: Escribe un programa que, dado un mapa con tesoros y obstaculos, diga si es posible alcanzar algun tesoro desde una posicion inicial determinada.
// Los movimientos permitidos son horizontales y verticales, pero no diagonales.
// ENTRADA: comienza con el númro de filas n > 0 y columnas m > 0 del mapa. Siga n filas con m caracteres cada una.
// Un punto indica una posición vacía, una "x" indica un obstáculo y una "t" indica un tesoro.
// Finalmente dos números r y c indican la fila y la columna inciales (ambas comenzando en 1) donde debemos comenzar a bucar el tesoro.
// Puede suponer que r esta entre 1 y n, que c esta entre 1 y m, y que la posición inicial siempre esta vacía.
// SALIDA: Imprime "Yes" o "No" segun sea posible o no llegar a algun tesoro.

// . camino vacio
// x obstáculo
// t tesoro

// Direcciones posibles para moverse en el mapa
vector<pair<int, int>> direcciones = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // derecha, izquierda, abajo, arriba

// Retorna si estoy dentro del mapa, si no retorno falso
bool limitado(vector<vector<char>> &T, int i, int j)
{
    return i >= 0 and j >= 0 and i < int(T.size()) and j < int(T[0].size());
}

bool tesoro_dfs(vector<vector<char>> &T, int i, int j)
{
    // Hay 2 casos base del algoritmo recursivo.
    if (T[i][j] == 't')
        return true; // Si el tesoro está en la posición (i, j), retorno verdadero
    else if (T[i][j] == 'x')
        return false; // Si hay un obstáculo en la posición (i, j), retorno falso

    // Ahora el caso recursivo.
    T[i][j] = 'x'; // Visitado

    // Moverse en el mapa
    for (auto &d : direcciones)
    {
        int adj_i = i + d.first;
        int adj_j = j + d.second;

        // (adj_i, adj_j) nueva posicion casilla
        if (limitado(T, adj_i, adj_j) && T[adj_i][adj_j] != 'x' && tesoro_dfs(T, adj_i, adj_j))
            return true; // Si el tesoro está en la nueva posición (adj_i, adj_j), retorno verdadero
    }
    return false;
}

int main()
{
    int n;         // nro de filas
    int m;         // nro de columnas
    cin >> n >> m; // leer el nro de filas y columnas (n y m)

    vector<vector<char>> T(n, vector<char>(m)); // Declaración del mapa T

    // Inicializar la matriz
    for (int i = 0; i < n; i++) // Itero sobre filas con variable i
    {
        for (int j = 0; j < m; j++) // Itero sobre clumnas con variable j
            cin >> T[i][j];         // leer el mapa por la consola
    }

    int r; // Fila inicial donde me encuentro en el mapa
    int c; // Columna inicial donde me encuentro en el mapa

    cin >> r >> c; // leer la posición inicial (r, c) en el mapa

    bool respuesta = tesoro_dfs(T, r - 1, c - 1); // Llamar a la función dfs para buscar el tesoro. Igualar matrices que parten en 0 al requerimiento.
    if (respuesta)
        cout << "Yes";
    else
        cout << "No"; // Imprimir la respuesta
    cout << endl;
}
