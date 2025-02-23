#include <iostream>
using namespace std;

void initializeArray(string array[]){
    for(int i = 0; i < 9; i++){
        array[i] = "~";
    }
}

void showArray(string array[]){
    for(int i = 0; i < 9; i++){
        cout << array[i] << " ";
        if(i == 2 || i == 5){
            cout << endl;
        }
    }
}

void startGame(){
    string cells[9];
    initializeArray(cells);
    showArray(cells);

}


int main(){

    string player1, player2;
    startGame();

    cout << "Inserta nombre del jugador 1: ";
    cin >> player1;

    cout << "\nInserta nombre del jugador 2:";
    cin >> player2;



}