//============================================================================
// Name        : Problema3.cpp
// Author      : Andrés Cuéllar
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{

    stack<int> stackA;
    stack<int> stackB;
    stack<int> stackC;
    vector<int> vectorCTmp;

    stackA.push(2);
    stackA.push(18);
    stackA.push(26);
    stackA.push(42);
    stackA.push(126);

    stackB.push(18);
    stackB.push(27);
    stackB.push(35);

    int vA = 0;
    int vB = 0;
    bool lastA        = true;
    bool lastB        = true;

    // Mientras las pilas no esten vacias......
    while (!stackA.empty() || !stackB.empty())
    {
        // Si el ultimo valor leido traspasado fue de la pila A, leer nuevo valor de pila A
        if (lastA)
        {
            vA = stackA.top();
            stackA.pop();
        }
        // Si el ultimo valor leido traspasado fue de la pila B, leer nuevo valor de pila B
        if (lastB)
        {
            vB = stackB.top();
            stackB.pop();
        }
        // Comprueba el valor de que pila es mayor...
        if (vA >= vB)
        {
            // Si el mayor es el de la pila A...guardarlo en el vector temporal, poner true ultimo valor mayor en pila A
            vectorCTmp.push_back(vA);
            lastA = true;
            lastB = false;
        }
        else
        {
            // Si el mayor es el de la pila B...guardarlo en el vector temporal, poner true ultimo valor mayor en pila B
            vectorCTmp.push_back(vB);
            lastA = false;
            lastB = true;
        }
    }
    // Meter el ultimo valor que quedo suelto segun sea el que haya quedado de la pila A o de la pila B
    vectorCTmp.push_back(lastA ? vB : vA);
    //reverse(vectorCTmp.begin(),vectorCTmp());


    // Una vez dado la vuelta, lo metemos en la pila LIFO final
    for (int i = 0; i < vectorCTmp.size(); i++)
        stackC.push(vectorCTmp[i]);

    // Aqui vaciamos la pila para poder imprimirla por pantalla
    cout << "\nLa Pila combinada es:\n";

    while (!stackC.empty())
    {

        cout << stackC.top() << ", ";
        stackC.pop();

    }
    cout << std::endl;

    system("pause");
    return 0;
}
