#include <map>
#include <iostream>
using namespace std;

// Recorriendo un map con bucle WHILE

int main()
{

    map<string, int> alumnoNota;

    alumnoNota["Santiago"] = 8;
    alumnoNota["Ana"] = 4;
    alumnoNota["Carlos"] = 9;
    alumnoNota["Ulises"] = 5;
    alumnoNota["Adan"] = 10;
    alumnoNota["Richard"] = 6;

    // BUCLE WHILE DESDE EL INICIO:

    // map<string, int>::iterator it = alumnoNota.begin();

    // while (it != alumnoNota.end())
    // {
    //     cout << "El alumno " << it->first << " ha sacado una nota: " << it->second << endl;
    //     it++;
    // }

    // BUCLE WHILE DESDE EL FINAL:

    map<string, int>::iterator it = --alumnoNota.end();

    while (it != --alumnoNota.begin())
    {
        cout << "El alumno " << it->first << " ha sacado una nota: " << it->second << endl;
        it--;
    }
}