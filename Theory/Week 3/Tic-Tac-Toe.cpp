#include <iostream>
using namespace std;

const int winningCombinations[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Filas
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columnas
    {0, 4, 8}, {2, 4, 6}             // Diagonales
};

void initializeArray(string array[]){
    for(int i = 0; i < 9; i++){
        array[i] = "~";
    }
}

void showArray(string array[]){
    for(int i = 0; i < 9; i++){
        cout << array[i] << (i == 2 || i == 5 ?  "\n" : " " );
    }
}

bool playPosition(int position, string array[], int player){
    if(array[position] == "~" && player == 1){
        array[position] = "X";
        return true;
    }
    else if(array[position] == "~" && player == 2){
        array[position] = "O";
        return true;
    }
    else{
        cout << "\nPosición inválida. Favor intentar de nuevo.\n\n";
        return false;
    }

    return false;
}

bool endGame(string array[], string player1, string player2){
    for (auto &combination : winningCombinations) {
        if (array[combination[0]] != "~" && array[combination[0]] == array[combination[1]] && array[combination[1]] == array[combination[2]]) {
            cout << "\n\nEl ganador es " << (array[combination[0]] == "X" ? player1 : player2) << endl;
            return true;
        }
    }   

    // Verificar si el juego sigue en curso
    for (int i = 0; i < 9; i++) {
        if (array[i] == "~") return false;
    }

    cout << "\n\nEl juego termina en empate" << endl;
    return true;
}

void gameLoop(string player1, string player2, string cells[]){
    int position;
    bool gameOver = false;

    while(!gameOver){

        do{
            cout << "\n\nTurno de " << player1 <<" - Inserte casilla a jugar (1 al 9): ";
            cin >> position;  
            cout << endl;            
        }while(!playPosition(position - 1,cells, 1));
        
        showArray(cells);
        if(endGame(cells, player1, player2)) break;

        do{
            cout << "\n\nTurno de " << player2 <<" - Inserte casilla a jugar (1 al 9): ";
            cin >> position;    
            cout << endl;                      
        }while(!playPosition(position - 1,cells, 2));

        showArray(cells);
        if(endGame(cells, player1, player2)) break;

    }
       
}

void startGame(){
    string cells[9], player1, player2;
    initializeArray(cells);
    
    cout << "Inserta nombre del jugador 1: ";
    cin >> player1;

    cout << "\nInserta nombre del jugador 2: ";
    cin >> player2;

    gameLoop(player1, player2, cells);
}

int main(){

    startGame();

    return 0;
}