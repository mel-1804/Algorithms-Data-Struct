#include <iostream>
#include <vector>
using namespace std;

// EJERCICIO BUSQUEDA DEL TESORO III: Escribe un programa que, dado un mapa con tesoros y obstaculos, calcule el número de tesoros que se pueden alcanzar desde una posicion inicial determinada.
// Los movimientos permitidos son horizontales y verticales, pero no diagonales. Si es necesario se permite pasar los tesoros.
// ENTRADA: comienza con el númro de filas n > 0 y columnas m > 0 del mapa. Siga n filas con m caracteres cada una.
// Un punto indica una posición vacía, una "x" indica un obstáculo y una "t" indica un tesoro.
// Finalmente dos números r y c indican la fila y la columna inciales (ambas comenzando en 1) donde debemos comenzar a bucar tesoros.
// Puede suponer que r esta entre 1 y n, que c esta entre 1 y m, y que la posición inicial siempre esta vacía.
// SALIDA: Imprime el número de tesoros accesibles desde la posición inicial.

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

int tesoro_dfs(vector<vector<char>> &T, int i, int j)
{
    int counter = 0; // Contador de tesoros alcanzables
    // Caso base
    if (T[i][j] == 't')
    {
        counter++; // si hay tesoro aumento el contador
    }

    T[i][j] = 'x'; // Marco esta casilla como "visitada" poniéndola como obstáculo

    // Ahora el caso recursivo.
    // Moverse en el mapa
    for (auto &d : direcciones)
    {
        int adj_i = i + d.first;
        int adj_j = j + d.second;

        // (adj_i, adj_j) nueva posicion casilla
        if (limitado(T, adj_i, adj_j) && T[adj_i][adj_j] != 'x')
            counter += tesoro_dfs(T, adj_i, adj_j); // Si el tesoro está en la nueva posición (adj_i, adj_j), aumento el contador
    }
    return counter; // Retorno el contador de tesoros alcanzables
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

    int respuesta = tesoro_dfs(T, r - 1, c - 1); // Llamar a la función dfs para buscar el tesoro. Igualar matrices que parten en 0 al requerimiento.
    cout << respuesta;                           // Imprimir la respuesta
    cout << endl;
}
