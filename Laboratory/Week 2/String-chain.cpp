#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool yaContado(char z, string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == z) {
            return true;
        }
    }
    return false;
}

void contarchar(string prompt, char letter, int length, string& letterStorage) {
    int f = 0;
   
    if (letter == ' ') {
        return;
    }

    if (yaContado(letter, letterStorage)) {
        return;
    }

    letterStorage += letter;

    for (int j = 0; j < length; j++) {
        
        if (prompt[j] == letter) {
            f++;
        }
    }

    cout << letter << ": " << f << endl;
}

int main() {
    cout << "Ingrese una cadena: ";
    string prompt;
    getline(cin, prompt);
    for (int i = 0; i < prompt.length(); i++) {
        prompt[i] = tolower(prompt[i]);
    }

    int length = prompt.length();
    string letterStorage = "";

    for (int i = 0; i < length; i++) {
       contarchar(prompt, prompt[i], length, letterStorage);
    }

    return 0;
}