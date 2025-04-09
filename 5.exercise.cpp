// Ejercicio 1: Ordenación Personalizada
// Título: Ordenar por frecuencia de aparición

// Enunciado:
// Dado un arreglo de enteros, ordénalo de forma que los elementos con mayor frecuencia aparezcan primero.
// Si dos elementos tienen la misma frecuencia, el que apareció primero en el array original debe ir antes.

// Ejemplo de entrada:
// std::vector<int> arr = {4, 5, 6, 5, 4, 3};

// Ejemplo de salida:
// 4 4 5 5 6 3

// Restricciones:
// Usa una estructura de datos adecuada para contar las frecuencias.
// Implementa tu propia función de ordenamiento o usa std::sort con un comparador personalizado.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // Para usar sort
#include <utility>   // Para usar pair
using namespace std;

// 1) Primero pasamos los valores y sus frecuencias a un map.

map<int, int> orden1(vector<int> &v) // una función q toma como parametro un vector y que retorna como resultado un map
{
    map<int, int> aux; // Inicilizamos un map vacio
    for (int i = 0; i < v.size(); i++)
    {                // Iteramos sobre el vector inicial.
        aux[v[i]]++; // agregamos al map el valor de v[i].
    }
    return aux; // retornamos como produicto final el map con valores
}

// 2) Despues pasamos los elementos de vuelta al vector en orden segun su frecuencia usando map.count(key) para contar la frecuencia de cada elemento.

vector<int> orden2(map<int, int> &m) // una función q toma como parametro un map y retorna el vector ordenado
{
    vector<int> w; // inicializamos un vector vacio
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        int key = it->first;    // accedemos a la key del map
        int value = it->second; // accedemos al value del map
        for (int i = 0; i < value; i++)
            w.push_back(key); // agregamos la clave al vector tantas veces como su frecuencia
    }

    sort(w.begin(), w.end(), [](int a, int b)
         { return a < b; }); // ordenamos el vector usando una lambda function para definir el criterio de ordenamiento
    return w;                // retornamos el vector ordenado
}

int main()
{
    vector<int> ejemplo = {1, 5, 1, 3, 3, 6, 3, 5}; // declaro un vector cualquiera
    map<int, int> resultado = orden1(ejemplo);      // generamos el map el cual lleva implicita la funcion orden

    cout << "este es el map generado: " << endl;
    for (const pair<int, int> &p : resultado)
    {
        cout << "Valor: " << p.first << " Frecuencia: " << p.second << endl;
    }

    vector<int> vectorOrdenado = orden2(resultado); // generamos el vector ordenado usando la funcion orden2

    cout << "Este es el vector resultante: " << endl;
    for (int i = 0; i < vectorOrdenado.size(); i++)
    {
        cout << vectorOrdenado[i] << " "; // imprimo el vector ordenado
    }
    cout << endl;
}
