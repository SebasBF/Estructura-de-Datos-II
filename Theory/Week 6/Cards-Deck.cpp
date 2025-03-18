#include <iostream>
using namespace std;

string PALOS[4] = {"Espadas", "Corazones", "Diamantes", "Tréboles"};
string VALORES[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

struct Carta
{
    string valor;
    string palo;
};

void createDeck(Carta baraja[])
{
    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            baraja[index++] = {VALORES[j], PALOS[i]};
        }
    }
}

void shuffleDeck(Carta baraja[])
{
    for (int i = 0; i < 52; i++)
    {
        int randomNumber = rand() % 52;

        Carta aux = baraja[i];
        baraja[i] = baraja[randomNumber];
        baraja[randomNumber] = aux;
    }
}

bool cardsFound(Carta baraja[], string valor1, string palo1, string valor2, string palo2, string valor3, string palo3){
    for(int i = 0; i < 50; i++){
        if (baraja[i].valor == valor1 && baraja[i].palo == palo1 && baraja[i+1].valor == valor2 && baraja[i+1].palo == palo2 && baraja[i+2].valor == valor3 && baraja[i+2].palo == palo3) {
            return true;
        }

        if (i < 49 && baraja[i].valor == "A" && baraja[i+1].valor == "A" && baraja[i+2].valor == "A" && baraja[i+3].valor == "A") {
            cout << "\nEL CASINO GANA.\n" << endl;
            return true;
        }
    }

    return false;
}

void showDeck(Carta baraja[], string valor1, string palo1, string valor2, string palo2, string valor3, string palo3) {
    for (int i = 0; i < 52; i++) {
        if ((baraja[i].valor == valor1 && baraja[i].palo == palo1) ||
            (baraja[i].valor == valor2 && baraja[i].palo == palo2) ||
            (baraja[i].valor == valor3 && baraja[i].palo == palo3)) {
            cout << "\033[1;31m" << baraja[i].valor << " de " << baraja[i].palo << "\033[0m" << endl;
        }
        else {
            cout << baraja[i].valor << " de " << baraja[i].palo << endl;
        }
    }
}

int main()
{
    srand(time(0));
    Carta baraja[52];
    bool validEntry = false;
    string palo1, palo2, palo3, valor1, valor2, valor3;
    int index = 0;
    createDeck(baraja);

    do{
        cout << "PALOS DISPONIBLES: \n 0 - Espadas\n 1 - Corazones\n 2 - Diamantes\n 3 - Treboles\n";
        cout << "\nPD: Hay valores de 2-10 y A, J, Q, K para cada palo" << endl;

        cout << "\nSeleccione el palo(0-3) a seleccionar para la carta #1:";
        cin >> palo1;
        cout << "\nSeleccione el valor a seleccionar para la carta #1:";
        cin >> valor1;
        cout << "\nSeleccione el palo(0-3) a seleccionar para la carta #2:";
        cin >> palo2;
        cout << "\nSeleccione el valor a seleccionar para la carta #2:";
        cin >> valor2;
        cout << "\nSeleccione el palo(0-3) a seleccionar para la carta #3:";
        cin >> palo3;
        cout << "\nSeleccione el valor a seleccionar para la carta #3:";
        cin >> valor3;

        if((valor1 == valor2 || valor1 == valor3 || valor2 == valor3) && (palo1 == palo2 || palo1 == palo3 || palo2 == palo3)){
            cout << "\n\nHay una carta repetida, intente de nuevo\n" << endl; 
            continue;
        }
        else{
            validEntry = true; 
          
        }

    }while(!validEntry);
    
    while(index < 1000000) {
        shuffleDeck(baraja);      
        index++;

        if(cardsFound(baraja, valor1, palo1, valor2, palo2, valor3, palo3)) {
            showDeck(baraja, valor1, palo1, valor2, palo2, valor3, palo3);
            cout << "\nNúmero de veces que se barajó el mazo: " << index << endl;
            break;
        }     
    }

    if(index == 1000000) {
        cout << "\nSE BARAJÓ 1 MILLÓN DE VECES Y NO SE CONSIGUIÓ LA COMBINACIÓN.";
    }

    return 0;    
}