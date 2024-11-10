const int NUMSTATES = 4; // Cuatro estados: 0, 1, 2, y 3
const int NUMCAR = 5;    // Caracteres: 'P', 'L', 'A', 'Z', 'O'
int matrix[NUMSTATES][NUMCAR] = {
    {1, 1, -1, -1, -1},  // Estado 0: 'P' y 'L' llevan al Estado 1
    {1, 1, 2, -1, -1},   // Estado 1: 'A' se queda en 1, 'Z' lleva al Estado 2
    {-1, -1, 0, 3, 2},   // Estado 2: 'A' regresa al Estado 0, 'Z' lleva al Estado 3, 'O' se queda en 2
    {-1, -1, -1, -1, -1} // Estado 3: Estado de aceptación, no hay salidas
};
