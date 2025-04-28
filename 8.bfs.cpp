#include <iostream>
#include <vector>
#include <queue> // Estrucutura de datos esencial en BFS, FIFO (First In First Out)
using namespace std;

// SIEMPRE QUE QUIERA CALCULAR DISTANCIAS SE USAN ALGORITMOS BFS.
// EJERCICIO TESOROS EN UN MAPA II: Escribe un programa que, daod un mapa con tesoros y obstáculos, calcule la distancia desde una posición inicial hasta el tesoro accesible mascercano.
// Los moviminetos permitidos son horizontles y verticales, pero no diagonales.
// ENTRADA: comienza con el número de filas n > 0 y columnas m > 0 del mapa. Siga n filas con m caracteres cada una.
// Un punto indica una posición vacía, una "x" indica un obstáculo y una "t" indica un tesoro.
// Finalmente dos números r y c indican la fila y la columna inicial (ambas comenzando en 1) donde debemos comenzar a buscar tesoros.
// Puede suponer que r está entre 1 y n, que c está entre 1 y m, y que la posición inicial siempre está vacía.
// SALIDA: Imprime el número mínimo de pasos para llegar a un tesoro desde la posición inicial. Si no hay tesoros accesibles, dígalo.

// Direcciones permitidas en el mapa
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Arriba, Abajo, Izquierda, Derecha

// Retorna true si estoy dentro de los límites del mapa y false en caso contrario.
bool limitado(const vector<vector<char>> &M, int i, int j)
{
    return i >= 0 && j >= 0 && i < M.size() && j < M[0].size();
}

// Algoritmo BFS que retorna la distancia mínima desde la posición inicial(i, j) hasta el tesoro más cercano.
int bfs(vector<vector<char>> &M, int i, int j)
{
    vector<vector<bool>> vis(M.size(), vector<bool>(M[0].size(), false)); // vector de visitados para marcar donde he ido y donde no.
    // cola de un par(par(x,y), int) el primer elemento es la posicion en el mapa, el segundo es la distancia.
    queue<pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(i, j), 0)); // Inicializa la cola con la posición inicial y la distancia 0.
    int x, y;                              // Posiciones con las que recorrere el mapa.
    int d;                                 // Distancia a aumentar

    while (not q.empty())
    {
        // recopilar datos de los elementos de la cola.
        x = q.front().first.first;  // x vale i
        y = q.front().first.second; // y vale j
        d = q.front().second;       // d vale la distancia

        q.pop(); // borro el elemento

        if (M[x][y] == 't')
            return d; // si la casilla es un tesoro, retorna la distancia actual.
        else if (not vis[x][y])
        {
            vis[x][y] = true; // marco la posición como visitada

            // Recorrer casillas adyacentes
            for (auto &c : dirs)
            {
                int ni, nj;
                ni = x - c.first;
                nj = y - c.second; // ni y nj son las nuevas coordenadas a visitar.

                if (limitado(M, ni, nj) and M[ni][nj] != 'x')
                    q.push(make_pair(make_pair(ni, nj), d + 1));
            }
        }
    }
    return -1; // Si no hay tesoros accesibles, retorna -1.
}

int main()
{
    int n;
    int m;
    cin >> n >> m; // n filas y m columnas

    vector<vector<char>> M(n, vector<char>(m)); // Mapa de n filas y m columnas

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j]; // Leer el mapa

    int r, c;
    cin >> r >> c; // Leer la posición inicial (1-indexed)

    int distancia = bfs(M, r - 1, c - 1); // Llamar a la función bfs con la posición inicial (0-indexed)
    if (distancia == -1)
        cout << "No treasure can be reached";
    else
        cout << "Minimum distance: " << distancia << endl; // Imprimir la distancia mínima
}
