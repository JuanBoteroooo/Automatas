#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void q1(string, int &);
void q2(string, int &);
void q3(string, int &);
void q4(string, int &);
void q5(string, int &);

void q0(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'V':
            i++;
            q1(line, i);
            break;
        case 'B':
            i++;
            q2(line, i);
            break;
        default:
            cout << "Cadena no válida en q0 con carácter: " << line[i] << endl;
            break;
        }
    }
}

void q1(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'A':
            i++;
            q2(line, i);
            break;
        case 'B':
            i++;
            q4(line, i);
            break;
        default:
            cout << "Cadena no válida en q1 con carácter: " << line[i] << endl;
            break;
        }
    }
}

void q2(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'O':
            i++;
            q1(line, i);
            break;
        case 'V':
            i++;
            q3(line, i);
            break;
        default:
            cout << "Cadena no válida en q2 con carácter: " << line[i] << endl;
            break;
        }
    }
}

void q3(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'I':
            i++;
            q3(line, i);
            break;
        case 'T':
            i++;
            q5(line, i);
            break;
        default:
            cout << "Cadena no válida en q3 con carácter inesperado: " << line[i] << endl;
            break;
        }
    }
    else
    {
        cout << "Cadena termina inesperadamente en q3" << endl;
    }
}

void q4(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'I':
            i++;
            q3(line, i);
            break;
        default:
            cout << "Cadena válida termina en q4" << endl;
            break;
        }
    }
    else
    {
        cout << "Cadena válida termina en q4" << endl;
    }
}

void q5(string line, int &i)
{
    if (i < line.length())
    {
        switch (line[i])
        {
        case 'I':
            i++;
            q4(line, i);
            break;
        default:
            cout << "Cadena válida termina en q5" << endl;
            break;
        }
    }
    else
    {
        cout << "Cadena válida termina en q5" << endl;
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
    while (getline(inputFile, line))
    {
        int index = 0;
        cout << "Procesando: " << line << endl;
        q0(line, index);
    }

    inputFile.close();
    return 0;
}
