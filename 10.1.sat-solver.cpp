#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

// PROBLEMA: el programa anterior itera sobre cada literal suponiendo valores (1 o 0) para ver si se genera algun conflicto (alguna calusula falsa).
//  Lo anterior no es eficiente. Lo más eficiente sería priorizar revisando priemro aquellos literales que se repiten en varias clausulas.
//  En este archivo se propone una modificación al programa original aplicando la priorización mencionada.

// Estas 3 son macros para definir los valores de las variables en el modelo:
#define UNDEF -1
#define TRUE 1
#define FALSE 0

// unsigned indica que las variables no pueden ser negativas, sin signo.
unsigned int numVars;
unsigned int numClauses;
vector<vector<int>> clauses; // esto es un vector de vectores, es decir, una matriz.
vector<int> model;           // aca guardamos las interpretaciones de los símbolos (variables).
vector<int> modelStack;      // hace referencia a una pila. LIFO
unsigned int indexOfNextLitToPropagate;
unsigned int decisionLevel;

//-------------------------------------------------------- SOLUCIÓN----------------------------------------------------------------
vector<vector<int>> positiveLiterals;
vector<vector<int>> negativeLiterals;

vector<double> literalsOcurrence; // guardamos cuantas veces aparece un literal.

int conflicts;
int decs; // decisiones

const int TIME_TO_UPDATE = 1000;

// iNICIALIZAMOS VARIABLES
void inicio()
{
    decs = 0;
    conflicts = 0;

    positiveLiterals.resize(numVars + 1); //.resize() ajusta elñ tamaño del vector
    negativeLiterals.resize(numVars + 1);
    literalsOcurrence.resize(numVars + 1, 0.0); // sintaxis : .rezise("tamaño que asigno", "valor de los elementos")
}

// ACTUALIZAMOS LAS OCURRENCIAS DE UN LITERAL DADA UNA CLAUSULA CONCRETA
void updateLiteralsOcurrence(int clausula)
{
    vector<int> filaConcreta = clauses[clausula]; // Accedo a una clausula concreta (fila especifica de la matriz)
    int size = filaConcreta.size();

    for (int i = 0; i < size; i++)
    {
        int lit = filaConcreta[i]; // Accedo a un literal en concreto.

        if (lit < 0)
            lit = -lit;
        literalsOcurrence[lit] += 1.0;
    }
}
// DECREMENTARÁ UNA PROPORCION DE OCURRENCIAS PARA TODOS LOS LITERALES DE MI FORMULA
void itsTimeUpdateOcurrence()
{
    for (unsigned int i = 0; i < numVars; i++)
    {
        literalsOcurrence[i] /= 2.0;
    }
}

// HEURISTICA DE OCURRENCIA, ACTIVA LOS PROCEDIMIENTOS ENCARGADOS DE MANIPULAR LAS OCURRENCIAS DE LOS LITERALES
// AUMENTO LAS COURRENCIAS DE LOS LOTERALES EN UNA FILA INDICE, EN EL CASO DE QUE TENGA 1000 CONFLICTOS,
// DECREMENTARÉ LAS OCURRENCIAS ANTERIORMENTE
void ocurrenceHeuristic(int indice)
{
    if (conflicts % 1000 == 0)
    {
        itsTimeUpdateOcurrence(); // Decremento las ocurrencias de todos los literales
    }
    updateLiteralsOcurrence(indice); // incremento ocurrencias de los literales en la fila indice.
}
//------------------------------------------------------------------------------------------------------------------------------------

// Procedimiento que lee todas las cláusulas del problema SAT.
void readClauses()
{
    // Skip comments
    char c = cin.get();
    while (c == 'c')
    {
        while (c != '\n')
            c = cin.get();
        c = cin.get();
    }
    // Read "cnf numVars numClauses"
    string aux;
    cin >> aux >> numVars >> numClauses;
    clauses.resize(numClauses);

    inicio(); // Inicializamos las variables llamando al procedimiento inicio()
    // Read clauses, matrix
    for (int i = 0; i < numClauses; ++i)
    {
        int lit;
        while (cin >> lit and lit != 0)
            clauses[i].push_back(lit);
        if (lit > 0)
        {
            positiveLiterals[lit].push_back(i); // añado la fila i al vector positiveLiterals[lit]
            literalsOcurrence[lit] += 1.0;
        }
        else
        {
            negativeLiterals[-lit].push_back(i);
            literalsOcurrence[-lit] += 1.0;
        }
    }
}
// Función que define que hacer si el literal es negativo. Aun no se ha propagado.
int currentValueInModel(int lit)
{
    if (lit >= 0)
        return model[lit];
    else
    {
        if (model[-lit] == UNDEF)
            return UNDEF;
        else
            return 1 - model[-lit];
    }
}

// Procedimiento que vuelve la interpretación del literal a verdadero.
void setLiteralToTrue(int lit)
{
    modelStack.push_back(lit);
    if (lit > 0)
        model[lit] = TRUE;
    else
        model[-lit] = FALSE;
}

// RETORNA CIERTO SI ENCUENTRA UN CONFLICTO AL PROPAGAR
// RETORNA FALSO EN CASO DE QUENO ENCUENTRE NINGUN CONFLICTO
bool propagateGivesConflict()
{
    while (indexOfNextLitToPropagate < modelStack.size())
    {
        vector<int> *vec; // guarda las direcciones iniciales de memoria en un vector
        int lit = modelStack[indexOfNextLitToPropagate];
        // en caso que el literal sea negativo
        if (lit < 0)
            vec = &positiveLiterals[-lit];
        // en caso que el literal sea positivo
        else
            vec = &negativeLiterals[lit];

        ++indexOfNextLitToPropagate;
        for (unsigned int i = 0; i < vec->size(); ++i)
        {
            bool someLitTrue = false;
            int numUndefs = 0;
            int lastLitUndef = 0;

            int point = (*vec)[i]; // accedo a una fila concreta llamada point
            for (int k = 0; not someLitTrue and k < clauses[point].size(); ++k)
            {
                int val = currentValueInModel(clauses[point][k]);
                if (val == TRUE)
                    someLitTrue = true;
                else if (val == UNDEF)
                {
                    ++numUndefs;
                    lastLitUndef = clauses[point][k];
                }
            }
            if (not someLitTrue and numUndefs == 0)
                return true; // conflict! all lits false
            else if (not someLitTrue and numUndefs == 1)
                setLiteralToTrue(lastLitUndef);
        }
    }
    return false;
}

void backtrack()
{
    int i = modelStack.size() - 1;
    int lit = 0;
    while (modelStack[i] != 0)
    { // 0 is the DL mark
        lit = modelStack[i];
        model[abs(lit)] = UNDEF;
        modelStack.pop_back();
        --i;
    }
    // at this point, lit is the last decision
    modelStack.pop_back(); // remove the DL mark
    --decisionLevel;
    indexOfNextLitToPropagate = modelStack.size();
    setLiteralToTrue(-lit); // reverse last decision
}

// Heuristic for finding the next decision literal:
int getNextDecisionLiteral()
{
    for (int i = 1; i <= numVars; ++i) // stupid heuristic:
        if (model[i] == UNDEF)
            return i; // returns first UNDEF var, positively
    return 0;         // reurns 0 when all literals are defined
}
//-----------------------------------------------------------------------------------------------------------
// FUNCION QUE RETORNA EL LITERAL CON MAS OCURRENCIAS EN LA FORMULA
int getNextLiteralHeuristic()
{
    int maximo; // numero de ocurrencias del literal con mas ocurrencias
    maximo = 0;
    int pos_max; // literal con mas ocurrencias
    pos_max = 0;

    for (unsigned int i = 0; i <= numVars; i++)
    {
        if (model[i] == UNDEF)
        {
            if (literalsOcurrence[i] > maximo)
            {
                maximo = literalsOcurrence[i];
                pos_max = i;
            }
        }
    }
    ++decs; // Incremento el numero de decisiones
    return pos_max;
}

//----------------------------------------------------------------------------------------------------------
void checkmodel()
{
    for (int i = 0; i < numClauses; ++i)
    {
        bool someTrue = false;
        for (int j = 0; not someTrue and j < clauses[i].size(); ++j)
            someTrue = (currentValueInModel(clauses[i][j]) == TRUE);
        if (not someTrue)
        {
            cout << "Error in model, clause is not satisfied:";
            for (int j = 0; j < clauses[i].size(); ++j)
                cout << clauses[i][j] << " ";
            cout << endl;
            exit(1);
        }
    }
}

int main()
{
    readClauses(); // reads numVars, numClauses and clauses
    model.resize(numVars + 1, UNDEF);
    indexOfNextLitToPropagate = 0;
    decisionLevel = 0;

    // Take care of initial unit clauses, if any
    for (int i = 0; i < numClauses; ++i)
        if (clauses[i].size() == 1)
        {
            int lit = clauses[i][0];
            int val = currentValueInModel(lit);
            if (val == FALSE)
            {
                cout << "UNSATISFIABLE" << endl;
                return 10;
            }
            else if (val == UNDEF)
                setLiteralToTrue(lit);
        }

    // DPLL algorithm
    while (true)
    {
        while (propagateGivesConflict())
        {
            if (decisionLevel == 0)
            {
                cout << "UNSATISFIABLE" << endl;
                return 10;
            }
            backtrack();
        }
        int decisionLit = getNextLiteralHeuristic();
        if (decisionLit == 0)
        {
            checkmodel();
            cout << "SATISFIABLE" << endl;
            return 20;
        }
        // start new decision level:
        modelStack.push_back(0); // push mark indicating new DL
        ++indexOfNextLitToPropagate;
        ++decisionLevel;
        setLiteralToTrue(decisionLit); // now push decisionLit on top of the mark
    }
}
