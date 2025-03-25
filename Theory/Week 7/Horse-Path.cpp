#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int movesX[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int movesY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

bool isValidMove(int x, int y, int N, vector<vector<int>> board) {
    if (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1){
        return true;
    }
    else{
        return false; 
    }
}

int countFutureMoves(int x, int y, int N, vector<vector<int>>& board) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int newX = x + movesX[i];
        int newY = y + movesY[i];
        if (isValidMove(newX, newY, N, board)) {
            count++;
        }
    }
    return count;
}

vector<pair<int, int>> findPath(vector<vector<int>>& board, int x, int y, int N) {
    vector<pair<int, int>> possibleMoves;

    for (int i = 0; i < 8; i++) {
        int newX = x + movesX[i];
        int newY = y + movesY[i];

        if (isValidMove(newX, newY, N, board)) {
            int futureMoves = countFutureMoves(newX, newY, N, board);
            possibleMoves.push_back({futureMoves, i});  
        }
    }

    sort(possibleMoves.begin(), possibleMoves.end());

    vector<pair<int, int>> orderedMoves;

    for (auto move : possibleMoves) {
        int i = move.second;
        orderedMoves.push_back({x + movesX[i], y + movesY[i]});
    }

    return orderedMoves; 
}

bool solve(vector<vector<int>>& board, int x, int y, int step, int N){
    if(step == N*N) return true;

    vector<pair<int, int>> moves = findPath(board, x, y, N);

    for (auto move : moves) {
        int newX = move.first;
        int newY = move.second;

        board[newX][newY] = step;  

        if (solve(board, newX, newY, step + 1, N)) {
            return true; 
        }

        board[newX][newY] = -1;  
    }

    return false;  
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell < 10 ? " " : "") << cell << " ";
        }
        cout << endl;
    }
}

int main(){
    int N, x, y;
    cout << "Indique el tamaño del tablero: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, -1));  
    
    cout << "Ingrese la posición inicial del caballo (x y): ";
    cin >> x >> y;


    if (x >= 0 && x < N && y >= 0 && y < N) { 
        board[x][y] = 0;

        if (solve(board, x, y, 1, N)) {
            cout << "\nSolución encontrada:\n" << endl;
            printBoard(board);
        } else {
            cout << "No hay solución para esta posición inicial.\n";
        }
    }
    else { 
        cout << "Coordenadas fuera del tablero.";
        return 1;
    }


}