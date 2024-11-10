#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "./matrix.h"

using namespace std;

int charToIndex(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    default:
        return -1; // Carácter no válido
    }
}

int main()
{
    ifstream inputFile("text.txt");
    if (!inputFile.is_open())
    {
        cout << "No se encontró el archivo." << endl;
        return 1;
    }

    string line;
    vector<string> validLines;
    vector<string> invalidLines;

    while (getline(inputFile, line))
    {
        int state = 0;
        bool valid = true;

        for (char c : line)
        {
            int index = charToIndex(c);
            if (index == -1 || matrix[state][index] == -1)
            {
                valid = false;
                break;
            }
            state = matrix[state][index];
            if (state == 6)
            {          // Verificar si es el estado de aceptación
                break; // Finalizar el procesamiento de caracteres
            }
        }

        if (valid && state == 6)
        {
            validLines.push_back(line);
        }
        else
        {
            invalidLines.push_back(line);
        }
    }

    cout << "Válidas: ";
    for (const string &vline : validLines)
    {
        cout << vline << " ";
    }
    cout << endl;

    cout << "No válidas: ";
    for (const string &ivline : invalidLines)
    {
        cout << ivline << " ";
    }
    cout << endl;

    return 0;
}
