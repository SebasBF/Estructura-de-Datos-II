#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


bool esVocal(char c) {
    c = tolower(static_cast<unsigned char>(c));
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


bool esDigrafoConsonantico(const string& token) {
    if (token == "ch" || token == "ll" || token == "rr") {
        return true;
    }
    return false;
}


vector<string> tokenizarConDigrafos(const string& palabra) {
    vector<string> tokens;
    size_t i = 0;
    while (i < palabra.size()) {
        char c = tolower(static_cast<unsigned char>(palabra[i]));

        if (i + 1 < palabra.size()) {
            char d = tolower(static_cast<unsigned char>(palabra[i + 1]));
            string posibleDigrafo;
            posibleDigrafo.push_back(c);
            posibleDigrafo.push_back(d);

            if (esDigrafoConsonantico(posibleDigrafo)) {
                tokens.push_back(palabra.substr(i, 2));
                i += 2;
                continue;
            }
        }
        tokens.push_back(palabra.substr(i, 1));
        i++;
    }
    return tokens;
}


bool tokenEsVocal(const string& token) {
    return (token.size() == 1 && esVocal(token[0]));
}


bool tokenEsConsonante(const string& token) {
    return !tokenEsVocal(token);
}


vector<string> separarEnSilabas(const string& palabra) {
    vector<string> tokens = tokenizarConDigrafos(palabra);
    vector<string> silabas;
    string silabaActual;

    for (size_t i = 0; i < tokens.size(); i++) {
        silabaActual += tokens[i];

        if (tokenEsVocal(tokens[i])) {
            size_t j = i + 1;
            int contadorConsonantes = 0;

            while (j < tokens.size() && tokenEsConsonante(tokens[j])) {
                contadorConsonantes++;
                j++;
            }

            if (contadorConsonantes == 1) {
                silabas.push_back(silabaActual);
                silabaActual.clear();
            }
            else if (contadorConsonantes >= 2) {
                silabas.push_back(silabaActual);
                silabaActual.clear();
            }
        }
    }

    if (!silabaActual.empty()) {
        silabas.push_back(silabaActual);
    }

    return silabas;
}

int main() {
    string linea;
    cout << "Ingrese una oracion ";
    getline(cin, linea);

    istringstream iss(linea);
    string palabra;
    bool primeraPalabra = true;

    while (iss >> palabra) {
        vector<string> silabas = separarEnSilabas(palabra);

        if (!primeraPalabra) {
            cout << " ";
        }

        for (size_t i = 0; i < silabas.size(); i++) {
            cout << silabas[i];
            if (i < silabas.size() - 1) {
                cout << "-";
            }
        }
        primeraPalabra = false;
    }

    cout << endl;

    return 0;
}
