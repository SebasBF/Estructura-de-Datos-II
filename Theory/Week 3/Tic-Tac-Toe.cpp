#include <iostream>
using namespace std;

void initializeArray(string array[]){
    for(int i = 0; i < 10; i++){
        array[i] = "~";
    }
}


void startGame(){
    string cells[10];
    initializeArray(cells);
}


int main(){

    string player1, player2;

    cout << "Inserta nombre del jugador 1: ";
    cin >> player1;

    cout << "\nInserta nombre del jugador 2:";
    cin >> player2;


}