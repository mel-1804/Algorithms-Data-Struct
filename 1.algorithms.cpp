#include <iostream>
using namespace std;

// EJEMPLOS DE DISTINTOS ALGORITMOS Y SU COSTE:
// NOTA: usaremos la notación ϴ, ya que en estos casos, usando como referencia algebraicca la cantidad de veces que se repite el coste, tendremos tasas de creciemiento exactas.

int main()
{
    int n;

    // FRAGMENTO 1: El coste es lineal, crece en tasa "n". Se dice que el coste es ϴ(n).
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s++;
    }

    // FRAGMENTO 2: El coste es lineal, crece en tasa "n/2". El bucle se realiza la mitad de las veces. Pero para estos efectos que haya una constante 1/2 multiplicando a la n no es relevante.
    // Lo que importa es la tasa de crecimiento, es decir la razon de crecimiento, la cual en este caso es lineal, independiente de la pendiente que tenga la recta representada.
    // Se dice que el coste es ϴ(n).
    int s = 0;
    for (int i = 0; i < n; i += 2)
    {
        s++;
    }

    // FRAGMENTO 3: El coste es lineal, crece en tasa "2". El bucle se realiza 2 veces. Pero para estos efectos que haya una constante 2 multiplicando a la n no es relevante.
    // Lo que importa es la tasa de crecimiento, es decir la razon de crecimiento, la cual en este caso es lineal, independiente de la pendiente que tenga la recta representada.
    // Se dice que el coste es ϴ(n).
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s++;
    }
    for (int j = 0; j < n; j++)
    {
        s++;
    }

    // FRAGMENTO 4: El coste es cuadrático, crece en tasa "n*n". Se trata de un bucle anidado, por eso la exponencial. Se dice que el coste es ϴ(n^2).
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s++;
        }
    }

    // FRAGMENTO 5: El segundo bucle se ejecuta en funcion de i, es decir, cada vez hay mas iteraciones.
    // En la 1ra iteracion, el bucle externo se ejecuta 1 vez, bucle interno no se ejecuta (j < 0)
    // En la 2da iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta 1 vez (j < 1)
    // En la 3ra iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta 2 veces (j < 2)
    // En la 4ta iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta 3 veces (j < 3)
    // En la (n) iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta (n-1) veces (j < n)
    // es una progresión aritmetica que se conoce como SUMA DE GAUSS, definida como: (n(n-1)) / 2
    // La notación asintótica para esta expresión seria ϴ(n(n-1))/2) o bien ϴ((n^2 - n)/2)
    // Cuando se tienen expresiones cuadratica (n^2), lineal (n) y constante (2) en una misma fórmula, se queda con el coste mayor, que sería el cuadrático.
    // Por lo tanto el coste seria ϴ(n^2).
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s++;
        }
    }

    // FRAGMENTO 6: El bucle interno se ejecuta a partir de la i.
    // Es similar al bucle nro 5, pero al revés, tengo menos iteraciones en el bucle interno porque le quito opciones desde el inicio (el naterior restaba opciones al final)
    // En la 1ra iteracion, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta n veces, todas las veces (j partiendo de i = 0)
    // En la 2da iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta n -1 veces (j partiendo desde 1)
    // En la 3ra iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta n -2 veces (j partiendo desde 2)
    // En la 4ta iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta n -3 veces (j partiendo desde 3)
    // En la (n-1) iteración, el bucle externo se ejecuta 1 vez, bucle interno se ejecuta 1 vez (j = n - 1 = 1)
    // La respuesta es la misma que el ejercicio anterior:
    // Por lo tanto el coste seria ϴ(n^2).
    int s = 0;
    // La notación asintótica para esta expresión seria ϴ(n(n-1))/2) o bien ϴ((n^2 - n)/2)
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s++;
        }
    }
}