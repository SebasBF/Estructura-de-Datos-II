#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


string vocalesAbiertas = "aeo";
string vocalesCerradas = "iu";


bool esLetra(char caracter) {
    return (caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z');
}

bool esVocal(char caracter) {
    caracter = tolower(caracter); 
    return (vocalesAbiertas.find(caracter) != string::npos || vocalesCerradas.find(caracter) != string::npos);
}


vector<string> separarPalabras(const string& frase) {
    vector<string> palabras;
    string palabraActual;
    for (char caracter : frase) {
        if (caracter == ' ') {
            if (!palabraActual.empty())
                palabras.push_back(palabraActual);
            palabraActual.clear();
        }
        else if (esLetra(caracter)) {
            palabraActual += caracter;
        }
    }
    if (!palabraActual.empty())
        palabras.push_back(palabraActual);
    return palabras;
}


int buscarSiguienteVocal(const string& palabra, int indiceActual) {
    for (int i = indiceActual + 1; i < palabra.size(); i++) {
        if (esVocal(palabra[i]))
            return i;
    }
    return -1; 
}


vector<string> dividirEnSilabas(const string& palabra) {
    vector<string> silabas;
    string silabaActual;

    for (int i = 0; i < palabra.size(); i++) {
        silabaActual += palabra[i];
        bool esAbierta = (vocalesAbiertas.find(tolower(palabra[i])) != string::npos);
        bool esCerrada = (vocalesCerradas.find(tolower(palabra[i])) != string::npos);

        if (esAbierta || esCerrada) {
            
            if (i == palabra.size() - 1) {
                silabas.push_back(silabaActual);
                return silabas;
            }

            
            if (esAbierta && (vocalesAbiertas.find(tolower(palabra[i + 1])) != string::npos)) {
                silabas.push_back(silabaActual);
                silabaActual.clear();
            }
            
            else if (esCerrada && (vocalesCerradas.find(tolower(palabra[i + 1])) != string::npos)) {
                if (tolower(palabra[i]) == tolower(palabra[i + 1])) {
                 
                    silabas.push_back(silabaActual);
                    silabaActual.clear();
                }
                else {
                   
                    silabaActual += palabra[++i];
                    silabas.push_back(silabaActual);
                    silabaActual.clear();
                }
            }
            
            else {
                int posicionSiguienteVocal = buscarSiguienteVocal(palabra, i);
                if (posicionSiguienteVocal == -1) {
                    
                    silabas.push_back(silabaActual + palabra.substr(i + 1));
                    return silabas;
                }

                int distancia = posicionSiguienteVocal - i - 1;

                switch (distancia) {
                case 1:
                 
                    silabas.push_back(silabaActual);
                    silabaActual.clear();
                    silabaActual += palabra[++i];
                    break;

                case 2:
                   
                    if (palabra[i + 2] == 'l' || palabra[i + 2] == 'r' || (palabra[i + 1] == 'c' && palabra[i + 2] == 'h')) {
                        silabas.push_back(silabaActual);
                        silabaActual.clear();
                        silabaActual += palabra[++i];
                        silabaActual += palabra[++i];
                    }
                    else {
                        silabaActual += palabra[++i];
                        silabas.push_back(silabaActual);
                        silabaActual.clear();
                        silabaActual += palabra[++i];
                    }
                    break;

                case 3:
                    // Tres consonantes → dividir antes de la última si no forman grupo inseparable
                    if (palabra[i + 3] == 'l' || palabra[i + 3] == 'r') {
                        silabaActual += palabra[++i];
                        silabas.push_back(silabaActual);
                        silabaActual.clear();
                        silabaActual += palabra[++i];
                        silabaActual += palabra[++i];
                    }
                    else {
                        silabaActual += palabra[++i];
                        silabaActual += palabra[++i];
                        silabas.push_back(silabaActual);
                        silabaActual.clear();
                        silabaActual += palabra[++i];
                    }
                    break;

                case 4:
                    // Cuatro consonantes → dividir en dos grupos
                    silabaActual += palabra[++i];
                    silabaActual += palabra[++i];
                    silabas.push_back(silabaActual);
                    silabaActual.clear();
                    silabaActual += palabra[++i];
                    silabaActual += palabra[++i];
                    break;

                default:
                    break;
                }
            }
        }
    }

    if (!silabaActual.empty())
        silabas.push_back(silabaActual);

    return silabas;
}
void imprimirSilabas(const vector<string>& silabas) {
    for (size_t i = 0; i < silabas.size() - 1; i++) {
        cout << silabas[i] << '-';
    }
    cout << silabas.back() << endl;
}

int main() {
    string fraseUsuario;
    cout << "Introduzca una frase: ";
    getline(cin, fraseUsuario);

   
    auto palabras = separarPalabras(fraseUsuario);

    
    for (auto& palabra : palabras) {
        imprimirSilabas(dividirEnSilabas(palabra));
    }

    return 0;
}