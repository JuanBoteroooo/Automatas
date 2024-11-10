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
    case 'P':
        return 0;
    case 'L':
        return 1;
    case 'A':
        return 2;
    case 'Z':
        return 3;
    case 'O':
        return 4;
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
            if (state == 3)
            {          // Check if the state is the acceptance state
                break; // Stop processing further characters
            }
        }

        if (valid && state == 3)
        {
            validLines.push_back(line);
        }
        else
        {
            invalidLines.push_back(line);
        }
    }

    // Printing valid and invalid lines
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
