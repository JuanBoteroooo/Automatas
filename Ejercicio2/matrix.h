const int NUMSTATES = 7; // Estados del 0 al 6
const int NUMCAR = 4;    // Caracteres: 'A', 'B', 'C', 'D'
int matrix[NUMSTATES][NUMCAR] = {
    {0, 1, 2, -1},   // Estado 0: 'A'->0, 'B'->1, 'C'->2
    {-1, 1, 2, -1},  // Estado 1: 'B'->1, 'C'->2
    {3, -1, -1, -1}, // Estado 2: 'A'->3 (después de 'C')
    {-1, 4, -1, -1}, // Estado 3: 'B'->4 (después de 'A')
    {-1, -1, 5, -1}, // Estado 4: 'C'->5 (después de 'B')
    {-1, -1, -1, 6}, // Estado 5: 'D'->6 (después de 'C')
    {-1, -1, -1, -1} // Estado 6: Estado de aceptación, no hay salidas
};
