#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Move {
    int row;
    int col;
};

void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(const char tablero[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}

bool verVictoria(const char tablero[3][3], char caracter) {
    // Filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == caracter && tablero[i][1] == caracter && tablero[i][2] == caracter) {
            return true;
        }
    }
    // Columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == caracter && tablero[1][j] == caracter && tablero[2][j] == caracter) {
            return true;
        }
    }
    // Diagonales
    if (tablero[0][0] == caracter && tablero[1][1] == caracter && tablero[2][2] == caracter) {
        return true;
    }
    if (tablero[0][2] == caracter && tablero[1][1] == caracter && tablero[2][0] == caracter) {
        return true;
    }
    return false;
}

bool verEmpate(const char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void copiarTablero(char destino[3][3], const char origen[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

int minimax(char tablero[3][3], int depth, bool isMaximizing, int alpha, int beta, char aiSymbol, char humanSymbol) {
    if (verVictoria(tablero, aiSymbol)) return 10 - depth;
    if (verVictoria(tablero, humanSymbol)) return depth - 10;
    if (verEmpate(tablero)) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    char copiaTablero[3][3];
                    copiarTablero(copiaTablero, tablero);
                    copiaTablero[i][j] = aiSymbol;
                    int score = minimax(copiaTablero, depth + 1, false, alpha, beta, aiSymbol, humanSymbol);
                    bestScore = max(bestScore, score);
                    alpha = max(alpha, bestScore);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    char copiaTablero[3][3];
                    copiarTablero(copiaTablero, tablero);
                    copiaTablero[i][j] = humanSymbol;
                    int score = minimax(copiaTablero, depth + 1, true, alpha, beta, aiSymbol, humanSymbol);
                    bestScore = min(bestScore, score);
                    beta = min(beta, bestScore);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    }
}

Move findBestMove(char tablero[3][3], char aiSymbol) {
    int bestScore = numeric_limits<int>::min();
    Move bestMove = {-1, -1};
    char humanSymbol = (aiSymbol == 'X') ? 'O' : 'X';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                char copiaTablero[3][3];
                copiarTablero(copiaTablero, tablero);
                copiaTablero[i][j] = aiSymbol;
                int score = minimax(copiaTablero, 0, false, numeric_limits<int>::min(), numeric_limits<int>::max(), aiSymbol, humanSymbol);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }
    return bestMove;
}

int getValidNumber(string mensaje) {
    int number;
    bool validEntry;
    do {
        validEntry = true;
        cout << mensaje;
        cin >> number;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "\nEntrada invalida. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validEntry = false;
        }
        if (number < 1 || number > 3) {
            cout << "\nNumero fuera de rango. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";
            validEntry = false;
        }
    } while (!validEntry);
    return number;
}

int main() {
    string jugador1, jugador2;
    char eleccion;
    bool turnoJugador1 = true;
    
    char tablero[3][3];
    inicializarTablero(tablero);

    cout << "¿Desea jugar primero? (s/n): ";
    cin >> eleccion;
    cin.ignore(256, '\n');

    if (toupper(eleccion) == 'S') {
        cout << "Ingrese su nombre (usara 'X'): ";
        getline(cin, jugador1);
        jugador2 = "AI";
        mostrarTablero(tablero);
        
    } else {
        jugador1 = "AI";
        cout << "Ingrese su nombre (usara 'O'): ";
        getline(cin, jugador2);
        
    }

    bool finDelJuego = false;

    while (!finDelJuego) {
        
        
        char simbolo;
        string jugadoractual;
        
        if (turnoJugador1) {
            simbolo = 'X';
            jugadoractual = jugador1;
        } else {
            simbolo = 'O';
            jugadoractual = jugador2;
        }
        

        if (jugadoractual == "AI") {
            Move bestMove = findBestMove(tablero, simbolo);
            int fila = bestMove.row;
            int columna = bestMove.col;
            cout << jugadoractual << " elige fila " << fila + 1 << " y columna " << columna + 1 << endl;
            tablero[fila][columna] = simbolo;
        } else {
            int fila, columna;
            do {
                fila = getValidNumber(jugadoractual + " ingrese la fila (1-3): ");
                columna = getValidNumber(jugadoractual + " ingrese la columna (1-3): ");
                fila--;
                columna--;

                if (tablero[fila][columna] != ' ') {
                    cout << "Posición ocupada. Intente de nuevo.\n";
                }
            } while (tablero[fila][columna] != ' ');

            tablero[fila][columna] = simbolo;
        }

        if (verVictoria(tablero, simbolo)) {
            mostrarTablero(tablero);
            cout << "¡" << jugadoractual << " ha ganado!\n";
            finDelJuego = true;
        } else if (verEmpate(tablero)) {
            mostrarTablero(tablero);
            cout << "¡Empate!\n";
            finDelJuego = true;
        } else {
            turnoJugador1 = !turnoJugador1;
            mostrarTablero(tablero);
        }
        
    }
    return 0;
}