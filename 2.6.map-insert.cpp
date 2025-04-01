#include <map>
#include <iostream>
using namespace std;

// Usando función insert
// Sintaxis: iterator map_name.insert(iterator_position1, iterator_position2})

int main()
{
    map<int, double> empresa; // Este es nuestro mapa inicial

    map<int, double> oficina; // Este es nuestro mapa auxiliar

    map<int, double>::iterator ite; // Declaro el iterador

    empresa.insert({1, 650});
    empresa.insert({3, 620});

    oficina.insert({2, 520.50});
    oficina.insert({4, 575});

    cout << "Los trabajadores de oficina son: " << endl;

    for (auto it = oficina.begin(); it != oficina.end(); it++) // auto implica que C++ detecta automaticamente cual es el tipo de dato.
        cout << it->first << " " << it->second << endl;

    // Añadimos los trabajadores de Oficina a Empresa

    empresa.insert(oficina.begin(), oficina.end());

    cout << "Los trabajadores de empresa son: " << endl;

    for (auto it = empresa.begin(); it != empresa.end(); it++) // auto implica que C++ detecta automaticamente cual es el tipo de dato.
        cout << it->first << " " << it->second << endl;
}