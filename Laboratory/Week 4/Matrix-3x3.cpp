#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <algorithm> // Para shuffle()

using namespace std;

const int winningCombinations[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Filas
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columnas
    {0, 4, 8}, {2, 4, 6}             // Diagonales
};

bool isSafe(const int tablero[3][3], int row, int col, int num) {
    for (int i = 0; i < 3; i++) {
        if (tablero[row][i] == num + tablero[i][col] == num) {
            return false;
        }
    }
    return true;
}
// Función para inicializar la matriz con números únicos del 1 al 9
void checkRow(int matrix[3][3], int first, int second, int third) {
    for(int i = 1; i < 3; i++){
        if(first + second + third != 15){
            return checkRow()
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(const int tablero[3][3], char caracter) {
   
}
int main() {
    int matrix[3][3];

    // Inicializar y mostrar la matriz
    inicializarMatriz(matrix);
    imprimirMatriz(matrix);

    return 0;
}
