#include <iostream>
using namespace std;

int main(){
int option;

cout << "Seleccione una opcion:\n" << endl;
cout << "1 - Convertir de letra a ASCII." << endl;
cout << "2 - Convertir de ASCII a letra.\n" << endl;
cin >> option;

    switch(option){
        case 1: {     
            char letter;
            cout << "Indique la letra a convertir a ASCII: ";
            cin >> letter;
            
            int ASCIIvalue = letter;
            cout << "\n\nEl valor ASCII es: " << ASCIIvalue;
        }
        break;
    
        case 2: {
            int ASCIIvalue;     
            cout << "Indique el valor ASCII a convertir a letra: ";
            cin >> ASCIIvalue;

            char letter = char(ASCIIvalue);
            cout << "\n\nLa letra es: " << letter;
        }
        break;

        default:{
            cout << "Opcion inválida.";
        }
    }

}