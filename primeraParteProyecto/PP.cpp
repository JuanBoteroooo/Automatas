#include <iostream>
#include <string>
#include <regex>

// Funciones de validación
bool esDigito(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[0-9]"));
}

bool esLetra(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[a-zA-Z]"));
}

bool esPalabra(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[a-zA-Z]+"));
}

bool esNumeroEntero(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[0-9]+"));
}

bool esNumeroReal(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[0-9]+\\.[0-9]+"));
}

bool esIdentificador(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("[a-zA-Z]([a-zA-Z0-9]*)"));
}

bool esOperador(const std::string &cadena)
{
    return std::regex_match(cadena, std::regex("=|\\+|\\-|\\*|\\/|%"));
}

void validarCadena(const std::string &cadena)
{
    std::cout << "\n--- Resultado de la validación ---\n";

    if (esDigito(cadena))
    {
        std::cout << "Tipo: Digito\n";
    }
    else if (esLetra(cadena))
    {
        std::cout << "Tipo: Letra\n";
    }
    else if (esPalabra(cadena))
    {
        std::cout << "Tipo: Palabra\n";
    }
    else if (esNumeroEntero(cadena))
    {
        std::cout << "Tipo: Numero Entero\n";
    }
    else if (esNumeroReal(cadena))
    {
        std::cout << "Tipo: Numero Real\n";
    }
    else if (esIdentificador(cadena))
    {
        std::cout << "Tipo: Identificador\n";
    }
    else if (esOperador(cadena))
    {
        std::cout << "Tipo: Operador\n";
    }
    else
    {
        std::cout << "Error: La cadena no corresponde a ninguna expresion regular.\n";
    }

    std::cout << "-----------------------------------\n";
}

int main()
{
    std::string cadena;
    char opcion;

    std::cout << "===========================================\n";
    std::cout << "       Programa de Validación de Cadenas   \n";
    std::cout << "===========================================\n";

    do
    {
        std::cout << "\nPor favor, ingrese una cadena para validar:\n";
        std::cout << ">> ";
        std::getline(std::cin, cadena);

        validarCadena(cadena);

        std::cout << "\n¿Desea validar otra cadena? (si/no): ";
        std::cin >> opcion;
        std::cin.ignore();
    } while (opcion == 'si' || opcion == 'no');

    std::cout << "\n===========================================\n";
    std::cout << "         Gracias por usar el programa       \n";
    std::cout << "===========================================\n";

    return 0;
}