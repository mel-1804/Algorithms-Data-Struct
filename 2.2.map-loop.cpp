#include <map>
#include <iostream>
using namespace std;

// Recorriendo un map con bucle FOR

int main()
{

    map<string, int> alumnoNota;

    alumnoNota["Santiago"] = 8;
    alumnoNota["Ana"] = 4;
    alumnoNota["Carlos"] = 9;
    alumnoNota["Ulises"] = 5;
    alumnoNota["Adan"] = 10;
    alumnoNota["Richard"] = 6;

    // BUCLE FOR DESDE EL INICIO:

    for (map<string, int>::iterator it = alumnoNota.begin(); it != alumnoNota.end(); it++)
    {
        cout << "El alumno " << it->first << " ha sacado una nota: " << it->second << endl;
    }

    // BUCLE FOR DESDE EL FINAL:

    // for (map<string, int>::iterator it = --alumnoNota.end(); it != --alumnoNota.begin(); it--)
    // {
    //     cout << "El alumno " << it->first << " ha sacado una nota: " << it->second << endl;
    // }
}