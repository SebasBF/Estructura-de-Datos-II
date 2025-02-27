#include <iostream>
#include <string>
using namespace std;

void inicializarTablero(char tablero[3][3]){
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
    
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == caracter && 
            tablero[i][1] == caracter && 
            tablero[i][2] == caracter) {
            return true;
        }
    }
   
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == caracter && 
            tablero[1][j] == caracter && 
            tablero[2][j] == caracter) {
            return true;
        }
    }
    
    if (tablero[0][0] == caracter && 
        tablero[1][1] == caracter && 
        tablero[2][2] == caracter) {
        return true;
    }
    if (tablero[0][2] == caracter && 
        tablero[1][1] == caracter && 
        tablero[2][0] == caracter) {
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

int getValidNumber(string mensaje) {
    int number;
    bool validEntry;
   
    do{
        validEntry = true;

        cout << mensaje;
        cin >> number;

        if(cin.fail() || cin.peek() != '\n'){
            cout << "\nEntrada invalida. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";

            cin.clear();
            cin.ignore(256, '\n');
            validEntry = false;
        }
        if(number < 1 || number > 3) {
            cout << "\nNumero fuera de rango. Favor intentar de nuevo.\n";
            cout << "------------------------------------------------\n\n";

            validEntry = false;
        }

    }while(!validEntry);

    return number;
}


int main() {
    string jugador1, jugador2;
    cout << "Ingrese el nombre del jugador 1 (usara 'X'): ";
    getline(cin, jugador1);
    cout << "Ingrese el nombre del jugador 2 (usara 'O'): ";
    getline(cin, jugador2);

    char tablero[3][3];
    inicializarTablero(tablero);
   
    bool turnoJugador1 = true;
    bool finDelJuego = false;

    while (!finDelJuego) {
        mostrarTablero(tablero);
        char simbolo = turnoJugador1 ? 'X' : 'O';
        string jugadoractual = turnoJugador1 ? jugador1 : jugador2;

        int fila = getValidNumber(jugadoractual + " ingrese la fila (1-3): ");
        int columna = getValidNumber(jugadoractual + " ingrese la columna (1-3): ");

        fila -= 1;
        columna -= 1;

        if (tablero[fila][columna] == ' '){
            
            tablero[fila][columna] = simbolo;

            if (verVictoria(tablero, simbolo)) {
                mostrarTablero(tablero);
                cout << "¡" << jugadoractual << " ha ganado!\n";
                finDelJuego = true;
            }
            else if(verEmpate(tablero)) {
                mostrarTablero(tablero);
                cout << "¡Empate!\n";
                finDelJuego = true;
            } 
            else {
               
                turnoJugador1 = !turnoJugador1;
            }
        } 
        else{
            cout << "Posición ocupada. Intente de nuevo.\n";
        }
    }

    return 0;
}