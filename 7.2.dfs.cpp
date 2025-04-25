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
