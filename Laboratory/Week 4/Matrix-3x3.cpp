#include <iostream>
using namespace std;

int contador = 0; 

bool isSafe(int tablero[3][3], int num) {
    for(int y = 0 ; y < 3; y++){
    for (int x = 0; x < 3; x++) {
        if (tablero[y][x] == num){
            return false;
        }
    }}
    return true;
}


bool cumpleCondicion(int matrix[3][3]) {
    for (int i = 0; i < 3 ; i++) {
        if (matrix[i][0] + matrix[i][1] + matrix[i][2] != 15 ) return false;
        if (matrix[0][i] + matrix[1][i] + matrix[2][i] != 15) return false;
    }
    if (matrix[0][0] + matrix[1][1] + matrix[2][2] != 15 ) return false;
    if (matrix[0][2] + matrix[1][1] + matrix[2][0] != 15 ) return false;
   
    return true;
} 

void solve(int matrix[3][3], int row, int col) {
    if (row == 3)  //Una vez rellenamos todas las filas, revisamos si se cumple.
    {
        if (cumpleCondicion(matrix))
        {
            cout << "\nSolución encontrada después de " << contador << " iteraciones:\n";
            cout << endl;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << " " << matrix[i][j];
                    if (j < 2)
                        cout << " |";
                }
                cout << endl;
                if (i < 2)
                    cout << "---+---+---\n";
            }
            cout << endl;
        }
        return;
    }

    if (col == 3) //Luego de que rellenamos una fila, continuamos con la otra
    {
        solve(matrix, row + 1, 0);
        return;
    }

    for (int i = 1; i <= 9; i++){ //Caso base, inicia aqui
        contador++;  // Incrementamos el contador en cada intento
        if (isSafe(matrix, i))
        {
            matrix[row][col] = i;
            solve(matrix, row, col + 1);

            matrix[row][col] = 0;
        }
    }
}

int main(){

    int matrix[3][3] = {0};
    solve(matrix,0,0);
    return 0;
}