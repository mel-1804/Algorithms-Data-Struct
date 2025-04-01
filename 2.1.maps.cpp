#include <map>
#include <iostream>
using namespace std;

// Misma dinamica del archivo anterior, pero un map de tipo map<string, int>

int main()
{

    // Un Alumno tendra como identificador key = nombre (string)
    // Un Alumno tendra como value = nota (int)

    map<string, int> alumnoNota;

    alumnoNota["Santiago"] = 8;
    alumnoNota["Ana"] = 4;
    alumnoNota["Carlos"] = 9;
    alumnoNota["Ulises"] = 5;
    alumnoNota["Adan"] = 10;

    // Vamos a acceder al primer elemneto del mapa, usando .begin() y al último elemento usando .end()
    // Respecto al uso de .end(), es importante saber que debe declararse en la variable a usar, en este caso la variable it, con un decremento.
    // it = --alumnoNota.end();
    // Se anota asi, porque este puntero en realidad esta apuntando al elemento que viene despues del final. Al decrementarlo se retrocede una posición y apuntamos al verdadero elemento final.

    // alumnoNot.begin(); retorna un iterador (un puntero) al primer elemento.
    // alumnoNot.end(); retorna un puntero ficticio al elemento que va despues del último.

    map<string, int>::iterator it; // tengo un iterador que apunta a map<int, int>

    it = alumnoNota.begin();
    // it = --alumnoNota.end();

    // it->first;    accedo a la key del map
    // it->second;  accedo al value del map

    cout << " La nota del alumno " << it->first << " es: " << it->second << endl;
}