#include <map>
#include <iostream>
using namespace std;

// Usando función insert
// Sintaxis: iterator map_name.insert(iterator_position, {key, value})

int main()
{
    map<int, double> empresa; // Este es un mapa vacío, esta empresa no tiene trabajadores.

    map<int, double>::iterator ite; // Declaro el iterador

    empresa.insert({3, 620});    // Inserto trabajador 1 con sueldo de 650.
    empresa.insert({2, 520.50}); // Inserto trabajador 2 con sueldo de 520.50.

    map<int, double>::iterator it = empresa.find(2);

    empresa.insert(it, {3, 620});

    ite = --empresa.end(); // Digo desde donde parte el iterador

    cout << ite->first << " " << ite->second << endl;
}